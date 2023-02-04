// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class GROWTH_API AEnemyController : public AAIController
{
	GENERATED_BODY()


public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UResourceComponent* ResourceComponent;

	AEnemyController();
};
