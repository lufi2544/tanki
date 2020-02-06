#include "Tank.h"
#include "GameFramework/Character.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

float ATank::GetTankHealth() const{return Health;}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)	
	{

		UE_LOG(LogTemp,Warning,TEXT("%f"),Damage);
		ApplyDamage(Damage);

		return Damage;
	}


bool ATank::ApplyDamage(float DamageTaken)
	{	
		//DamageTaken = FMath::Clamp<float>(DamageTaken,0,Health); // We have to declare the clamped value, it is an static method that returns something.
				if(!Dead)
					{ 
						Health-=DamageTaken;

						UE_LOG(LogTemp,Error,TEXT("Damaged!!"));

						if(Health <= 0 )
							{
								Dead = true;
								Health = 0;
								OnDeath.Broadcast();
							}
					}

		return Dead;
	}
 









