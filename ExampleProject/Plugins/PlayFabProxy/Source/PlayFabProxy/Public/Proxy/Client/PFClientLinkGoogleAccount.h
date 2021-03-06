// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLinkGoogleAccount.generated.h"

UCLASS(MinimalAPI)
class UPFClientLinkGoogleAccount : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Links the currently signed-in user account to their Google account, using their Google account credentials
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientLinkGoogleAccount* LinkGoogleAccount(class APlayerController* PlayerController, const FBPClientLinkGoogleAccountRequest& InLinkGoogleAccountRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLinkGoogleAccountRequest Request;
    PlayFab::UPlayFabClientAPI::FLinkGoogleAccountDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLinkGoogleAccountResult& Result);
};
