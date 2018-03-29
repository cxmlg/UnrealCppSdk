// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerDeleteSharedGroup.generated.h"

UCLASS(MinimalAPI)
class UPFServerDeleteSharedGroup : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Deletes a shared group, freeing up the shared group ID to be reused for a new group. Shared Groups are designed for sharing data between a very small number of players, please see our guide: https://api.playfab.com/docs/tutorials/landing-players/shared-groups
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Shared Group Data")
        static UPFServerDeleteSharedGroup* DeleteSharedGroup(class APlayerController* PlayerController, const FBPServerDeleteSharedGroupRequest& InDeleteSharedGroupRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerDeleteSharedGroupRequest Request;
    PlayFab::UPlayFabServerAPI::FDeleteSharedGroupDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result);
};
