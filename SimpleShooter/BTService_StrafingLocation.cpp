// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_StrafingLocation.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_StrafingLocation::UBTService_StrafingLocation()
{
	NodeName = TEXT("Update Stafe Location");
}

void UBTService_StrafingLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr)
	{
		return;
	}

	APawn* AIPawn = AIController->GetPawn();
	if (AIPawn == nullptr)
	{
		return;
	}

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (BlackboardComponent == nullptr)
	{
		return;
	}

	FVector StrafeVector = FVector(FMath::FRandRange(-StrafeRange, StrafeRange), FMath::FRandRange(-StrafeRange, StrafeRange), 0);
	BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), AIPawn->GetActorLocation() + StrafeVector);
}
