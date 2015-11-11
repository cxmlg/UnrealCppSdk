// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerGetLeaderboardForUserCharacters.h"

UPFServerGetLeaderboardForUserCharacters::UPFServerGetLeaderboardForUserCharacters(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetLeaderboardForUserCharactersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetLeaderboardForUserCharacters* UPFServerGetLeaderboardForUserCharacters::GetLeaderboardForUserCharacters(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName, const FString& InPlayFabId, const int32& InMaxResultsCount)
{
	UPFServerGetLeaderboardForUserCharacters* Proxy = NewObject<UPFServerGetLeaderboardForUserCharacters>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.MaxResultsCount = InMaxResultsCount;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetLeaderboardForUserCharacters::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetLeaderboardForUserCharacters(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetLeaderboardForUsersCharactersResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetLeaderboardForUserCharacters::OnSuccessCallback(const PlayFab::ServerModels::FGetLeaderboardForUsersCharactersResult& Result)
{
	FBPServerGetLeaderboardForUsersCharactersResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetLeaderboardForUserCharacters::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetLeaderboardForUsersCharactersResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
