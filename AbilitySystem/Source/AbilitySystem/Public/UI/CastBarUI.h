// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CastBarUI.generated.h"

class UProgressBar;
class UTextBlock;
class AAbility;
class AHUDBase;
UCLASS()
class ABILITYSYSTEM_API UCastBarUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual bool Initialize() override;

	void SetCastBarToHUD();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AAbility* Ability;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AHUDBase* HUDBase;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* CastBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AbilityName;

	FTimerHandle CastTimer;
	

public:
	FORCEINLINE void SetAbility(AAbility* NewAbility) { Ability = NewAbility; }
	void StartCast();
	void CompletedCast();
	void InterruptedCast();

	void CastTestFunc();
};
