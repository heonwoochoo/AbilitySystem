// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AnimNotify_Step.h"
#include "AbilitySystemCharacter.h"
#include "ActorComponents/FootstepComponent.h"

void UAnimNotify_Step::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (MeshComp)
	{
		AAbilitySystemCharacter* Character = Cast<AAbilitySystemCharacter>(MeshComp->GetOwner());
		if (Character)
		{
			UFootstepComponent* FootstepComponent = Character->GetFootstepComponent();
			if (FootstepComponent)
			{
				FootstepComponent->HandleFootstep(Foot);
			}
		}
	}
}
