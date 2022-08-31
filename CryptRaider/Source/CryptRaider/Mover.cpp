// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	parent = GetOwner();
	
	startingPosition = parent->GetActorLocation();
	targetPosition = startingPosition + moveOffset;
	speed = FVector::Distance(startingPosition, targetPosition) / moveTime;
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(shouldMove) {Move(DeltaTime);}
}

void UMover::Move(float deltaTime)
{
	FVector currentPosition = parent->GetActorLocation();
	FVector newPosition = FMath::VInterpConstantTo(currentPosition, targetPosition, deltaTime, speed);
	parent->SetActorLocation(newPosition);
}

