// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientAddSharedGroupMembers.h"

UPFClientAddSharedGroupMembers::UPFClientAddSharedGroupMembers(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FAddSharedGroupMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientAddSharedGroupMembers* UPFClientAddSharedGroupMembers::AddSharedGroupMembers(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InSharedGroupId, const TArray<FString>& InPlayFabIds)
{
	UPFClientAddSharedGroupMembers* Proxy = NewObject<UPFClientAddSharedGroupMembers>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.SharedGroupId = InSharedGroupId;
	Proxy->Request.PlayFabIds = InPlayFabIds;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientAddSharedGroupMembers::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->AddSharedGroupMembers(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientAddSharedGroupMembers::OnSuccessCallback(const PlayFab::ClientModels::FAddSharedGroupMembersResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientAddSharedGroupMembers::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
