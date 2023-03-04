// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBarUI.h"
#include "Ability.h"
#include "UI/CastBarUI.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "DefaultGameModeBase.h"
#include "HUDBase.h"
UCastBarUI* UActionBarUI::DisplayCastBar(AAbility* AbilityToCast)
{
	if (CastBarUI)
	{
		CastBarUI->SetVisibility(ESlateVisibility::Visible);
		CastBarUI->SetAbility(AbilityToCast);
		CastBarUI->StartCast();
		return CastBarUI;
	}
	return CastBarUI;
}

bool UActionBarUI::Initialize()
{
	bool success = Super::Initialize();
	if (!success) return false;

	SetActionBarUIToHUD();

	return true;
}

void UActionBarUI::SetActionBarUIToHUD()
{
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
	if (GameMode)
	{
		ADefaultGameModeBase* DefaultGameMode = Cast<ADefaultGameModeBase>(GameMode);
		if (DefaultGameMode)
		{
			AActor* HUDClass = (UGameplayStatics::GetActorOfClass(this, DefaultGameMode->HUDClass));
			AHUDBase* HUDBase = Cast<AHUDBase>(HUDClass);
			if (HUDBase)
			{
				HUDBase->SetActionBar(this);
			}
		}
	}
}
