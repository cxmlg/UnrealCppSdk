// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminCreatePlayerStatisticDefinition.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminCreatePlayerStatisticDefinition : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminCreatePlayerStatisticDefinitionResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminCreatePlayerStatisticDefinitionResultDelegate OnFailure;
	
	// 
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Data Management")
	static UPFAdminCreatePlayerStatisticDefinition* CreatePlayerStatisticDefinition(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InName);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FCreatePlayerStatisticDefinitionRequest Request;

	PlayFab::UPlayFabAdminAPI::FCreatePlayerStatisticDefinitionDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FCreatePlayerStatisticDefinitionResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
