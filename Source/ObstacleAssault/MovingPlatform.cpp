// @copyright SKH

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	
	SetActorLocation(CurrentLocation);

	float const Distance = FVector::Distance(CurrentLocation, StartLocation);

	if (Distance > MoveDistance)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
	
		StartLocation = StartLocation + (MoveDirection * MoveDistance);

		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}
