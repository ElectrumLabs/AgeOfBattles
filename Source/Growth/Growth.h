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

