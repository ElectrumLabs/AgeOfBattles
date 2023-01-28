// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/ResourceComponent.h"

#include "GrowthPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GROWTH_API AGrowthPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UResourceComponent* ResourceComponent;

	AGrowthPlayerController();
	
};
