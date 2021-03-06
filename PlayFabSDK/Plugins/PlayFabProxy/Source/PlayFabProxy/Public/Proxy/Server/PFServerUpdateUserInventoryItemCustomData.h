// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdateUserInventoryItemCustomData.generated.h"

UCLASS(MinimalAPI)
class UPFServerUpdateUserInventoryItemCustomData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Updates the key-value pair data tagged to the specified item, which is read-only from the client.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Player Item Management")
        static UPFServerUpdateUserInventoryItemCustomData* UpdateUserInventoryItemCustomData(class APlayerController* PlayerController, const FBPServerUpdateUserInventoryItemDataRequest& InUpdateUserInventoryItemDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerUpdateUserInventoryItemDataRequest Request;
    PlayFab::UPlayFabServerAPI::FUpdateUserInventoryItemCustomDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result);
};
