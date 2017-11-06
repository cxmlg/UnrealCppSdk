// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetPlayerIdFromAuthToken.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetPlayerIdFromAuthToken : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetPlayerIdFromAuthTokenResultDelegate OnSuccess;

    // Gets a player's ID from an auth token.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Account Management")
        static UPFAdminGetPlayerIdFromAuthToken* GetPlayerIdFromAuthToken(class APlayerController* PlayerController, const FBPAdminGetPlayerIdFromAuthTokenRequest& InGetPlayerIdFromAuthTokenRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetPlayerIdFromAuthTokenRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetPlayerIdFromAuthTokenDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerIdFromAuthTokenResult& Result);
};
