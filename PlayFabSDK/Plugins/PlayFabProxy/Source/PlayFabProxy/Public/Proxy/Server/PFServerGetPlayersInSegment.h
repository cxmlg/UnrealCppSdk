// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetPlayersInSegment.generated.h"

UCLASS(MinimalAPI)
class UPFServerGetPlayersInSegment : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerGetPlayersInSegmentResultDelegate OnSuccess;

    // Allows for paging through all players in a given segment. This API creates a snapshot of all player profiles that match the segment definition at the time of its creation and lives through the Total Seconds to Live, refreshing its life span on each subsequent use of the Continuation Token. Profiles that change during the course of paging will not be reflected in the results. AB Test segments are currently not supported by this operation.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|PlayStream")
        static UPFServerGetPlayersInSegment* GetPlayersInSegment(class APlayerController* PlayerController, const FBPServerGetPlayersInSegmentRequest& InGetPlayersInSegmentRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerGetPlayersInSegmentRequest Request;
    PlayFab::UPlayFabServerAPI::FGetPlayersInSegmentDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FGetPlayersInSegmentResult& Result);
};
