// Epic Games (Employee : Juan Esteban Rayo Contreras

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;

/**
 * Controlls the movement of the tank tracks in order to the tank to move.
 */
UCLASS(meta = (BlueprintSpawnableComponent), Category = "Custom")
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

	public:

	//Apply a certain amount of throttle to both tank tracks.
	UFUNCTION(BlueprintCallable, Category = " Movement")
	void IntendMoveForward(float Throw);

	//Move The Tank Torwards a Right/Left direction depends on the in Throw and returns a String indicating the Turned Side.
	UFUNCTION(BlueprintCallable, Category = " Movement")
	UPARAM (DisplayName="Turned Side")FString IntendMoveSides(float Throw);


	//Sets the tracks references into c++
	UFUNCTION(BlueprintCallable, category = " Movement")
	void Initialise(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet);



	private:

	float DotVectorAngle;
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

	// Caled from the path finidng logic by AIController class
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	
};
