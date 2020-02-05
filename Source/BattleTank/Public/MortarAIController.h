// Epic Games (Employee : Juan Esteban Rayo Contreras)

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MortarAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AMortarAIController : public AAIController
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn* InMesh)override;

private:

	UFUNCTION()
	void OnMortarDeath();

	
};
