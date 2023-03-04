// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionBarSlotUI.generated.h"

class UButton;
class UImage;
class UProgressBar;
class AAbility;
class AHUDBase;

UCLASS()
class ABILITYSYSTEM_API UActionBarSlotUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AAbility> AbilityClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AHUDBase* HUDBase;

protected:
	void NativePreConstruct() override;
	virtual bool Initialize() override;

	UFUNCTION()
	void OnClickedButton();

	void CastAction();

	void SetSlotToHUD();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AAbility* AbilityClassObject;

	UPROPERTY(meta = (BindWidget))
	UButton* CastButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* CoolDownProgressBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsCasting = false;

public:
	UFUNCTION(BlueprintCallable)
	UImage* GetIcon();

	FORCEINLINE bool GetIsCasting() const { return bIsCasting; }
};
