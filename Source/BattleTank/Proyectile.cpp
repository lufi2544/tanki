// Fill out your copyright notice in the Description page of Project Settings.



#include "Components/StaticMeshComponent.h"
#include "Proyectile.h"
#include "ShootMovementcomponent.h"

// Sets default valuesaaa
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	
	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	ShootMovementComponent = CreateDefaultSubobject<UShootMovementcomponent>(FName("ShootMovementComponent"));
	ShootMovementComponent->bAutoActivate= false;

}

void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorHit.AddDynamic(this,&AProyectile::OnHit);

}

void AProyectile::GetPlayerName() 
	{GetOwner()->GetName();}

void AProyectile::FireProyectile( float Speed )
	{

		ShootMovementComponent->SetVelocityInLocalSpace( FVector::ForwardVector * Speed );

		ShootMovementComponent->Activate();

	}

	void AProyectile::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit )
	
		{

			UE_LOG(LogTemp,Error,TEXT("Hit"));
			
			LaunchBlast->Deactivate();
			ImpactBlast->Activate();

		}

