// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"

#include "ShooterAI.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update PlayerLocation If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaTime)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaTime);
	UE_LOG(LogTemp, Display, TEXT("Node is ticking"));
	
	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());
	if (OwnerController)
	{
		AShooterSamCharacter* PlayerCharacter = OwnerController->PlayerCharacter;
		UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();
		if (PlayerCharacter && Blackboard)
		{
			if (OwnerController->LineOfSightTo(PlayerCharacter))
			{
				Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), PlayerCharacter->GetActorLocation());
				OwnerController->SetFocus(PlayerCharacter);
			}
			else
			{
				Blackboard->ClearValue(GetSelectedBlackboardKey());
				OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
			}
		}
	}
}
