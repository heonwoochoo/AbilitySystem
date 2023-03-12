// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemCharacter.h"
#include "GameTypes.h"
#include "Data/CharacterAnimDataAsset.h"
#include "AnimInstances/AG_AnimInstance.h"

UBlendSpace* UAG_AnimInstance::GetLocomotionBlendSpace() const
{
	AAbilitySystemCharacter* Character = Cast<AAbilitySystemCharacter>(GetOwningActor());
	if (Character)
	{
		FCharacterData Data = Character->GetCharacterData();
		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace;
		}
	}
	else if (DefaultCharacterAnimDataAsset)
	{
		return DefaultCharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace;
	}
	return nullptr;
}

UAnimSequence* UAG_AnimInstance::GetIdleAnimation() const
{
	AAbilitySystemCharacter* Character = Cast<AAbilitySystemCharacter>(GetOwningActor());
	if (Character)
	{
		FCharacterData Data = Character->GetCharacterData();
		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
		}
	}
	else if (DefaultCharacterAnimDataAsset)
	{
		return DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
	}
	return nullptr;
}
