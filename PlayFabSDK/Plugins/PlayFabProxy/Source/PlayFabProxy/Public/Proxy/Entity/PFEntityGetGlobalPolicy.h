// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityGetGlobalPolicy.generated.h"

UCLASS(MinimalAPI)
class UPFEntityGetGlobalPolicy : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPEntityGetGlobalPolicyResponseDelegate OnSuccess;

    // Gets the global title access policy 
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|Account Management")
        static UPFEntityGetGlobalPolicy* GetGlobalPolicy(class APlayerController* PlayerController);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    
    PlayFab::UPlayFabEntityAPI::FGetGlobalPolicyDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FGetGlobalPolicyResponse& Result);
};
