// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionBarUI.generated.h"

class AAbility;
class UCastBarUI;
class UActionBar;
/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UActionBarUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCastBarUI* DisplayCastBar(AAbility* AbilityToCast);

protected:
	virtual bool Initialize() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	UCastBarUI* CastBarUI;

	UPROPERTY(meta = (BindWidget))
	UActionBar* ActionBar;

	void SetActionBarUIToHUD();
};
