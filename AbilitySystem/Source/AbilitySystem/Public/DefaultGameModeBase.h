// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DefaultGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API ADefaultGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ADefaultGameModeBase();

	UFUNCTION(BlueprintCallable)
	void GameModeFunc();

protected:
	virtual void BeginPlay() override;

private:
};
