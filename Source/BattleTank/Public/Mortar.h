// Epic Games (Employee : Juan Esteban Rayo Contreras)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Mortar.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMortarState);

UCLASS()
class BATTLETANK_API AMortar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMortar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Health Amount
	UPROPERTY(EditDefaultsOnly, Category="State")
	float Health = 100;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual bool ApplyDamage(float DamageAmount);

	bool IsAlive();



public:	

	UFUNCTION(BlueprintPure, Category = "State")
	float GetHealth();
		




	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Triggered when the Mortar dies.
	FMortarState OnDeath;

};
