// Fill out your copyright notice in the Description page of Project Settings.



#include "TankTrack.h"
#include "Components/SceneComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "BattleTank.h"


UTankTrack::UTankTrack()
    {
        
        PrimaryComponentTick.bCanEverTick=false;
       
        

    
         ConstructorHelpers::FObjectFinder<UStaticMesh>StaticmeshFinder(TEXT("StaticMesh'/Game/Tank/tank_fbx_Track.tank_fbx_Track'"));

        if(StaticmeshFinder.Object)
            {

                UStaticMesh* TrackAsset= StaticmeshFinder.Object;

                this->SetStaticMesh(TrackAsset);
                   


            }else
            {
                UE_LOG(LogTemp,Error,TEXT("There is No Track Mesh Found"));
            }
    }


  

    void UTankTrack::BeginPlay()
    {

        Super::BeginPlay();

        OnComponentHit.AddDynamic(this,&UTankTrack::OnHit);

    }


    void UTankTrack::SetThrottle(float Throttle)
        {

            CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle,-1,+1);

        }


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit )
    {
    
        DrivingTrack();
        ApplySidewaysForce();
      
        CurrentThrottle =0;
    }

void UTankTrack::ApplySidewaysForce( )
    {
     
                auto SlippageSpeed = FVector::DotProduct(GetRightVector(),GetComponentVelocity());

                 auto CorrectionAcceleration = -SlippageSpeed / GetWorld()->GetDeltaSeconds() * GetRightVector();

                //(F = m * a)

                auto TankRoot = Cast <UStaticMeshComponent>(GetOwner()->GetRootComponent());

                auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // 2 tracks

               TankRoot->AddForce(CorrectionForce);
    
    }

    void  UTankTrack::DrivingTrack()
        {
                auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
                auto ForceLocation = GetComponentLocation();
                auto TankPrimitiveComponent =Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

                TankPrimitiveComponent->AddForceAtLocation(
                    ForceApplied,
                    ForceLocation
                );


        }