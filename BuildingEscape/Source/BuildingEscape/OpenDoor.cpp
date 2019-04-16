// Copyright Emile Blouin 2019


#include "OpenDoor.h"

#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// find the owning actor
	AActor* Owner = GetOwner();

	// create a rotator
	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);

	// set the door rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// poll the trigger volume every frame
	if (PrimaryTrigger->IsOverlappingActor(ActorThatOpens) && SecondaryTrigger->IsOverlappingActor(ActorThatOpens))// if the ActorThatOpens is in the volume
	{ 
		OpenDoor();
	}		
}

