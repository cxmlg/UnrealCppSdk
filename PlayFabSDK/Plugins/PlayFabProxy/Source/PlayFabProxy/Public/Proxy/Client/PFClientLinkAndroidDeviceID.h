// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLinkAndroidDeviceID.generated.h"

UCLASS(MinimalAPI)
class UPFClientLinkAndroidDeviceID : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Links the Android device identifier to the user's PlayFab account
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientLinkAndroidDeviceID* LinkAndroidDeviceID(class APlayerController* PlayerController, const FBPClientLinkAndroidDeviceIDRequest& InLinkAndroidDeviceIDRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLinkAndroidDeviceIDRequest Request;
    PlayFab::UPlayFabClientAPI::FLinkAndroidDeviceIDDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLinkAndroidDeviceIDResult& Result);
};