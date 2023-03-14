// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/StatInfo.h"

TArray<FStatTier> UStatInfo::GetTierList()
{
	return TierList;
}

FStatDescription UStatInfo::GetDescription()
{
	return Description;
}

TEnumAsByte<StatType> UStatInfo::GetType()
{
	return Type;
}

TEnumAsByte<StatKey> UStatInfo::GetKey()
{
	return Key;
}

USuffixData::USuffixData()
{
	Type = ST_SUFFIX;
}

UPrefixData::UPrefixData()
{
	Type = ST_PREFIX;
}

UImplicitData::UImplicitData()
{
	Type = ST_IMPLICIT;
}

UExplicitData::UExplicitData()
{
	Type = ST_EXPLICIT;
}