// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime * FMath::FRandRange(0.6f, 1.4f)) - FMath::Sin(RunningTime));
	float DeltaX = FMath::Sin(RunningTime + DeltaTime * FMath::FRandRange(0.6f, 1.4f)) - FMath::Sin(RunningTime);
	float DeltaY = FMath::Sin(RunningTime + DeltaTime * FMath::FRandRange(0.6f, 1.4f)) - FMath::Sin(RunningTime);
	NewLocation.Z += DeltaHeight * Speed;
	NewLocation.X += DeltaX * Speed;
	NewLocation.Y += DeltaY * Speed;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

}

