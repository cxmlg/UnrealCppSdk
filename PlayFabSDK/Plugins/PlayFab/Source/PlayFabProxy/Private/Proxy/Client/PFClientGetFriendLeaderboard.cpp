// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetFriendLeaderboard.h"

UPFClientGetFriendLeaderboard::UPFClientGetFriendLeaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetFriendLeaderboardDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetFriendLeaderboard* UPFClientGetFriendLeaderboard::GetFriendLeaderboard(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName, const int32& InStartPosition, const int32& InMaxResultsCount, const bool& InIncludeSteamFriends, const bool& InIncludeFacebookFriends)
{
	UPFClientGetFriendLeaderboard* Proxy = NewObject<UPFClientGetFriendLeaderboard>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.StartPosition = InStartPosition;
	Proxy->Request.MaxResultsCount = InMaxResultsCount;
	Proxy->Request.IncludeSteamFriends = InIncludeSteamFriends;
	Proxy->Request.IncludeFacebookFriends = InIncludeFacebookFriends;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetFriendLeaderboard::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetFriendLeaderboard(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetLeaderboardResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetFriendLeaderboard::OnSuccessCallback(const PlayFab::ClientModels::FGetLeaderboardResult& Result)
{
	FBPClientGetLeaderboardResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetFriendLeaderboard::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetLeaderboardResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
