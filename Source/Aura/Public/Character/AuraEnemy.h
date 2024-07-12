#pragma once

#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "CoreMinimal.h"
#include "AuraEnemy.generated.h"




UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy();

	// Enemy Interface //
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//End Enemy Interface//

	// COMBAT INTERFACE //

	virtual int32 GetPlayerLevel() override;

	// END COMBAT INTERFACE //


protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
