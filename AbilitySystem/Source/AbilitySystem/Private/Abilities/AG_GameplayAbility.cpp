// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/AG_GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemCharacter.h"

void UAG_GameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UAbilitySystemComponent* AbilitySystemComponent = ActorInfo->AbilitySystemComponent.Get())
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();

		for (auto GameplayEffect : OngoingEffectsToJustApplyOnStart)
		{
			if (!GameplayEffect.Get()) continue;

			FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, 1, EffectContext);
			if (SpecHandle.IsValid())
			{
				FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
				if (!ActiveGEHandle.WasSuccessfullyApplied())
				{
					UE_LOG(LogTemp, Warning, TEXT("Ability %s failed to apply startup effect %s"), *GetName(), *GetNameSafe(GameplayEffect));
				}
			}
		}

		if (IsInstantiated())
		{
			for (auto GameplayEffect : OngoingEffectsToRemoveOnEnd)
			{
				if (!GameplayEffect.Get()) continue;

				FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, 1, EffectContext);
				if (SpecHandle.IsValid())
				{
					FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
					if (!ActiveGEHandle.WasSuccessfullyApplied())
					{
						UE_LOG(LogTemp, Warning, TEXT("Ability %s failed to apply runtime effect %s"), *GetName(), *GetNameSafe(GameplayEffect));
					}
					else
					{
						RemoveOnEndEffectHandles.Add(ActiveGEHandle);
					}
				}
			}
		}
	}
}

void UAG_GameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	if (IsInstantiated())
	{
		UAbilitySystemComponent* AbilitySystemComponent = ActorInfo->AbilitySystemComponent.Get();
		for (auto ActiveEffectHandle : RemoveOnEndEffectHandles)
		{
			if (ActiveEffectHandle.IsValid())
			{
				AbilitySystemComponent->RemoveActiveGameplayEffect(ActiveEffectHandle);
			}
		}
		RemoveOnEndEffectHandles.Empty();
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

AAbilitySystemCharacter* UAG_GameplayAbility::GetCharacterFromActorInfo() const
{
	return Cast<AAbilitySystemCharacter>(GetAvatarActorFromActorInfo());
}
