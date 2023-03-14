// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
/**
 * 
 */
UENUM()
enum StatType
{
	ST_PREFIX UMETA(DisplayName="Префикс"),
	ST_SUFFIX UMETA(DisplayName = "Суффикс"),
	ST_IMPLICIT UMETA(DisplayName = "Собственный"),
	ST_EXPLICIT UMETA(DisplayName = "Внешний"),
	ST_BASE UMETA(DisplayName = "Базовый"),
};

UENUM()
enum StatKey
{
	SK_ATTACKFLAT UMETA(DisplayName = "Бонус к плоской атаке"),
	SK_ATTACKMULTIPLY UMETA(DisplayName = "Процентный бонус к атаке"),
	SK_HEALTHFLAT UMETA(DisplayName = "Бонус к плоскому здоровью"),
	SK_HEALTHMULTIPLY UMETA(DisplayName = "Процентный бонус к здоровью"),
};

