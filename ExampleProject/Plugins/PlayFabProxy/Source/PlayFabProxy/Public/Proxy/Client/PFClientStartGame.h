// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientStartGame.generated.h"

UCLASS(MinimalAPI)
class UPFClientStartGame : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientStartGameResultDelegate OnSuccess;

    // Start a new game server with a given configuration, add the current player and return the connection information.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Matchmaking")
        static UPFClientStartGame* StartGame(class APlayerController* PlayerController, const FBPClientStartGameRequest& InStartGameRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientStartGameRequest Request;
    PlayFab::UPlayFabClientAPI::FStartGameDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FStartGameResult& Result);
};
