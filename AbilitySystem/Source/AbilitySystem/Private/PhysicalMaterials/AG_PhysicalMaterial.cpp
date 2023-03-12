// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicalMaterials/AG_PhysicalMaterial.h"

USoundBase* UAG_PhysicalMaterial::GetFootstepSound() const
{
	if (FootstepSound)
	{
		return FootstepSound;
	}
	return nullptr;
}
