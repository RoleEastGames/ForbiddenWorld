// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/WearingItem.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class FORBIDDENWORLD_API AWeapon : public AWearingItem
{
	GENERATED_BODY()
	
protected:

	int32 _baseAttack;

	// Место для компонента атаки

public:
	virtual void equip() override;
};
