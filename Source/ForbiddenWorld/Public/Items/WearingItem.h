// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stats/Stat.h"
#include "Items/Item.h"
#include "Items/Equip.h"
#include "WearingItem.generated.h"

UENUM(BlueprintType)
enum ESocket {

	SC_LEFTHAND UMETA(DisplayName = "Левая рука"),
	SC_RIGHTHAND UMETA(DisplayName = "Правая рука"),
	SC_EXTRASLOT UMETA(DisplayName = "Слот для дополнительного оружия"),

	SC_HELMET UMETA(DisplayName = "Шлем"),
	SC_BODY UMETA(DisplayName = "Нагрудник"),
	SC_BOOTS UMETA(DisplayName = "Ботинки"),
	SC_GLOVES UMETA(DisplayName = "Перчатки"),
	SC_BELT UMETA(DisplayName = "Пояс"),

	SC_AMULET UMETA(DisplayName = "Амулет"),
	SC_RING UMETA(DisplayName = "Кольцо"),

};

/**
 * 
 */
UCLASS()
class FORBIDDENWORLD_API AWearingItem : public AItem, public IEquip
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Stats")
	FStat _implicit;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Stats")
	FStat _explicit;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Stats")
	TArray<FStat> _prefixes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Stats")
	TArray<FStat> _suffixes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Stats")
	TArray<TEnumAsByte<ESocket>> _availableSockets;

	// Таг для доступных классов

public:
	UFUNCTION(BlueprintCallable)
	virtual void equip() override;
};
