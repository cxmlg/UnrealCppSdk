// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientRemoveSharedGroupMembers.h"

UPFClientRemoveSharedGroupMembers::UPFClientRemoveSharedGroupMembers(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FRemoveSharedGroupMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientRemoveSharedGroupMembers* UPFClientRemoveSharedGroupMembers::RemoveSharedGroupMembers(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InSharedGroupId, const TArray<FString>& InPlayFabIds)
{
	UPFClientRemoveSharedGroupMembers* Proxy = NewObject<UPFClientRemoveSharedGroupMembers>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.SharedGroupId = InSharedGroupId;
	Proxy->Request.PlayFabIds = InPlayFabIds;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientRemoveSharedGroupMembers::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->RemoveSharedGroupMembers(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientRemoveSharedGroupMembers::OnSuccessCallback(const PlayFab::ClientModels::FRemoveSharedGroupMembersResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientRemoveSharedGroupMembers::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}