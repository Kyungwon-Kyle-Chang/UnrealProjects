// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class QUICKSTART_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	FVector OriginalTransform;

	UPROPERTY(EditAnywhere)
	FVector TargetTransform;

	UFUNCTION(BlueprintCallable)
		FVector GetOriginalTransform();
	
	UFUNCTION(BlueprintCallable)
	FVector GetTargetTransform();

	FTimerHandle CountdownTimerHandle;

	void AdvancedTimer();

	UFUNCTION(BlueprintNativeEvent)
		void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void StartMoveEvent();
	virtual void StartMoveEvent_Implementation();
};
