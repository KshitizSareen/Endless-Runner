// Fill out your copyright notice in the Description page of Project Settings.

#include "Runner.h"
#include "GameWidget1.h"

void UGameWidget1::Load()
{
	const FName TextBlockName = FName("ScoreTextBlock");
	if (ScoreText == nullptr)
		ScoreText = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
	SetScore(0,100);
}
void UGameWidget1::SetScore(int Score,int Health)
{
	if (ScoreText != nullptr)
		ScoreText->SetText(FText::FromString(FString(TEXT("Score :")) + FString::FromInt(Score)+ FString(TEXT(" Health  :"))+FString::FromInt(Health)));
}
void UGameWidget1::OnCollide(int Score,int Health)
{
	if (ScoreText != nullptr)
		ScoreText->SetText(FText::FromString(FString(TEXT("Score :")) + FString::FromInt(Score) + FString(TEXT(" Health  :")) + FString::FromInt(Health)));
}
void UGameWidget1::OnGameOver(int Score, int Health)
{
	if (ScoreText != nullptr)
		ScoreText->SetText(FText::FromString(FString(TEXT("GameOver Press R To Restart"))));
}




