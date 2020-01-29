// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Particles/ParticleSystemComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectile.generated.h"


class UShootMovementcomponent;


UCLASS()
class BATTLETANK_API AProyectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	
	virtual void Tick(float DeltaTime) override;

	void FireProyectile(float Speed);

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;
	UParticleSystemComponent*  LaunchBlast = nullptr;

	UShootMovementcomponent* ShootMovementComponent = nullptr;

	//Added again
	void GetPlayerName();

};
