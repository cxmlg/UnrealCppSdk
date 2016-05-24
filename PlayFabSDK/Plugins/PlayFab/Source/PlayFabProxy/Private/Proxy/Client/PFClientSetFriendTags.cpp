// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientSetFriendTags.h"

UPFClientSetFriendTags::UPFClientSetFriendTags(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FSetFriendTagsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientSetFriendTags* UPFClientSetFriendTags::SetFriendTags(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InFriendPlayFabId, const TArray<FString>& InTags)
{
	UPFClientSetFriendTags* Proxy = NewObject<UPFClientSetFriendTags>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.FriendPlayFabId = InFriendPlayFabId;
	Proxy->Request.Tags = InTags;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientSetFriendTags::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->SetFriendTags(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientSetFriendTags::OnSuccessCallback(const PlayFab::ClientModels::FSetFriendTagsResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientSetFriendTags::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
