// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

class UActionBarUI;

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:
	AHUDBase();
	

protected:
	void BeginPlay() override;



private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Widget, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UActionBarUI> ActionBarWidget;
		
	UPROPERTY()
	UActionBarUI* ActionBar;

};
