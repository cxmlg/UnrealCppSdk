// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminSetPublishedRevision.generated.h"

UCLASS(MinimalAPI)
class UPFAdminSetPublishedRevision : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Sets the currently published revision of a title Cloud Script
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Server-Side Cloud Script")
        static UPFAdminSetPublishedRevision* SetPublishedRevision(class APlayerController* PlayerController, const FBPAdminSetPublishedRevisionRequest& InSetPublishedRevisionRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminSetPublishedRevisionRequest Request;
    PlayFab::UPlayFabAdminAPI::FSetPublishedRevisionDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FSetPublishedRevisionResult& Result);
};
