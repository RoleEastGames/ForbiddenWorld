// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction.h"
#include "Rarity.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"

#include "Item.generated.h"

UCLASS()
class FORBIDDENWORLD_API AItem : public AActor, public IInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* _interactZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
		UTexture2D* _icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Parameters")
		FString _name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Parameters")
		FString _description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Parameters")
		URarity* _rarity;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BLueprintCallable)
		void interact() override;

	/// <summary>
	/// Геттеры и сеттеры
	/// </summary>
	UFUNCTION(BLueprintCallable)
		void SetIcon(UTexture2D* texture);
	UFUNCTION(BLueprintCallable)
		UTexture2D* GetIcon();

	UFUNCTION(BLueprintCallable)
		UStaticMeshComponent* GetMesh();

	UFUNCTION(BLueprintCallable)
		void SetName(FString name);
	UFUNCTION(BLueprintCallable)
		FString GetName();

	UFUNCTION(BLueprintCallable)
		void SetDescription(FString description);
	UFUNCTION(BLueprintCallable)
		FString GetDescription();
};
