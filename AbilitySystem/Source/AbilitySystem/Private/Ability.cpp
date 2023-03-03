#include "Ability.h"

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


