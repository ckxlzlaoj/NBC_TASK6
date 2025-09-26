// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_Platform.h"
#include "TimerManager.h"

// Sets default values
AMove_Platform::AMove_Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);  //SceneRoot에 붙이겠다

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/VREditor/BasicMeshes/SM_Cube_02.SM_Cube_02'"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Script/Engine.MaterialInstanceConstant'/Engine/VREditor/BasicMeshes/MI_Cube_03.MI_Cube_03'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	

}

// Called when the game starts or when spawned
void AMove_Platform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
	
}




// Called every frame
void AMove_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		if (FVector::Dist(StartLocation, GetActorLocation()) >= MaxRange)
		{
			MoveSpeed *= -1;
			AddActorLocalOffset(FVector(0.0f, MoveSpeed * (DeltaTime+0.1), 0.0f));
		}
	}

	AddActorLocalOffset(FVector(0.0f, MoveSpeed* DeltaTime, 0.0f));
}

