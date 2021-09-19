/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex 6
 * File description:	player brain factory XD
 * 			creates brain according to player's role
 ****************************************/

#include "PlayerFactory.h"

#include <stddef.h>

#include "DefenderBrain.h"
#include "enumPlayerRole.h"
#include "GoalieBrain.h"
#include "RoboPlayer.h"
#include "StrikerBrain.h"

PlayerFactory::PlayerFactory() {}
PlayerFactory::~PlayerFactory() {}

/*************************************************************************
* Function name:	PlayerFactory::getBrain
* The Input:		player to create brain to
* The Output:		brain according to player
* The Function operation: creates brain to the player
*************************************************************************/
PlayerBrain* PlayerFactory::getBrain(RoboPlayer& player) {
	switch (player.getRole())
	{
	case goalie:
		return new GoalieBrain(player);
		break;
	case activeStriker:
		return new StrikerBrain(player, false);
		break;
	case passiveStriker:
		return new StrikerBrain(player, true);
		break;
	case defender:
		return new DefenderBrain(player);
		break;
	default:
		return NULL;
		break;
	}
	return NULL;
}
