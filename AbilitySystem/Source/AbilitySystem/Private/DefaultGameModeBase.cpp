#include "DefaultGameModeBase.h"

ADefaultGameModeBase::ADefaultGameModeBase()
{
}

void ADefaultGameModeBase::GameModeFunc()
{
	UE_LOG(LogTemp, Warning, TEXT("Hi I'm GameMode"));
}

void ADefaultGameModeBase::BeginPlay()
{
	Super::BeginPlay();

}
