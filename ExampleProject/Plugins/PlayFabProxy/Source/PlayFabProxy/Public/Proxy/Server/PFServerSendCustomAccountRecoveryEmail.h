// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerSendCustomAccountRecoveryEmail.generated.h"

UCLASS(MinimalAPI)
class UPFServerSendCustomAccountRecoveryEmail : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Forces an email to be sent to the registered contact email address for the user's account based on an account recovery email template
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Account Management")
        static UPFServerSendCustomAccountRecoveryEmail* SendCustomAccountRecoveryEmail(class APlayerController* PlayerController, const FBPServerSendCustomAccountRecoveryEmailRequest& InSendCustomAccountRecoveryEmailRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerSendCustomAccountRecoveryEmailRequest Request;
    PlayFab::UPlayFabServerAPI::FSendCustomAccountRecoveryEmailDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FSendCustomAccountRecoveryEmailResult& Result);
};
