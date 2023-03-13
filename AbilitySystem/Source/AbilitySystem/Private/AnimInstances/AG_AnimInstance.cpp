// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemCharacter.h"
#include "GameTypes.h"
#include "Data/CharacterAnimDataAsset.h"
#include "AnimInstances/AG_AnimInstance.h"

void UAG_AnimInstance::NativeInitializeAnimation()
{
	Character = Cast<AAbilitySystemCharacter>(GetOwningActor());
}

UBlendSpace* UAG_AnimInstance::GetLocomotionBlendSpace() const
{
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

UBlendSpace* UAG_AnimInstance::GetCrouchLocomotionBlendSpace() const
{
	if (Character)
	{
		FCharacterData Data = Character->GetCharacterData();
		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.CrouchMovementBlendspace;
		}
	}
	else if (DefaultCharacterAnimDataAsset)
	{
		return DefaultCharacterAnimDataAsset->CharacterAnimationData.CrouchMovementBlendspace;
	}
	return nullptr;
}

UAnimSequence* UAG_AnimInstance::GetCrouchIdleAnimation() const
{
	if (Character)
	{
		FCharacterData Data = Character->GetCharacterData();
		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.CrouchIdleAnimationAsset;
		}
	}
	else if (DefaultCharacterAnimDataAsset)
	{
		return DefaultCharacterAnimDataAsset->CharacterAnimationData.CrouchIdleAnimationAsset;
	}
	return nullptr;
}

AAbilitySystemCharacter* UAG_AnimInstance::GetCharacter() const
{
	if (Character)
	{
		return Character;
	}
	return nullptr;
}
