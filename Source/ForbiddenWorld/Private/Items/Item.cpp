// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_interactZone = CreateDefaultSubobject<USphereComponent>(TEXT("InteractZone"));
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = _mesh;
	_interactZone->SetupAttachment(RootComponent);

	_mesh->SetCollisionProfileName(TEXT("IgnoreOnlyPawn"));

	_interactZone->SetCollisionProfileName(TEXT("Trigger"));
	_interactZone->SetWorldScale3D(FVector(1.5f));

	_interactZone->OnComponentBeginOverlap.AddDynamic(this, &AItem::BeginOverlap);
	_interactZone->OnComponentEndOverlap.AddDynamic(this, &AItem::EndOverlap);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

void AItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Actor on item!"));
}

void AItem::EndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Actor leave zone of item!"));
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::interact()
{

}

// Геттеры и сеттеры
UStaticMeshComponent* AItem::GetMesh()
{
	return _mesh;
}

//
UTexture2D* AItem::GetIcon()
{
	return _icon;
}

void AItem::SetIcon(UTexture2D* icon)
{
	_icon = icon;
}

//
FString AItem::GetName()
{
	return _name;
}

void AItem::SetName(FString name)
{
	_name = name;
}

//
FString AItem::GetDescription()
{
	return _description;
}

void AItem::SetDescription(FString description)
{
	_description = description;
}

