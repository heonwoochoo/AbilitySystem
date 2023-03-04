// Fill out your copyright notice in the Description page of Project Settings.

#include "Ability.h"
#include "UI/CastBarUI.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"
#include "HUDBase.h"
#include "DefaultGameModeBase.h"
#include "GameFramework/Character.h"

void UCastBarUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (Ability && IsVisible())
	{
		float ElapedTime = GetWorld()->GetTimerManager().GetTimerElapsed(CastTimer);
		float CurrentPercent = ElapedTime / Ability->GetCastTime();
		CastBar->SetPercent(CurrentPercent);
	}
}

bool UCastBarUI::Initialize()
{
	bool success = Super::Initialize();
	if (!success) return false;

	SetVisibility(ESlateVisibility::Hidden);
	SetCastBarToHUD();
	return true;
}

void UCastBarUI::SetCastBarToHUD()
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
				HUDBase->SetCastBar(this);
			}
		}
	}
}

void UCastBarUI::StartCast()
{
	UE_LOG(LogTemp, Warning, TEXT("StartCast"));
	if (Ability)
	{
		AbilityName->SetText(FText::FromString(Ability->GetName()));
		GetWorld()->GetTimerManager().SetTimer(CastTimer, this, &UCastBarUI::CompletedCast, Ability->GetCastTime(), false);
		SetVisibility(ESlateVisibility::Visible);
	}
}

void UCastBarUI::CompletedCast()
{
	UE_LOG(LogTemp, Warning, TEXT("CompletedCast"));

	if (Ability)
	{
		Ability->SpawnAbility();
	}

	SetVisibility(ESlateVisibility::Hidden);
}

void UCastBarUI::InterruptedCast()
{

}

void UCastBarUI::CastTestFunc()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello I'm Cast func"));
}
