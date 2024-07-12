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

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;


private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Level = 1;
};
