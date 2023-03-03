// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionBarSlotUI.generated.h"

class UButton;
class UImage;
class UProgressBar;
class AAbility;


UCLASS()
class ABILITYSYSTEM_API UActionBarSlotUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AAbility> AbilityClass;

protected:
	void NativePreConstruct() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AAbility* AbilityClassObject;

	UPROPERTY(meta = (BindWidget))
	UButton* CastButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* CoolDownProgressBar;

public:
	UFUNCTION(BlueprintCallable)
	UImage* GetIcon();
	
};
