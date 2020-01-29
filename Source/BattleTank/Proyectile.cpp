// Fill out your copyright notice in the Description page of Project Settings.



#include "Components/StaticMeshComponent.h"
#include "Proyectile.h"
#include "ShootMovementcomponent.h"

// Sets default valuesaaa
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->AttachTo(RootComponent);
	
	ShootMovementComponent = CreateDefaultSubobject<UShootMovementcomponent>(FName("ShootMovementComponent"));

	ShootMovementComponent->bAutoActivate= false;

}

void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AProyectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProyectile::FireProyectile(float Speed)
	{

		ShootMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);

		ShootMovementComponent->Activate();

	}


void AProyectile::GetPlayerName() 
	{
	
	GetOwner()->GetName();

}

