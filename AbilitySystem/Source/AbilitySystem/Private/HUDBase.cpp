// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "Blueprint/UserWidget.h"
#include "ActionBarUI.h"

AHUDBase::AHUDBase()
{
}

void AHUDBase::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Player = GetWorld()->GetFirstPlayerController();
	if (Player && ActionBarWidget)
	{
		ActionBar = CreateWidget<UActionBarUI>(Player, ActionBarWidget);
		ActionBar->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("ActionBar »ý¼º"));
	}
}
