// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientAddUserVirtualCurrency.h"

UPFClientAddUserVirtualCurrency::UPFClientAddUserVirtualCurrency(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FAddUserVirtualCurrencyDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientAddUserVirtualCurrency* UPFClientAddUserVirtualCurrency::AddUserVirtualCurrency(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InVirtualCurrency, const int32& InAmount)
{
	UPFClientAddUserVirtualCurrency* Proxy = NewObject<UPFClientAddUserVirtualCurrency>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.VirtualCurrency = InVirtualCurrency;
	Proxy->Request.Amount = InAmount;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientAddUserVirtualCurrency::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->AddUserVirtualCurrency(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientModifyUserVirtualCurrencyResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientAddUserVirtualCurrency::OnSuccessCallback(const PlayFab::ClientModels::FModifyUserVirtualCurrencyResult& Result)
{
	FBPClientModifyUserVirtualCurrencyResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientAddUserVirtualCurrency::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientModifyUserVirtualCurrencyResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
