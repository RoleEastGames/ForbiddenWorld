// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Rarity.generated.h"

/**
 * 
 */
UCLASS()
class FORBIDDENWORLD_API URarity : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Parameters")
		FText name;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		FText description;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		UTexture2D* backgroung;

	UPROPERTY(EditAnywhere, Category = "Parameters")
		FColor color;

	UPROPERTY(EditAnywhere, Category = "Item infuence")
		int _maxNumberOfParameters;

	UPROPERTY(EditAnywhere, Category = "Item infuence")
		int _maxNumberOfPrefixes;

	UPROPERTY(EditAnywhere, Category = "Item infuence")
		int _maxNumberOfSuffixes;

	UPROPERTY(EditAnywhere, Category = "Item infuence")
		float _baseValueRatio;
};
