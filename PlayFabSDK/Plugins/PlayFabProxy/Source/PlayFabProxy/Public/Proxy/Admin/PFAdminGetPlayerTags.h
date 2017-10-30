// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetPlayerTags.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetPlayerTags : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetPlayerTagsResultDelegate OnSuccess;

    // Get all tags with a given Namespace (optional) from a player profile.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|PlayStream")
        static UPFAdminGetPlayerTags* GetPlayerTags(class APlayerController* PlayerController, const FBPAdminGetPlayerTagsRequest& InGetPlayerTagsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetPlayerTagsRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetPlayerTagsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerTagsResult& Result);
};