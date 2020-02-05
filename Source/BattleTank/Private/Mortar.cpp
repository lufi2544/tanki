// Epic Games (Employee : Juan Esteban Rayo Contreras)


#include "Mortar.h"

// Sets default values
AMortar::AMortar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMortar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


// Called to bind functionality to input
void AMortar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMortar::GetHealth() { return Health; }

bool AMortar::IsAlive() 
	{
	if (Health <= 0) { return false; }
	else
	{
		return true;
	}

	}


float AMortar::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
	{

	if (IsAlive()) 
	{
	
		ApplyDamage(Damage);
	}
	

	
		
	return Damage;
	}


bool AMortar::ApplyDamage( float DamageAmount ) 
	{

	float CDamage = FMath::Clamp<float>( DamageAmount, 0, Health );

	if ( Health > DamageAmount )	
	{
			
		Health -= DamageAmount;

		return true;

	}
	else
	{

		Health -= CDamage;

		OnDeath.Broadcast();

		return false;

	}

	}



