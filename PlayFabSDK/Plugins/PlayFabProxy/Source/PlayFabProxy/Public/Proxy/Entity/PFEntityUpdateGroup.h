// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityUpdateGroup.generated.h"

UCLASS(MinimalAPI)
class UPFEntityUpdateGroup : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPEntityUpdateGroupResponseDelegate OnSuccess;

    // Updates non-membership data about a group.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|Groups")
        static UPFEntityUpdateGroup* UpdateGroup(class APlayerController* PlayerController, const FBPEntityUpdateGroupRequest& InUpdateGroupRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPEntityUpdateGroupRequest Request;
    PlayFab::UPlayFabEntityAPI::FUpdateGroupDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FUpdateGroupResponse& Result);
};
