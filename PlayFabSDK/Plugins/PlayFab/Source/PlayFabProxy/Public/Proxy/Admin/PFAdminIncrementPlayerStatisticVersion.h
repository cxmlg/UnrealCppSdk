// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminIncrementPlayerStatisticVersion.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminIncrementPlayerStatisticVersion : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminIncrementPlayerStatisticVersionResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminIncrementPlayerStatisticVersionResultDelegate OnFailure;
	
	// 
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Data Management")
	static UPFAdminIncrementPlayerStatisticVersion* IncrementPlayerStatisticVersion(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InStatisticName);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FIncrementPlayerStatisticVersionRequest Request;

	PlayFab::UPlayFabAdminAPI::FIncrementPlayerStatisticVersionDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FIncrementPlayerStatisticVersionResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
