// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminRemovePlayerTag.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminRemovePlayerTag : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Remove a given tag from a player profile. The tag's namespace is automatically generated based on the source of the tag.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|PlayStream")
	static UPFAdminRemovePlayerTag* RemovePlayerTag(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InTagName);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FRemovePlayerTagRequest Request;

	PlayFab::UPlayFabAdminAPI::FRemovePlayerTagDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FRemovePlayerTagResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
