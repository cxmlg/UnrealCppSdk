// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientAddFriend.h"

UPFClientAddFriend::UPFClientAddFriend(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FAddFriendDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientAddFriend* UPFClientAddFriend::AddFriend(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InFriendPlayFabId, const FString& InFriendUsername, const FString& InFriendEmail, const FString& InFriendTitleDisplayName)
{
	UPFClientAddFriend* Proxy = NewObject<UPFClientAddFriend>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.FriendPlayFabId = InFriendPlayFabId;
	Proxy->Request.FriendUsername = InFriendUsername;
	Proxy->Request.FriendEmail = InFriendEmail;
	Proxy->Request.FriendTitleDisplayName = InFriendTitleDisplayName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientAddFriend::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->AddFriend(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientAddFriendResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientAddFriend::OnSuccessCallback(const PlayFab::ClientModels::FAddFriendResult& Result)
{
	FBPClientAddFriendResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientAddFriend::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientAddFriendResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
