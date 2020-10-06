#include "Team.h"




Team::Team() {
	vesselList.Clear();
	shellList.Clear();
	torpedoList.Clear();
	lauchedShellNum = 0;
	launchedTorpedoNum = 0;
	symbol = NONE;
}

Team::Team(TeamSymbol newSybol): Team() {
	symbol = newSybol;
}

#pragma region getters and setters
int Team::getLauchedShellNum() {
	return lauchedShellNum;
}
void Team::setLauchedShellNum(int newLauchedShellNum) {
	lauchedShellNum = newLauchedShellNum;
}
void Team::plus1LauchShellNum() {
	lauchedShellNum++;
}

int Team::getLaunchedTorpedoNum() {
	return launchedTorpedoNum;
}

void Team::setLaunchedTorpedoNum(int newLaunchedTorpedoNum) {
	launchedTorpedoNum = newLaunchedTorpedoNum;
}

void Team::plus1LaunchTorpedoNum() {
	launchedTorpedoNum++;
}

TeamSymbol Team::getSymbol() {
	return symbol;
}
void Team::setSymbol(TeamSymbol newTeamSymbol) {
	symbol = newTeamSymbol;
}
#pragma endregion