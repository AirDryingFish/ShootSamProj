// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();
	
	// PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// if (PlayerPawn)
	// {
	// 	SetFocus(PlayerPawn);
	// }
	

}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// if (PlayerPawn)
	// {
	// 	if (LineOfSightTo(PlayerPawn))
	// 	{
	// 		SetFocus(PlayerPawn);
	// 		MoveToActor(PlayerPawn, 200.0f);
	// 	}
	// 	else
	// 	{
	// 		ClearFocus(EAIFocusPriority::Gameplay);
	// 		StopMovement();
	// 	}
	// }
	
}

void AShooterAI::StartBehaviorTree(AShooterSamCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<AShooterSamCharacter>(GetPawn());
		if (Player)
		{
			PlayerCharacter = Player;
		}
		RunBehaviorTree(EnemyAIBehaviorTree);
		
		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		if (MyBlackboard)
		{
			MyBlackboard->SetValueAsVector("PlayerLocation", PlayerCharacter->GetActorLocation());
			MyBlackboard->SetValueAsVector("StartLocation", MyCharacter->GetActorLocation());
		}
	}
}
