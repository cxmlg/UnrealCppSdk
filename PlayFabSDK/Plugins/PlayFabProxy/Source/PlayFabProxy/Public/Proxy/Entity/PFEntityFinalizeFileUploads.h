// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityFinalizeFileUploads.generated.h"

UCLASS(MinimalAPI)
class UPFEntityFinalizeFileUploads : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPEntityFinalizeFileUploadsResponseDelegate OnSuccess;

    // Finalize file uploads to an entity's profile.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|File")
        static UPFEntityFinalizeFileUploads* FinalizeFileUploads(class APlayerController* PlayerController, const FBPEntityFinalizeFileUploadsRequest& InFinalizeFileUploadsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPEntityFinalizeFileUploadsRequest Request;
    PlayFab::UPlayFabEntityAPI::FFinalizeFileUploadsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FFinalizeFileUploadsResponse& Result);
};