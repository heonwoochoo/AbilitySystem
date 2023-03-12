// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AG_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAG_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	class UBlendSpace* GetLocomotionBlendSpace() const;

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	class UAnimSequence* GetIdleAnimation() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	class UCharacterAnimDataAsset* DefaultCharacterAnimDataAsset;
};
