// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GrowthPlayerCharacter.generated.h"

UCLASS()
class GROWTH_API AGrowthPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGrowthPlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComponent;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float Value);

	void Zoom(float Value);

};

