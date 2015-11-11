// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientPurchaseItem.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientPurchaseItem : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientPurchaseItemResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientPurchaseItemResultDelegate OnFailure;
	
	// Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase, as well as what the client believes the price to be. This lets the server fail the purchase if the price has changed.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Player Item Management")
	static UPFClientPurchaseItem* PurchaseItem(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InItemId, const FString& InVirtualCurrency, const int32& InPrice, const FString& InCatalogVersion, const FString& InStoreId, const FString& InCharacterId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FPurchaseItemRequest Request;

	PlayFab::UPlayFabClientAPI::FPurchaseItemDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FPurchaseItemResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
