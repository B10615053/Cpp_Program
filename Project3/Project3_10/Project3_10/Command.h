#pragma once

#include "VesselObject.h"
#include "VesselCV.h"
#include "VesselBB.h"
#include "VesselCG.h"
#include "VesselDD.h"
#include "VesselLV.h"
#include "VesselAH.h"
#include "Team.h"
#include "Shell.h"
#include "Torpedo.h"
#include "GeographicSystem.h"
#include "Reef.h"
#include "Flatland.h"
#include "Mountain.h"
#include "HydrometeorologicSystem.h"
#include "Lightning.h"
#include "Typhoon.h"
#include "Fog.h"

#define DEBUG
#ifdef DEBUG
using namespace System::Diagnostics;
#endif // DEBUG
using namespace System;

namespace CommandAnalyze {

	// SET, FIRE, DEFENSE, TAG, MOVE, LASER, ENRICH, LAUNCH
	enum CommandsType {

		SET_SUCCESS, SET_FAIL,			// set		新增
		FIRE_SUCCESS, FIRE_FAIL,		// fire		攻擊
		DEFENSE_SUCCESS, DEFENSE_FAIL,	// defense	防禦
		TAG_SUCCESS, TAG_FAIL,			// tag		更名
		MOVE_SUCCESS, MOVE_FAIL,		// move		移動
		LASER_SUCCESS, LASER_FAIL,		// laser	雷射
		ENRICH_SUCCESS, ENRICH_FAIL,	// enrich	救濟
		LAUNCH_SUCCESS, LAUNCH_FAIL,	// launch	魚雷
		UNKNOWN_CMD_TYPE
	};

	String^ processCommand(int, int, String^, Team^, Team^);
	String^ toUpper(String^);
	double findNumberInString(String^);
}