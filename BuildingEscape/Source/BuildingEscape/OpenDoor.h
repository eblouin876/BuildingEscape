// Copyright Emile Blouin 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float OpenAngle = 0.f;
	float ClosedAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PrimaryTrigger;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* SecondaryTrigger;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = .5f;

	float LastDoorOpenTime;

	AActor* ActorThatOpens; // Pawn inherits from actor
	AActor* Owner;

};
