// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminSetupPushNotification.generated.h"

UCLASS(MinimalAPI)
class UPFAdminSetupPushNotification : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminSetupPushNotificationResultDelegate OnSuccess;

    // Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device Messaging is not supported.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Title-Wide Data Management")
        static UPFAdminSetupPushNotification* SetupPushNotification(class APlayerController* PlayerController, const FBPAdminSetupPushNotificationRequest& InSetupPushNotificationRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminSetupPushNotificationRequest Request;
    PlayFab::UPlayFabAdminAPI::FSetupPushNotificationDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FSetupPushNotificationResult& Result);
};
