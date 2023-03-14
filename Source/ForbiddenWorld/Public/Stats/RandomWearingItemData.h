// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StatInfo.h"
#include "Items/Rarity.h"
#include "RandomWearingItemData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FStatsPrompts
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Вес данного параметра (Чем выше вес, тем с большой вероятностью он выпадет)
		int32 Prompt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Список редкостей, для которых доступен данный параметр
		TArray<URarity*> Rarities;

};

USTRUCT(BlueprintType)
struct FSuffixDataAsset : public FStatsPrompts
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USuffixData* Stat;
};

USTRUCT(BlueprintType)
struct FPrefixDataAsset : public FStatsPrompts
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPrefixData* Stat;
};

USTRUCT(BlueprintType)
struct FItemRandomParameters
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImplicitData* Implicit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UExplicitData* Explicit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSuffixDataAsset> AvailableSuffixes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPrefixDataAsset> AvailablePrefixes;

};

UCLASS(BlueprintType)
class FORBIDDENWORLD_API URandomWearingItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FItemRandomParameters> ItemList;
};
