// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveActor.h"


// Sets default values
AMoveActor::AMoveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
	CountdownTime = 3;
}

// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	
	OriginalTransform = GetActorLocation();
	StartMoveEvent();

}

// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AMoveActor::GetOriginalTransform()
{
	return OriginalTransform;
}


FVector AMoveActor::GetTargetTransform()
{
	return TargetTransform;
}

void AMoveActor::AdvancedTimer()
{
	--CountdownTime;
	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void AMoveActor::CountdownHasFinished_Implementation()
{

}

void AMoveActor::StartMoveEvent_Implementation()
{
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AMoveActor::AdvancedTimer, 1.0f, true);
}

