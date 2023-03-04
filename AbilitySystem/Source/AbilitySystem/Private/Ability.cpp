#include "Ability.h"
#include "Kismet/GameplayStatics.h"
#include "HUDBase.h"
#include "DefaultGameModeBase.h"
#include "ActionBarUI.h"
#include "UI/CastBarUI.h"
#include "GameFramework/Character.h"
#include "../AbilitySystemCharacter.h"

AAbility::AAbility()
{
 	PrimaryActorTick.bCanEverTick = true;

}

void AAbility::BeginPlay()
{
	Super::BeginPlay();

}

void AAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UTexture2D* AAbility::GetIcon()
{
	return Icon;
}

void AAbility::SpawnAbility()
{
	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Player)
	{
		Character = Cast<AAbilitySystemCharacter>(Player);
		if (Character)
		{
			const FVector Location{ Character->GetActorLocation() };
			const FRotator Rotation{ Character->GetActorRotation() };
			FActorSpawnParameters SpawnParameters;
			GetWorld()->SpawnActor<AAbility>(Location, Rotation, SpawnParameters);
			UE_LOG(LogTemp, Warning, TEXT("Spawn Ability !"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Character is not found "));
		}
	}
}


