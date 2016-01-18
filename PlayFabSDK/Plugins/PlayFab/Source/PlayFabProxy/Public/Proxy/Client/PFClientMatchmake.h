// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientMatchmake.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientMatchmake : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientMatchmakeResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientMatchmakeResultDelegate OnFailure;
	
	// Attempts to locate a game session matching the given parameters. If the goal is to match the player into a specific active session, only the LobbyId is required. Otherwise, the BuildVersion, GameMode, and Region are all required parameters. Note that parameters specified in the search are required (they are not weighting factors). If a slot is found in a server instance matching the parameters, the slot will be assigned to that player, removing it from the availabe set. In that case, the information on the game session will be returned, otherwise the Status returned will be GameNotFound. Note that EnableQueue is deprecated at this time.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Matchmaking APIs")
	static UPFClientMatchmake* Matchmake(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InBuildVersion, const FString& InGameMode, const FString& InLobbyId, const FString& InStatisticName, const FString& InCharacterId, const bool& InEnableQueue);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FMatchmakeRequest Request;

	PlayFab::UPlayFabClientAPI::FMatchmakeDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FMatchmakeResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};