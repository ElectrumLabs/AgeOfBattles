// Electrum Labs LLC 2023


#include "Characters/GrowthPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGrowthPlayerCharacter::AGrowthPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f,400.f));
	CameraBoom->TargetArmLength = 1000.f;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void AGrowthPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrowthPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGrowthPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AGrowthPlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Zoom", this, &AGrowthPlayerCharacter::Zoom);


}

void AGrowthPlayerCharacter::MoveRight(float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AGrowthPlayerCharacter::Zoom(float Value)
{
	const float CameraBoomValue = 	FMath::Clamp(CameraBoom->TargetArmLength += (Value * 10.f), 500.f, 2000.f);

	CameraBoom->TargetArmLength = CameraBoomValue;

}

