// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class JUMPMAP_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed=60;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// 루트 컴포넌트를 나타내는 Scene Component 포인터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SceneRoot")
		USceneComponent * SceneRoot;
	// Static Mesh Component 포인터
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMeshComp")
	UStaticMeshComponent* StaticMeshComp;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
