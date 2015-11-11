// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminAddUserVirtualCurrency.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminAddUserVirtualCurrency : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminModifyUserVirtualCurrencyResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminModifyUserVirtualCurrencyResultDelegate OnFailure;
	
	// Increments the specified virtual currency by the stated amount
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Item Management")
	static UPFAdminAddUserVirtualCurrency* AddUserVirtualCurrency(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InVirtualCurrency, const int32& InAmount);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FAddUserVirtualCurrencyRequest Request;

	PlayFab::UPlayFabAdminAPI::FAddUserVirtualCurrencyDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FModifyUserVirtualCurrencyResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
