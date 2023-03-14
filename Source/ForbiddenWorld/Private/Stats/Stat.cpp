// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/Stat.h"
#include <random>
#include <algorithm>

FStat::FStat()
{
	Name = FText::FromString("Default");
	Description = FText::FromString("Default");
	Value = 0;
	Tier = 0;
	Type = ST_PREFIX;
	Key = SK_ATTACKFLAT;
}

void  FStat::Generate(UStatInfo* info, int itemLevel)
{

	Name = info->GetDescription().name;
	Description = info->GetDescription().description;

	Type = info->GetType();
	Key = info->GetKey();

	const auto list = info->GetTierList();

	// Сумма всех значений вероятности тиров параметра
	int32 generalPrompt = 0;
	// Массив, который определит как тир использовать в дальнейшем
	int32* tierPrompts = new int32[list.Num()];
	for (int32 i = 0; i < list.Num(); i++) {
		// Проверяем подходящий уровень тира
		if (list[i].reqiuredItemLevel <= itemLevel) {
			generalPrompt += list[i].promptValue;
			tierPrompts[i] = generalPrompt;
		}
	}
	// Генератор случайных чисел
	std::random_device rng;
	std::mt19937 gen(rng());
	std::uniform_int_distribution<int> range(0, generalPrompt);
	// Значение вероятности, полученное случайным образом
	int32 prompt = range(rng);
	// Ищем найденный диапозон
	for (int32 i = 0; i < list.Num(); i++) {
		if (tierPrompts[i] <= prompt) {
			// Нашли необходимый тир -> записываем свойства параметра в наш стат
			Tier = list[i].level;
			std::uniform_real_distribution < float > rngValue(list[i].minValue, list[i].maxValue);
			Value = rngValue(rng);
			break;
		}
	}
	delete tierPrompts;
}