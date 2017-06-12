// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetCurrentGames.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientGetCurrentGames : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientCurrentGamesResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientCurrentGamesResultDelegate OnFailure;
	
	// Get details about all current running game servers matching the given parameters.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Matchmaking")
	static UPFClientGetCurrentGames* GetCurrentGames(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InBuildVersion, const FString& InGameMode, const FString& InStatisticName, const FBPClientCollectionFilter& InTagFilter);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FCurrentGamesRequest Request;

	PlayFab::UPlayFabClientAPI::FGetCurrentGamesDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FCurrentGamesResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
