// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectile.generated.h"

class UParticleSystemComponent;
class UShootMovementcomponent;
class URadialForceComponent;


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

	//Projectile Damage
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float BaseDamage;

	//Proyectile Static Mesh.
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;

	//Particle System for the proyectile.
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent*  LaunchBlast = nullptr;

	//Particle System (Impact) for the proyectile.
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent*  ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Firing")
	URadialForceComponent* ExplosionForce = nullptr;;

	//The delay time for the actor to be destroyed after impacting.
	UPROPERTY(EditAnywhere, Category = " SetUp")
	float DestroyDelay = 3;

	UFUNCTION()
	void OnHit (UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

	UShootMovementcomponent* ShootMovementComponent = nullptr;

	//Added again
	void GetPlayerName();
	void OnTimerExpire();

};
