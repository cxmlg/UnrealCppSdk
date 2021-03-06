// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLinkSteamAccount.generated.h"

UCLASS(MinimalAPI)
class UPFClientLinkSteamAccount : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab account
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientLinkSteamAccount* LinkSteamAccount(class APlayerController* PlayerController, const FBPClientLinkSteamAccountRequest& InLinkSteamAccountRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLinkSteamAccountRequest Request;
    PlayFab::UPlayFabClientAPI::FLinkSteamAccountDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLinkSteamAccountResult& Result);
};
