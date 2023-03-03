// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBarSlotUI.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Ability.h"

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

UImage* UActionBarSlotUI::GetIcon()
{
	return Icon;
}
