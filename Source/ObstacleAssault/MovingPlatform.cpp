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
void AMovingPlatform::Tick(float const DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float const DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector const MoveDirection = PlatformVelocity.GetSafeNormal();
	
		StartLocation = StartLocation + (MoveDirection * MoveDistance);

		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float const DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("RotatePlatform delta time: %f"), DeltaTime);
	// FRotator const Rotation = FRotator(0, 0, 0);
	//
	// FRotator const DeltaRotation = FRotator(0, 0, 0);
	//
	// FRotator const NewRotation = Rotation + DeltaRotation;
	//
	// SetActorRotation(NewRotation);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(GetActorLocation(), StartLocation);
}
