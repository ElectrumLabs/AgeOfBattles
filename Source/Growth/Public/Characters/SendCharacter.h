// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Growth/Growth.h"

#include "SendCharacter.generated.h"

UCLASS()
class GROWTH_API ASendCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASendCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

	//  Character information
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send ID Information")
	FName UnitID;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send ID Information")
	FText UnitName;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send ID Information")
	FText UnitDescription;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send ID Information")
	EUnitType UnitType;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send ID Information")
	EWeaponType WeaponType;
	


	//  Character vitals
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Information")
	float CurrentHealth;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	float MaximumHealth;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	TArray<float> AttackRange;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	TArray<float> AttackDamage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	TArray<float> AttackPenetration;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	TArray<float> Armor;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	TArray<float> AttackSpeed;
	
	UPROPERTY(BlueprintReadWrite, Category = "Send Information", meta = (ExposeOnSpawn="true"))
	EFactionType FactionType;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	TMap<ResourceType, float> UnitTax;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Send Information")
	float GoldBounty;


	UFUNCTION(BlueprintCallable)
	void HandleDamage(float IncomingDamage, float IncomingArmorPenetration, ASendCharacter* InstigatingSend);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_PostDamageEvent(float FinalDamage, ASendCharacter* InstigatingSend);

	UPROPERTY(BlueprintReadWrite)
	ESendState SendState;


};
