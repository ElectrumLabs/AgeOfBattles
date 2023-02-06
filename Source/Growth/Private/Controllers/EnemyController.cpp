// Electrum Labs LLC 2023


#include "Controllers/EnemyController.h"

#include "Components/ResourceComponent.h"
#include "Components/UpgradesComponent.h"

AEnemyController::AEnemyController()
{
	ResourceComponent = CreateDefaultSubobject<UResourceComponent>(TEXT("Resource Manager"));

	UpgradesComponent = CreateDefaultSubobject<UUpgradesComponent>(TEXT("Upgrades Manager"));

	EnemyCompositionAssessment.Add(EUnitType::Armored, 0);
	EnemyCompositionAssessment.Add(EUnitType::Unarmored, 0);
	EnemyCompositionAssessment.Add(EUnitType::Piercing, 0);

	PlayerCompositionAssessment.Add(EUnitType::Armored, 0);
	PlayerCompositionAssessment.Add(EUnitType::Unarmored, 0);
	PlayerCompositionAssessment.Add(EUnitType::Piercing, 0);


}

void AEnemyController::IncrementComposition(EUnitType UnitType, int32 UnitValue, EFactionType FactionType)
{

	if (FactionType == EFactionType::Friendly)
	{
		PlayerCompositionAssessment[UnitType] = PlayerCompositionAssessment[UnitType] + UnitValue;
	}

	if (FactionType == EFactionType::Enemy)
	{
		EnemyCompositionAssessment[UnitType] = EnemyCompositionAssessment[UnitType] + UnitValue;
	}
}

void AEnemyController::ResetComposition(EFactionType FactionType)
{
	if (FactionType == EFactionType::Friendly)
	{
		for (auto& Elem : PlayerCompositionAssessment)
		{
			PlayerCompositionAssessment[Elem.Key] = 0;
		}
	}

	if (FactionType == EFactionType::Enemy)
	{
		for (auto& Elem : EnemyCompositionAssessment)
		{
			EnemyCompositionAssessment[Elem.Key] = 0;
		}
	}
}

EUnitType AEnemyController::RecommendNextUnit()
{
	TMap<EUnitType, int32> CompositionDifference;

	TArray<EUnitType> UnitCandidate;
	
	for (auto& UnitType : PlayerCompositionAssessment)
	{
		const int32 Difference = PlayerCompositionAssessment[UnitType.Key] - EnemyCompositionAssessment[UnitType.Key];

		if (Difference > 0)
		{
			UnitCandidate.Add(UnitType.Key);
		}
	}

	//  in the future, rank based off difference
	if (UnitCandidate.Num() > 0)
	{
		const int32 RandomIndexFromCompDiff = FMath::RandRange(0, UnitCandidate.Num()-1);

		EUnitType RandomCandidate = UnitCandidate[RandomIndexFromCompDiff];

		switch (RandomCandidate)
		{
			case EUnitType::Armored: return EUnitType::Piercing;

			case EUnitType::Piercing: return EUnitType::Unarmored;

			case EUnitType::Unarmored: return EUnitType::Armored;

		default: return EUnitType::Unarmored;
		}
	}
	else return EUnitType::Unarmored;
	
}
