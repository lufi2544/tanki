 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankState);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
	

public:

	/*Delegate triggered when the Tank is dead.*/
	FTankState OnDeath;

	/**
	 *Gives you the tank health amount.
	  **/
	UFUNCTION(BlueprintPure, Category = "State")
	float GetTankHealth() const;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	

private:

	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "State")
	float Health = 60;

	/**
	 * Applies a certain damage to the tank and calculates if the Player is still alive.
	 * @return If the Player is death.
	 * @param DamageTaken the amount Damage that the tank recives.
	 **/
	bool ApplyDamage(float DamageTaken);

	bool Dead = false;


};