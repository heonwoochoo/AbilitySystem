// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameTypes.h"
#include "AnimNotify_Step.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAnimNotify_Step : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
	UPROPERTY(EditAnywhere)
	EFoot Foot;
};
