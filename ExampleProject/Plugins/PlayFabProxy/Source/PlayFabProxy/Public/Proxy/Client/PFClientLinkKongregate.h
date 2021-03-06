// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLinkKongregate.generated.h"

UCLASS(MinimalAPI)
class UPFClientLinkKongregate : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Links the Kongregate identifier to the user's PlayFab account
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientLinkKongregate* LinkKongregate(class APlayerController* PlayerController, const FBPClientLinkKongregateAccountRequest& InLinkKongregateAccountRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLinkKongregateAccountRequest Request;
    PlayFab::UPlayFabClientAPI::FLinkKongregateDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLinkKongregateAccountResult& Result);
};
