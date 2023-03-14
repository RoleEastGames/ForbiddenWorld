// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EStatType.h"
#include "StatInfo.generated.h"

USTRUCT(BlueprintType)
struct FStatTier {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float minValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int reqiuredItemLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 promptValue;
};

USTRUCT(BlueprintType)
struct FStatDescription {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText description;
};

/**
 * 
 */
UCLASS(BlueprintType)
class FORBIDDENWORLD_API UStatInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "Parameters")
	TArray<FStatTier> TierList;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	FStatDescription Description;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Parameters")
	TEnumAsByte<StatType> Type;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	TEnumAsByte<StatKey> Key;

public:

	TArray<FStatTier> GetTierList();

	FStatDescription GetDescription();

	TEnumAsByte<StatType> GetType();

	TEnumAsByte<StatKey> GetKey();
};

UCLASS(BlueprintType)
class FORBIDDENWORLD_API UPrefixData : public UStatInfo
{
	GENERATED_BODY()

public:
	UPrefixData();
};

UCLASS(BlueprintType)
class FORBIDDENWORLD_API USuffixData : public UStatInfo
{
	GENERATED_BODY()

public:
	USuffixData();
};


UCLASS(BlueprintType)
class FORBIDDENWORLD_API UImplicitData : public UStatInfo
{
	GENERATED_BODY()

public:
	UImplicitData();
};


UCLASS(BlueprintType)
class FORBIDDENWORLD_API UExplicitData : public UStatInfo
{
	GENERATED_BODY()

public:
	UExplicitData();
};

