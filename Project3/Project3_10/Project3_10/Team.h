#pragma once

#include "VesselObject.h"
#include "Shell.h"
#include "Torpedo.h"

using namespace System;
using namespace System::Windows;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
//using namespace System::Globalization;
//using namespace System::IO;

ref class Team {
public:
	Team();
	Team(TeamSymbol);

	// vessel list
	Dictionary<String^, VesselObject^> vesselList;

	// shell list
	List<Shell^> shellList;

	// Torpedo list
	List<Torpedo^> torpedoList;

	#pragma region getters and setters
	// shell
	int getLauchedShellNum();
	void setLauchedShellNum(int);
	void plus1LauchShellNum();

	// torpedo
	int getLaunchedTorpedoNum();
	void setLaunchedTorpedoNum(int);
	void plus1LaunchTorpedoNum();

	TeamSymbol getSymbol();
	void setSymbol(TeamSymbol);
	#pragma endregion

private:
	int lauchedShellNum;
	int launchedTorpedoNum;
	TeamSymbol symbol;
};

