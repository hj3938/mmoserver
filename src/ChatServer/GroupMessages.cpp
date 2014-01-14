/*
This source file is part of swgANH (Star Wars Galaxies - A New Hope - Server Emulator)
For more information, see http://www.swganh.org


Copyright (c) 2006 - 2010 The swgANH Team

---------------------------------------------------------------------------------------
*/

#include "ChatMessageLib.h"
#include "ChatOpcodes.h"
#include "Player.h"

#include "Common/atMacroString.h"
#include "Common/DispatchClient.h"
#include "Common/Message.h"
#include "Common/MessageDispatch.h"
#include "Common/MessageFactory.h"

void ChatMessageLib::sendIsmInviteRequest(Player* sender, Player* target) const
{
	// lets tell the zone to pop the invite window
	Message* newMessage;

	gMessageFactory->StartMessage();
	gMessageFactory->addUint32(opIsmGroupInviteRequest);
	gMessageFactory->addUint32(sender->getClient()->getAccountId());  // the sender's id
	gMessageFactory->addUint32(target->getClient()->getAccountId()); // the reciever account id
	gMessageFactory->addUint64(sender->getGroupId()); // the group id
	newMessage = gMessageFactory->EndMessage();

	target->getClient()->SendChannelA(newMessage,target->getClient()->getAccountId(),static_cast<uint8>(target->getPlanetId())+8, 3);
}

//======================================================================================================================

void ChatMessageLib::sendIsmGroupLootModeResponse(Player* target) const
{
	// lets tell the zone to pop the invite window
	Message* newMessage;
	gMessageFactory->StartMessage();
	gMessageFactory->addUint32(opIsmGroupLootModeResponse);
	gMessageFactory->addUint32(target->getClient()->getAccountId());  // the sender's id
	newMessage = gMessageFactory->EndMessage();
	target->getClient()->SendChannelA(newMessage,target->getClient()->getAccountId(),static_cast<uint8>(target->getPlanetId())+8, 3);
}

//======================================================================================================================

void ChatMessageLib::sendIsmGroupLootMasterResponse(Player* target) const
{
	// lets tell the zone to pop the invite window
	Message* newMessage;
	gMessageFactory->StartMessage();
	gMessageFactory->addUint32(opIsmGroupLootMasterResponse);
	gMessageFactory->addUint32(target->getClient()->getAccountId());  // the sender's id
	newMessage = gMessageFactory->EndMessage();
	target->getClient()->SendChannelA(newMessage,target->getClient()->getAccountId(),static_cast<uint8>(target->getPlanetId())+8, 3);
}

//======================================================================================================================

void ChatMessageLib::sendIsmGroupCREO6deltaGroupId(uint64 groupId, Player* target) const
{
	if(!target)
		return;
	// lets tell the zone to advise in-range players
	Message* newMessage;

	gMessageFactory->StartMessage();
	gMessageFactory->addUint32(opIsmGroupCREO6deltaGroupId);
	gMessageFactory->addUint32(target->getClient()->getAccountId());  // the sender's id
	gMessageFactory->addUint64(groupId); // the new group id
	newMessage = gMessageFactory->EndMessage();
	
	target->getClient()->SendChannelA(newMessage,target->getClient()->getAccountId(),static_cast<uint8>(target->getPlanetId())+8, 3);
}

//======================================================================================================================

void ChatMessageLib::sendIsmInviteInRangeRequest(Player* sender, Player* target)
{
	Message* newMessage;
	gMessageFactory->StartMessage();
	gMessageFactory->addUint32(opIsmGroupInviteInRangeRequest);
	gMessageFactory->addUint32(sender->getClient()->getAccountId());
	gMessageFactory->addUint32(target->getClient()->getAccountId());
	newMessage = gMessageFactory->EndMessage();

	sender->getClient()->SendChannelA(newMessage, sender->getClient()->getAccountId(), static_cast<uint8>(sender->getPlanetId())+8, 3);
}

//======================================================================================================================