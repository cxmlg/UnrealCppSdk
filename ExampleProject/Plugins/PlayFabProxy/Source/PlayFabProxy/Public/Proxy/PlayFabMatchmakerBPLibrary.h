// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Core/PlayFabMatchmakerAPI.h"
#include "Core/PlayFabMatchmakerDataModels.h"
#include "PlayFabMatchmakerBPDataModels.h"
#include "PlayFabMatchmakerBPLibrary.generated.h"

UCLASS(MinimalAPI)
class UPFMatchmakerProxyLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    
    // AuthUserRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerAuthUserRequest MakeBPMatchmakerAuthUserRequest(
    FString InAuthorizationTicket
);

    // AuthUserResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerAuthUserResponse(
    const FBPMatchmakerAuthUserResponse& In
	, bool& OutAuthorized
	, FString& OutPlayFabId
);

    // DeregisterGameRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerDeregisterGameRequest MakeBPMatchmakerDeregisterGameRequest(
    FString InLobbyId
);

    // DeregisterGameResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerDeregisterGameResponse(
    const FBPMatchmakerDeregisterGameResponse& In
);

    // ItemInstance
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerItemInstance MakeBPMatchmakerItemInstance(
    FString InAnnotation
	, TArray<FString> InBundleContents
	, FString InBundleParent
	, FString InCatalogVersion
	, TMap<FString, FString> InCustomData
	, FString InDisplayName
	, FDateTime InExpiration
	, FString InItemClass
	, FString InItemId
	, FString InItemInstanceId
	, FDateTime InPurchaseDate
	, int32 InRemainingUses
	, FString InUnitCurrency
	, int32 InUnitPrice
	, int32 InUsesIncrementedBy
);
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerItemInstance(
    const FBPMatchmakerItemInstance& In
	, FString& OutAnnotation
	, TArray<FString>& OutBundleContents
	, FString& OutBundleParent
	, FString& OutCatalogVersion
	, TMap<FString, FString>& OutCustomData
	, FString& OutDisplayName
	, FDateTime& OutExpiration
	, FString& OutItemClass
	, FString& OutItemId
	, FString& OutItemInstanceId
	, FDateTime& OutPurchaseDate
	, int32& OutRemainingUses
	, FString& OutUnitCurrency
	, int32& OutUnitPrice
	, int32& OutUsesIncrementedBy
);

    // PlayerJoinedRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerPlayerJoinedRequest MakeBPMatchmakerPlayerJoinedRequest(
    FString InLobbyId
	, FString InPlayFabId
);

    // PlayerJoinedResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerPlayerJoinedResponse(
    const FBPMatchmakerPlayerJoinedResponse& In
);

    // PlayerLeftRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerPlayerLeftRequest MakeBPMatchmakerPlayerLeftRequest(
    FString InLobbyId
	, FString InPlayFabId
);

    // PlayerLeftResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerPlayerLeftResponse(
    const FBPMatchmakerPlayerLeftResponse& In
);

    // RegisterGameRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerRegisterGameRequest MakeBPMatchmakerRegisterGameRequest(
    FString InBuild
	, FString InGameMode
	, FString InLobbyId
	, EBPMatchmakerRegion InRegion
	, FString InServerHost
	, FString InServerPort
	, TMap<FString, FString> InTags
);

    // RegisterGameResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerRegisterGameResponse(
    const FBPMatchmakerRegisterGameResponse& In
	, FString& OutLobbyId
);

    // StartGameRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerStartGameRequest MakeBPMatchmakerStartGameRequest(
    FString InBuild
	, FString InCustomCommandLineData
	, FString InExternalMatchmakerEventEndpoint
	, FString InGameMode
	, EBPMatchmakerRegion InRegion
);

    // StartGameResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerStartGameResponse(
    const FBPMatchmakerStartGameResponse& In
	, FString& OutGameID
	, FString& OutServerHostname
	, int32& OutServerPort
);

    // UserInfoRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerUserInfoRequest MakeBPMatchmakerUserInfoRequest(
    int32 InMinCatalogVersion
	, FString InPlayFabId
);

    // UserInfoResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerUserInfoResponse(
    const FBPMatchmakerUserInfoResponse& In
	, TArray<FBPMatchmakerItemInstance>& OutInventory
	, bool& OutIsDeveloper
	, FString& OutPlayFabId
	, FString& OutSteamId
	, FString& OutTitleDisplayName
	, FString& OutUsername
	, TMap<FString, int32>& OutVirtualCurrency
	, TMap<FString, FBPMatchmakerVirtualCurrencyRechargeTime>& OutVirtualCurrencyRechargeTimes
);

    // VirtualCurrencyRechargeTime
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeMakeFunc))
    static FBPMatchmakerVirtualCurrencyRechargeTime MakeBPMatchmakerVirtualCurrencyRechargeTime(
    int32 InRechargeMax
	, FDateTime InRechargeTime
	, int32 InSecondsToRecharge
);
    UFUNCTION(BlueprintPure, Category = "PlayFab|Matchmaker", meta = (NativeBreakFunc))
    static void BreakBPMatchmakerVirtualCurrencyRechargeTime(
    const FBPMatchmakerVirtualCurrencyRechargeTime& In
	, int32& OutRechargeMax
	, FDateTime& OutRechargeTime
	, int32& OutSecondsToRecharge
);

};