// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "Components/ResourceComponent.h"


#include "GrowthController.generated.h"

/**
 * 
 */
UCLASS()
class GROWTH_API AGrowthController : public AController
{
	GENERATED_BODY()

public:
	AGrowthController();
	
	UPROPERTY(VisibleAnywhere)
	class UResourceComponent* ResourceComponent;
	
};
