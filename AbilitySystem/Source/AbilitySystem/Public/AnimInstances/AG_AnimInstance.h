// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AG_AnimInstance.generated.h"

class AAbilitySystemCharacter;

UCLASS()
class ABILITYSYSTEM_API UAG_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	virtual void NativeInitializeAnimation() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AAbilitySystemCharacter* Character;

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	class UBlendSpace* GetLocomotionBlendSpace() const;

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	class UAnimSequence* GetIdleAnimation() const;

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	class UBlendSpace* GetCrouchLocomotionBlendSpace() const;

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	class UAnimSequence* GetCrouchIdleAnimation() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	class UCharacterAnimDataAsset* DefaultCharacterAnimDataAsset;

	UFUNCTION(BlueprintCallable)
	AAbilitySystemCharacter* GetCharacter() const;
};
