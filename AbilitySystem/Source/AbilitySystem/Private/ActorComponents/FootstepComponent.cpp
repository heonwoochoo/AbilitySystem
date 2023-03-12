// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemCharacter.h"
#include "ActorComponents/FootstepComponent.h"
#include "PhysicalMaterials/AG_PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UFootstepComponent::UFootstepComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UFootstepComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UFootstepComponent::HandleFootstep(EFoot Foot)
{
	AAbilitySystemCharacter* Character = Cast<AAbilitySystemCharacter>(GetOwner());
	if (Character)
	{
		USkeletalMeshComponent* Mesh = Character->GetMesh();
		if (Mesh)
		{
			FHitResult HitResult;
			const FVector SocketLocation = Mesh->GetSocketLocation(Foot == EFoot::Left ? LeftFootSocketName : RightFootSocketName);
			const FVector Location = SocketLocation + FVector::UpVector * 20.f;


			FCollisionQueryParams QueryParams;
			QueryParams.bReturnPhysicalMaterial = true;
			QueryParams.AddIgnoredActor(Character);

			if (GetWorld())
			{
				GetWorld()->LineTraceSingleByChannel(HitResult, Location, Location + FVector::UpVector * -50.f, ECollisionChannel::ECC_WorldStatic, QueryParams);
				DrawDebugLine(GetWorld(), Location, Location + FVector::UpVector * -50.f, FColor::Red, false, 0.1f, 0U, 10.f);
				if (HitResult.bBlockingHit)
				{
					UAG_PhysicalMaterial* PhysicalMaterial = Cast<UAG_PhysicalMaterial>(HitResult.PhysMaterial.Get());
					if (PhysicalMaterial)
					{
						if (PhysicalMaterial->GetFootstepSound())
						{
							UGameplayStatics::PlaySoundAtLocation(this, PhysicalMaterial->GetFootstepSound(), Location);
						}
					}
				}
			}
		}
	}
}
