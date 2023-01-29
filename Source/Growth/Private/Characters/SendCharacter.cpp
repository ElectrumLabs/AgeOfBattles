// Electrum Labs LLC 2023


#include "Characters/SendCharacter.h"

// Sets default values
ASendCharacter::ASendCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentHealth = MaximumHealth;

}

// Called when the game starts or when spawned
void ASendCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASendCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASendCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

