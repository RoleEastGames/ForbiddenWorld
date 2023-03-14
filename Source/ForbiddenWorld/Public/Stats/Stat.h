// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EStatType.h"
#include "StatInfo.h"

#include "Stat.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct FORBIDDENWORLD_API FStat
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText Description;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Tier;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Value;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<StatType> Type;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<StatKey> Key;

	void Generate(UStatInfo*, int);

	FStat();
};
