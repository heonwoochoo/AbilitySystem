// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBarSlotUI.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Ability.h"
#include "Kismet/GameplayStatics.h"
#include "HUDBase.h"
#include "DefaultGameModeBase.h"
#include "UI/CastBarUI.h"

void UActionBarSlotUI::NativePreConstruct()
{
	if (CoolDownProgressBar)
	{
		CoolDownProgressBar->SetPercent(0.3f);
	}

	if (AbilityClass)
	{
		AbilityClassObject = Cast<AAbility>(AbilityClass->GetDefaultObject());
		if (AbilityClassObject)
		{
			if (Icon)
			{
				Icon->SetBrushFromTexture(AbilityClassObject->GetIcon());
			}
		}
	}
}

bool UActionBarSlotUI::Initialize()
{
	bool success = Super::Initialize();
	if (!success)
	{
		return false;
	}

	if (CastButton)
	{
		CastButton->OnClicked.AddDynamic(this, &UActionBarSlotUI::OnClickedButton);
	}

	return true;
}

void UActionBarSlotUI::OnClickedButton()
{
	bIsCasting = true;
	UE_LOG(LogTemp, Warning, TEXT("Clicked button !"));
	
	SetSlotToHUD();
	CastAction();
}

void UActionBarSlotUI::CastAction()
{
	if (HUDBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("CastAction"));
		HUDBase->GetCastBarUI()->SetAbility(AbilityClassObject);
		HUDBase->GetCastBarUI()->StartCast();
	}
}

void UActionBarSlotUI::SetSlotToHUD()
{
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
	if (GameMode)
	{
		ADefaultGameModeBase* DefaultGameMode = Cast<ADefaultGameModeBase>(GameMode);
		if (DefaultGameMode)
		{
			AActor* HUDClass = (UGameplayStatics::GetActorOfClass(this, DefaultGameMode->HUDClass));
			HUDBase = Cast<AHUDBase>(HUDClass);
			if (HUDBase)
			{
				HUDBase->SetActionBarSlot(this);
			}

		}
	}
}

UImage* UActionBarSlotUI::GetIcon()
{
	return Icon;
}
