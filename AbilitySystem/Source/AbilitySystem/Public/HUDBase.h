// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

class UActionBarUI;
class UActionBarSlotUI;
class UCastBarUI;
/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:
	AHUDBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Widget)
	TSubclassOf<UActionBarUI> ActionBarWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget)
	UActionBarUI* ActionBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget)
	UActionBarSlotUI* CurrentSlot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget)
	UCastBarUI* CastBar;

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;


private:


public:
	void SetActionBar(UActionBarUI* ActionBarUI);
	FORCEINLINE UActionBarUI* GetActionBarUI() const { return ActionBar; }

	void SetActionBarSlot(UActionBarSlotUI* ClickedSlot);
	FORCEINLINE UActionBarSlotUI* GetActionBarSlot() const { return CurrentSlot; }

	void SetCastBar(UCastBarUI* NewCastBar);
	FORCEINLINE UCastBarUI* GetCastBarUI() const { return CastBar; }

};
