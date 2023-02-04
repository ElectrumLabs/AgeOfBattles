// Electrum Labs LLC 2023


#include "Controllers/EnemyController.h"

#include "Components/ResourceComponent.h"

AEnemyController::AEnemyController()
{
	ResourceComponent = CreateDefaultSubobject<UResourceComponent>(TEXT("Resource Manager"));
}
