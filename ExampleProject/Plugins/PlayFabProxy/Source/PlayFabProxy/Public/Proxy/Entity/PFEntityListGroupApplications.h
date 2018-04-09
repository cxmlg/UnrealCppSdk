// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityListGroupApplications.generated.h"

UCLASS(MinimalAPI)
class UPFEntityListGroupApplications : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPEntityListGroupApplicationsResponseDelegate OnSuccess;

    // Lists all outstanding requests to join a group
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|Groups")
        static UPFEntityListGroupApplications* ListGroupApplications(class APlayerController* PlayerController, const FBPEntityListGroupApplicationsRequest& InListGroupApplicationsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPEntityListGroupApplicationsRequest Request;
    PlayFab::UPlayFabEntityAPI::FListGroupApplicationsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FListGroupApplicationsResponse& Result);
};