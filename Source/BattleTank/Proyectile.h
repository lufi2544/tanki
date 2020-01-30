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

	void FireProyectile(float Speed);

private:

	//Proyectile Static Mesh.
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;

	//Particle System for the proyectile.
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent*  LaunchBlast = nullptr;

	//Particle System (Impact) for the proyectile.
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent*  ImpactBlast = nullptr;

	UFUNCTION()
	void OnHit (AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit );

	UShootMovementcomponent* ShootMovementComponent = nullptr;

	//Added again
	void GetPlayerName();

};
