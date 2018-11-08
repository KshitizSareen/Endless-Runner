// Fill out your copyright notice in the Description page of Project Settings.

#include "Runner.h"
#include "MainGameMode.h"
#include "GameBlockController.h"
#include "GameWidget1.h"
void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(NewWidgetClass);
	((UGameWidget1*)CurrentWidget)->Load();

}

// Called every frame
void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 UWorld* const World = GetWorld();
	if (World)
	{
		FVector PlayerLocation = World->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
		((UGameWidget1*)CurrentWidget)->SetScore(FMath::Floor(PlayerLocation.Y / 100.0f),Health);
		while (PointScenarioBlocks < PlayerLocation.Y + FARTHEST_DISTANCE)
		{
			FVector Location = FVector(0.0f, PointScenarioBlocks, 0.0f);
			AGameBlockController* Block = World->SpawnActor<AGameBlockController>(GroundBlock, Location, FRotator::ZeroRotator);
			PointScenarioBlocks += Block->Size;
		}
		while (PointHazardBlocks < PlayerLocation.Y + FARTHEST_DISTANCE)
		{
			FVector Location = FVector(0.0f, PointHazardBlocks, 0.0f);
			AGameBlockController* Block = World->SpawnActor<AGameBlockController>(FMath::RandBool() ? HazardBlock1 : HazardBlock2, Location, FRotator::ZeroRotator);
			PointHazardBlocks += Block->Size;
		}
	}
}
void AMainGameMode::OnCollide()
{
	Health -= 10;
	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
	((UGameWidget1*)CurrentWidget)->OnCollide(FMath::Floor(PlayerLocation.Y / 100.0f),Health);
	if (Health <= 0)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		((UGameWidget1*)CurrentWidget)->OnGameOver(FMath::Floor(PlayerLocation.Y / 100.0f), Health);
	}
}
void AMainGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> StartingWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
