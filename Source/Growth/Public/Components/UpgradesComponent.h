// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpgradesComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpgrade);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROWTH_API UUpgradesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUpgradesComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int32 AttackRangeLevel;

	int32 AttackDamageLevel;

	int32 AttackPenetrationLevel;

	int32 ArmorLevel;

	int32 AttackSpeedLevel;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Upgrades Manager")
	int32 ReturnAttackRangeLevel()
	{
		return AttackRangeLevel;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Upgrades Manager")
	int32 ReturnAttackDamageLevel()
	{
		return AttackDamageLevel;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Upgrades Manager")
	int32 ReturnAttackPenetrationLevel()
	{
		return AttackPenetrationLevel;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Upgrades Manager")
	int32 ReturnArmorLevel()
	{
		return ArmorLevel;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Upgrades Manager")
	int32 ReturnAttackSpeedLevel()
	{
		return AttackSpeedLevel;
	}

	//  500, 1000, 1500
	UFUNCTION(BlueprintCallable, Category = "Upgrades Manager")
	void UpgradeAttackRangeLevel();

	UFUNCTION(BlueprintCallable, Category = "Upgrades Manager")
	void UpgradeDamageLevel();

	UFUNCTION(BlueprintCallable, Category = "Upgrades Manager")
	void UpgradeAttackPenetrationLevel();

	UFUNCTION(BlueprintCallable, Category = "Upgrades Manager")
	void UpgradeArmorLevel();

	UFUNCTION(BlueprintCallable, Category = "Upgrades Manager")
	void UpgradeAttackSpeedLevel();

	UPROPERTY(BlueprintAssignable, Category = "Upgrade Manager")
	FOnUpgrade OnUpgrade;

	

		
};
