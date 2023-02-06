// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Growth/Growth.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UUpgradesComponent* UpgradesComponent;

	AEnemyController();

	UPROPERTY(BlueprintReadWrite)
	TMap<EUnitType, int32> PlayerCompositionAssessment;

	UPROPERTY(BlueprintReadWrite)
	TMap<EUnitType, int32> EnemyCompositionAssessment;

	UFUNCTION(BlueprintCallable)
	void IncrementComposition(EUnitType UnitType, int32 UnitValue, EFactionType FactionType);

	UFUNCTION(BlueprintCallable)
	void ResetComposition(EFactionType FactionType);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EUnitType RecommendNextUnit();

};
