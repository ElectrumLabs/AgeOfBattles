// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ResourceType : uint8
{
	Wood	UMETA(DisplayName = "Wood"),
	Food	UMETA(DisplayName = "Food"),
	Gold	UMETA(DisplayName = "Gold"),
	Ore		UMETA(DisplayName = "Ore"),
};

UENUM(BlueprintType)
enum class EUnitType : uint8
{
	Unarmored	UMETA(DisplayName = "Unarmored"),
	Armored		UMETA(DisplayName = "Armored"),
	Piercing	UMETA(DisplayName = "Piercing")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee		UMETA(DisplayName = "Melee"),
	Ranged		UMETA(DisplayName = "Ranged")
};

UENUM(BlueprintType)
enum class EFactionType : uint8
{
	Friendly		UMETA(DisplayName = "Friendly"),
	Enemy			UMETA(DisplayName = "Enemy")
};



