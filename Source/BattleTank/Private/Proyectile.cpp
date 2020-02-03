// Fill out your copyright notice in the Description page of Project Settings.



#include "Proyectile.h"
#include "ShootMovementcomponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default valuesaaa
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//The Mesh Component of the Projectile
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	//The Particle System at the Launch Time
	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	
	//the Particle System at the Impact Time
	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	//Te radial Force at the Impact Time
	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Radial Force"));
	ExplosionForce->bAutoActivate = false;
	ExplosionForce->bIgnoreOwningActor = true;
	ExplosionForce->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);


	//The Shootment Component of the Projectile
	ShootMovementComponent = CreateDefaultSubobject<UShootMovementcomponent>(FName("ShootMovementComponent"));
	ShootMovementComponent->bAutoActivate= false;

}

void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionMesh->OnComponentHit.AddDynamic(this,&AProyectile::OnHit);
	

}

void AProyectile::GetPlayerName() 
	{GetOwner()->GetName();}

void AProyectile::FireProyectile( float Speed )
	{

		ShootMovementComponent->SetVelocityInLocalSpace( FVector::ForwardVector * Speed );

		ShootMovementComponent->Activate();

	}

	void AProyectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit )
	
		{
			
				

			LaunchBlast->Deactivate();
			ImpactBlast->Activate();
			ExplosionForce->Activate();
			ExplosionForce->FireImpulse();
			
			SetRootComponent(ImpactBlast);
			CollisionMesh->DestroyComponent();


			UGameplayStatics::ApplyRadialDamage(
				this,
				BaseDamage,
				this->GetActorLocation(),
				ExplosionForce->Radius,
				UDamageType::StaticClass(),
				TArray<AActor*>()
			);


			FTimerHandle Timehandler;

			GetWorld()->GetTimerManager().SetTimer(Timehandler,this,&AProyectile::OnTimerExpire,DestroyDelay,false);



		}


void AProyectile::OnTimerExpire()
	{

		Destroy();

	}

