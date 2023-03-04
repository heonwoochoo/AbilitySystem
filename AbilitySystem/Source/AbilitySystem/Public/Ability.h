// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.generated.h"

class UTexture2D;
class AAbilitySystemCharacter;

UCLASS()
class ABILITYSYSTEM_API AAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    float Cost;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    float Cooldown;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    float CastTime;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    bool bIsInterruptable;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    bool bRequiresTarget;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Properties", meta = (AllowPrivateAccess = "ture"))
    UTexture2D* Icon;

    AAbilitySystemCharacter* Character;

public:
    FORCEINLINE FString GetName() const { return Name; }
    FORCEINLINE FString GetDescription() const { return Description; }
    FORCEINLINE float GetCost() const { return Cost; }
    FORCEINLINE float GetCooldown() const { return Cooldown; }
    FORCEINLINE float GetCastTime() const { return CastTime; }
    FORCEINLINE bool GetIsInterruptable() const { return bIsInterruptable; }
    FORCEINLINE bool GetRequiresTarget() const { return bRequiresTarget; }
    UTexture2D* GetIcon();

    void SpawnAbility();
};
