// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "Blueprint/UserWidget.h"
#include "ActionBarUI.h"
#include "ActionBarSlotUI.h"
#include "UI/CastBarUI.h"

AHUDBase::AHUDBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHUDBase::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Player = GetWorld()->GetFirstPlayerController();
	if (Player && ActionBarWidget)
	{
		ActionBar = CreateWidget<UActionBarUI>(Player, ActionBarWidget);
		ActionBar->AddToViewport();
	}
}

void AHUDBase::Tick(float DeltaTime)
{
}

void AHUDBase::SetActionBar(UActionBarUI* ActionBarUI)
{
	ActionBar = ActionBarUI;
}

void AHUDBase::SetActionBarSlot(UActionBarSlotUI* ClickedSlot)
{
	CurrentSlot = ClickedSlot;
}

void AHUDBase::SetCastBar(UCastBarUI* NewCastBar)
{
	CastBar = NewCastBar;
}
