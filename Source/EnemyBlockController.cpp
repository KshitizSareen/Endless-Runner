// Fill out your copyright notice in the Description page of Project Settings.

#include "Runner.h"
#include "EnemyBlockController.h"
#include "RunnerCharacter.h"
#include "MainGameMode.h"


// Sets default values
AEnemyBlockController::AEnemyBlockController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RootBox"));
	CollisionBox->bGenerateOverlapEvents = true;
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBlockController::OnOverlap);
	RootComponent = CollisionBox;

}

// Called when the game starts or when spawned
void AEnemyBlockController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBlockController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void AEnemyBlockController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ARunnerCharacter::StaticClass()))
	{
		((AMainGameMode*)GetWorld()->GetAuthGameMode())->OnCollide();
	}
}
