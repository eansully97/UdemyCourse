// Ean

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/CharacterClassInfo.h"
#include "AuraAbilitySystemBPLibrary.generated.h"

struct FDamageEffectParams;
class UAbilityInfo;
class UAbilitySystemComponent;
class UAttributeMenuWidgetController;
class UOverlayWidgetController;
class USpellMenuWidgetController;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|WidgetController")
	static bool MakeWidgetControllerParams(const UObject* WorldContextObject, FWidgetControllerParams& OutWCParams, AAuraHUD*& OutAuraHUD);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|WidgetController")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|WidgetController")
	static USpellMenuWidgetController* GetSpellMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|CharacterClassDefaults")
	static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC, ECharacterClass CharacterClass);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|CharacterClassDefaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|CharacterClassDefaults")
	static UAbilityInfo* GetAbilityInfo(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static bool IsSuccessfulDebuff(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static float GetDebuffDamage(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static float GetDebuffDuration(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static float GetDebuffFrequency(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static FGameplayTag GetDamageType(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static FVector GetDeathImpulse(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static FVector GetKnockbackForce(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetIsBlockedHit(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInIsBlockedHit);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetIsCriticalHit(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInIsCriticalHit);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetIsSuccessfulDebuff(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInSuccessfulDebuff);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetDebuffDamage(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, float InDamage);
	
	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetDebuffDuration(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, float InDuration);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetDebuffFrequency(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, float InFrequency);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetDamageType(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, const FGameplayTag& InDamageType);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetDeathImpulse(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, const FVector& InImpulse);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayEffects")
	static void SetKnockbackForce(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, const FVector& InForce);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|GameplayMechanics")
	static void GetLivePlayersWithinRadius(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappingActors, const TArray<AActor*>& ActorsToIgnore, float Radius, const FVector& SphereOrigin);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemBPLibrary|GameplayMechanics")
	static bool IsNotFriend(AActor* FirstActor, AActor* SecondActor);

	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemBPLibrary|DamageEffect")
	static FGameplayEffectContextHandle ApplyDamageEffect(const FDamageEffectParams& DamageEffectParams);

	static int32 GetXPRewardForClassAndLevel(const UObject* WorldContextObject, ECharacterClass CharacterClass, int32 CharacterLevel);
	
};


