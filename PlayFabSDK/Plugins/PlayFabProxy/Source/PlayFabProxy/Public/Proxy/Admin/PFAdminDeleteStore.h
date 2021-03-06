// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminDeleteStore.generated.h"

UCLASS(MinimalAPI)
class UPFAdminDeleteStore : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Deletes an existing virtual item store
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Title-Wide Data Management")
        static UPFAdminDeleteStore* DeleteStore(class APlayerController* PlayerController, const FBPAdminDeleteStoreRequest& InDeleteStoreRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminDeleteStoreRequest Request;
    PlayFab::UPlayFabAdminAPI::FDeleteStoreDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FDeleteStoreResult& Result);
};
