// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientUpdateSharedGroupData.h"

UPFClientUpdateSharedGroupData::UPFClientUpdateSharedGroupData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdateSharedGroupDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUpdateSharedGroupData* UPFClientUpdateSharedGroupData::UpdateSharedGroupData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InSharedGroupId, const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFClientUpdateSharedGroupData* Proxy = NewObject<UPFClientUpdateSharedGroupData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.SharedGroupId = InSharedGroupId;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUpdateSharedGroupData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UpdateSharedGroupData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUpdateSharedGroupData::OnSuccessCallback(const PlayFab::ClientModels::FUpdateSharedGroupDataResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientUpdateSharedGroupData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}