// Fill out your copyright notice in the Description page of Project Settings.

#include "Runner.h"
#include "GameBlockController.h"


// Sets default values
AGameBlockController::AGameBlockController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameBlockController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameBlockController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

