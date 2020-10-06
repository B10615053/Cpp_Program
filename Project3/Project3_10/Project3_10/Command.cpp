#include "Command.h"




namespace CommandAnalyze {

	// SET, FIRE, DEFENSE, TAG, MOVE
	String^ processCommand(int minute, int second, String^ inpString, Team^ team, Team^ anotherTeam) {

		//array<String^>^ VESSEL_TYPE_LIST = gcnew array<String^>{"CV", "BB", "CG", "DD"};
		String^ cmdType = "";
		String^ vesselName = "";
		array<String^>^ elementOfCmd = inpString->Split(); // split by space
		int k, first;
		CommandsType cmdRes;
		String^ resString = "";

		// get command type and vessel name
		for (k = 0, first = 1; k < elementOfCmd->Length; k++) {
			if (elementOfCmd[k] != "") {

				if (first == 1) {
					// to upper, ex: set -> SET, fIRe -> FIRE
					cmdType = toUpper(elementOfCmd[k]);
					first = 0;
				}
				else {
					vesselName = elementOfCmd[k];
					break;
				}
			}
		}
		// now k is at the index of [Vessel_Name]

		#pragma region coordinate format process
		if (cmdType == "SET" || cmdType == "FIRE" || cmdType == "LAUNCH") {

			int lastIdx = elementOfCmd->Length - 1;
			for (; lastIdx >= 0; lastIdx--) {
				if (elementOfCmd[lastIdx] != "")
					break;
			}

			for (int u = elementOfCmd[lastIdx]->Length - 1; u >= 0; u--) {

				if (elementOfCmd[lastIdx][u] == ',') {
					for (int v = inpString->Length - 1; v >= 0; v--) {

						if (inpString[v] == ',') {
							inpString = inpString->Substring(0, v) + " " + inpString->Substring(v);
							break;
						}
					}

					delete[] elementOfCmd;
					elementOfCmd = inpString->Split();

					// get command type and vessel name
					for (k = 0, first = 1; k < elementOfCmd->Length; k++) {
						if (elementOfCmd[k] != "") {

							if (first == 1) {
								// to upper, ex: set -> SET, fIRe -> FIRE
								cmdType = toUpper(elementOfCmd[k]);
								first = 0;
							}
							else {
								vesselName = elementOfCmd[k];
								break;
							}
						}
					}
					// now k is at the index of [Vessel_Name]

					break;
				}

			}
		}
		#pragma endregion
		


		/* ============================================================================================= */

		// SET [Vessel_Name] [Type] [2DCoordinate]
		if (cmdType == "SET") {

			String^ vesselType = "";
			double newX = -10.0, newY = -10.0;

			cmdRes = SET_SUCCESS;

			// get vessel type and coordinate
			for (k++, first = 1; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {

					if (first == 1) {
						vesselType = elementOfCmd[k];
						first = 0;
					}
					else if (first == 0) {
						newX = findNumberInString(elementOfCmd[k]);
						first = -1;
					}
					else {
						newY = findNumberInString(elementOfCmd[k]);
						break;
					}
				}
			}

			// Fail: the coordinate is out of range
			if (newX < 0.0 || newX > 20.0 || newY < 0.0 || newY > 20.0) {
				cmdRes = SET_FAIL;
			}

			// Fail: already exist a vessel which name is the same and at the same team
			if (team->vesselList.ContainsKey(vesselName)) {
				cmdRes = SET_FAIL;
			}

			// Search if there is another vessel which is at the new coordinate
			for each (KeyValuePair<String^, VesselObject^> vessel in team->vesselList) {
				double dis2 = ((vessel.Value->getCoord().X - newX) * (vessel.Value->getCoord().X - newX)) + ((vessel.Value->getCoord().Y - newY) * (vessel.Value->getCoord().Y - newY));

				// Fail: there is another vessel in the new coordinate
				if (dis2 <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE) {
					cmdRes = SET_FAIL;
					break;
				}
			}
			for each (KeyValuePair<String^, VesselObject^> vessel in anotherTeam->vesselList) {
				double dis2 = ((vessel.Value->getCoord().X - newX) * (vessel.Value->getCoord().X - newX)) + ((vessel.Value->getCoord().Y - newY) * (vessel.Value->getCoord().Y - newY));

				// Fail: there is another vessel in the new coordinate
				if (dis2 <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE) {
					cmdRes = SET_FAIL;
					break;
				}
			}

			// Search if there the location is at a geography area
			for each (GeographicSystem^ geo in GeographicSystem::geoList) {

				// Fail: you cannot set a vessel at a geography area
				if (geo->getGp()->IsVisible(COORD_TO_DRAWING_COORD(newX, newY))) {
					cmdRes = SET_FAIL;
					break;
				}
			}

			#pragma region create any types of vessels
			if (vesselType == "CV" && cmdRes == SET_SUCCESS) {
				VesselCV^ newCV = gcnew VesselCV(vesselName, team->getSymbol(), PointF(newX, newY));
				team->vesselList.Add(vesselName, newCV);
			}

			else if (vesselType == "BB" && cmdRes == SET_SUCCESS) {
				VesselBB^ newBB = gcnew VesselBB(vesselName, team->getSymbol(), PointF(newX, newY));
				team->vesselList.Add(vesselName, newBB);
			}

			else if (vesselType == "CG" && cmdRes == SET_SUCCESS) {
				VesselCG^ newCG = gcnew VesselCG(vesselName, team->getSymbol(), PointF(newX, newY));
				team->vesselList.Add(vesselName, newCG);
			}

			else if (vesselType == "DD" && cmdRes == SET_SUCCESS) {
				VesselDD^ newDD = gcnew VesselDD(vesselName, team->getSymbol(), PointF(newX, newY));
				team->vesselList.Add(vesselName, newDD);
			}

			else if (vesselType == "LV" && cmdRes == SET_SUCCESS) {
				VesselLV^ newLV = gcnew VesselLV(vesselName, team->getSymbol(), PointF(newX, newY));
				team->vesselList.Add(vesselName, newLV);
			}

			else if (vesselType == "AH" && cmdRes == SET_SUCCESS) {
				VesselAH^ newAH = gcnew VesselAH(vesselName, team->getSymbol(), PointF(newX, newY));
				team->vesselList.Add(vesselName, newAH);
			}
			#pragma endregion

			// Fail: unknown vessel type
			else {
				cmdRes = SET_FAIL;
			}

			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " SET " + vesselName + " with " + vesselType + " at (" + newX.ToString() + ", " + newY.ToString() + ") -> " + ((cmdRes == SET_SUCCESS) ? "Success\r\n" : "Fail\r\n");
			return resString;
		}

		// FIRE [Vessel_Name] [2DCoordinate]
		else if (cmdType == "FIRE") {

			double newX = -10.0, newY = -10.0;
			double nowX = -10.0, nowY = -10.0, dis, dis2; // dis2 means the square of dis, that is, (dis * dis)
			String^ newShellName;
			VesselObject^ thisVessel;

			cmdRes = FIRE_SUCCESS;

			// get the coordinate
			for (k++, first = 1; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {

					if (first == 1) {
						newX = findNumberInString(elementOfCmd[k]);
						first = 0;
					}
					else {
						newY = findNumberInString(elementOfCmd[k]);
						break;
					}
				}
			}

			// set the name of new shell
			newShellName = "Shell_" + ((team->getSymbol() == A) ? "A" : "B") + (team->getLauchedShellNum() + 1).ToString();

			// find the vessel from lists
			if (team->vesselList.ContainsKey(vesselName))
				thisVessel = team->vesselList[vesselName];
			// Fail: Vessel not found
			else
				cmdRes = FIRE_FAIL;

			// Fail: LV and AH cannot FIRE
			if (cmdRes == FIRE_SUCCESS && (thisVessel->getVesselType() == LV || thisVessel->getVesselType() == AH))
				cmdRes = FIRE_FAIL;

			// Fail: the location of goal is out of range
			if (newX < 0.0 || newX > 20.0 || newY < 0.0 || newY > 20.0)
				cmdRes = FIRE_FAIL;

			if (cmdRes == FIRE_SUCCESS) {

				// calculate the coordinate of vessel and attack distance
				nowX = thisVessel->getCoord().X; nowY = thisVessel->getCoord().Y;
				dis2 = ((nowX - newX) * (nowX - newX)) + ((nowY - newY) * (nowY - newY));
				dis = Math::Sqrt(dis2);

				// Fail: the attack distance is over than the max attack distance
				if (dis2 > thisVessel->getMaxAttackDistance() * thisVessel->getMaxAttackDistance())
					cmdRes = FIRE_FAIL;

				// Fail: still in CD time
				if (thisVessel->getRemainAttackCD() > 0.0) {
					cmdRes = FIRE_FAIL;
				}
			}

			if (cmdRes == FIRE_SUCCESS) {
				team->plus1LauchShellNum();

				double angle;
				if (nowY == newY && nowX == newX)
					angle = 0.0, newY += 0.01, newX += 0.01;
				else
					angle = (180.0 / Math::PI) * Math::Atan2(nowY - newY, nowX - newX);

				Shell^ newShell = gcnew Shell(newShellName, team->getSymbol(), thisVessel->getShellSpeed(), thisVessel->getDamage(), angle, thisVessel->getCoord(), PointF(newX, newY));
				team->shellList.Add(newShell);

				//Debug::WriteLine("New shell: " + newShell->getName() + ", " + newShell->getNowCoord() + ", " + newShell->getGoalCoord() + ", " + newShell->getSpeed());
				//Debug::WriteLine(newShell->getNowCoord4Draw());
			}

			// enter attack CD time
			if (thisVessel != nullptr && thisVessel->getRemainAttackCD() == 0.0) {
				thisVessel->setRemainAttackCD(thisVessel->getAttackCD());
			}

			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " " + vesselName + " FIRE to " + "(" + newX.ToString() + ", " + newY.ToString() + ") -> " + ((cmdRes == FIRE_SUCCESS) ? (newShellName + "\r\n") : "Fail\r\n");
			return resString;
		}

		// DEFENSE [Vessel_Name] [Shell_Name]
		else if (cmdType == "DEFENSE") {

			String^ shellName;
			VesselObject^ thisVessel;
			double dis2;
			bool hasHitShell = false;
			bool hasFoundShell = false;

			cmdRes = DEFENSE_SUCCESS;

			// get the shell name
			for (k++; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {
					shellName = elementOfCmd[k];
					break;
				}
			}

			// find the vessel from lists
			if (team->vesselList.ContainsKey(vesselName))
				thisVessel = team->vesselList[vesselName];
			// Fail: Vessel not found
			else
				cmdRes = DEFENSE_FAIL;

			// Fail: LV and AH cannot DEFENSE
			if (thisVessel != nullptr && cmdRes == DEFENSE_SUCCESS && (thisVessel->getVesselType() == LV || thisVessel->getVesselType() == AH))
				cmdRes = DEFENSE_FAIL;

			// Fail: still in CD time
			if (cmdRes == DEFENSE_SUCCESS && thisVessel->getRemainDefenseCD() > 0.0) {
				cmdRes = FIRE_FAIL;
			}

			if (cmdRes == DEFENSE_SUCCESS) {

				for (int i = 0; i < team->shellList.Count && !hasFoundShell; i++) {
					Shell^ thisShell = team->shellList[i];

					// found the shell
					if (thisShell->getName() == shellName) {

						hasFoundShell = true;
						dis2 = ((thisShell->getNowCoord().X - thisVessel->getCoord().X) * (thisShell->getNowCoord().X - thisVessel->getCoord().X)) + ((thisShell->getNowCoord().Y - thisVessel->getCoord().Y) * (thisShell->getNowCoord().Y - thisVessel->getCoord().Y));

						// hit
						if (dis2 <= thisVessel->getMaxDefenseDistance() * thisVessel->getMaxDefenseDistance()) {
							hasHitShell = true;
							team->shellList.RemoveAt(i);
							break;
						}
					}
				}
				for (int i = 0; i < anotherTeam->shellList.Count && !hasFoundShell; i++) {
					Shell^ thisShell = anotherTeam->shellList[i];

					// found the shell
					if (thisShell->getName() == shellName) {
						dis2 = ((thisShell->getNowCoord().X - thisVessel->getCoord().X) * (thisShell->getNowCoord().X - thisVessel->getCoord().X)) + ((thisShell->getNowCoord().Y - thisVessel->getCoord().Y) * (thisShell->getNowCoord().Y - thisVessel->getCoord().Y));

						// hit
						if (dis2 <= thisVessel->getMaxDefenseDistance() * thisVessel->getMaxDefenseDistance()) {
							hasHitShell = true;
							anotherTeam->shellList.RemoveAt(i);
							break;
						}
					}
				}

				if (!hasHitShell)
					cmdRes = DEFENSE_FAIL;
			}

			// enter defense CD time
			if (thisVessel != nullptr && thisVessel->getRemainDefenseCD() == 0.0) {
				thisVessel->setRemainDefenseCD(thisVessel->getDefenseCD());
			}
			
			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] " + vesselName + " DEFENSE " + shellName + " -> " + (cmdRes == DEFENSE_SUCCESS ? "Hit\r\n" : "Fail\r\n");
			return resString;
		}

		// TAG [Vessel_Name] [New_Name]
		else if (cmdType == "TAG") {
			String^ newName = "";
			VesselObject^ newVessel = gcnew VesselObject;

			cmdRes = TAG_SUCCESS;

			for (k++; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {

					newName = elementOfCmd[k];
					break;
				}
			}

			if (newName != "" && team->vesselList.ContainsKey(vesselName) && !team->vesselList.ContainsKey(newName)) {
				newVessel = team->vesselList[vesselName];
				newVessel->setName(newName);
				team->vesselList.Add(newName, newVessel);
				team->vesselList.Remove(vesselName);
			}

			else {
				cmdRes = TAG_FAIL;
			}

			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " RENAME " + vesselName + " to " + newName + " -> " + ((cmdRes == TAG_SUCCESS) ? "Success\r\n" : "Fail\r\n");
			return resString;
		}

		// MOVE [Vessel_Name] [Speed] [Angle]
		else if (cmdType == "MOVE") {

			VesselObject^ thisVessel;
			double moveSpeed = -10.0, moveAngle = -10.0;

			cmdRes = MOVE_SUCCESS;

			// get the speed and the angle
			for (k++, first = 1; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {

					if (first == 1) {
						moveSpeed = findNumberInString(elementOfCmd[k]);
						first = 0;
					}
					else {
						moveAngle = findNumberInString(elementOfCmd[k]);
						break;
					}
				}
			}

			if (moveSpeed == -10.0) {
				cmdRes = MOVE_FAIL;
			}

			// find the vessel from lists
			if (team->vesselList.ContainsKey(vesselName))
				thisVessel = team->vesselList[vesselName];
			// Fail: Vessel not found
			else
				cmdRes = MOVE_FAIL;

			if (cmdRes == MOVE_SUCCESS) {

				// Fail: move speed is over the max vessel speed
				if (Math::Abs(moveSpeed) > (thisVessel->getMaxVesselSpeed()) * 60.0)
					cmdRes = MOVE_FAIL;

				// Fail: angle is negative value or is over 359
				if (moveAngle < 0.0 || moveAngle > 359.0)
					cmdRes = MOVE_FAIL;

				// Fail: in fog area, cannot moving
				if (thisVessel->getCanMove() == false) {
					cmdRes = MOVE_FAIL;
					Debug::WriteLine("cmdRes, getMove false");
				}
			}

			//Debug::WriteLine(moveSpeed.ToString() + ", " + moveAngle.ToString());

			if (cmdRes == MOVE_SUCCESS) {
				thisVessel->setNowSpeed(moveSpeed / 60.0);
				thisVessel->setNowAngle(moveAngle);
			}
			else {
				if (thisVessel != nullptr) {
					thisVessel->setNowSpeed(0.0);
					thisVessel->setNowAngle(0.0);
				}
			}

			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " " + vesselName + " MOVE to " + moveAngle + " as " + moveSpeed + " -> " + ((cmdRes == MOVE_SUCCESS) ? "Success\r\n" : "Fail\r\n");
			return resString;
		}

		// LASER [Vessel_Name] [Angle]
		else if (cmdType == "LASER") {

			VesselObject^ thisVessel;
			double laserAngle = -10.0;

			cmdRes = LASER_SUCCESS;

			// get the angle
			for (k++; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {
					laserAngle = findNumberInString(elementOfCmd[k]);
					break;
				}
			}

			// find the vessel from lists
			if (team->vesselList.ContainsKey(vesselName))
				thisVessel = team->vesselList[vesselName];
			// Fail: Vessel not found
			else
				cmdRes = LASER_FAIL;

			// Fail: still remain laser CD
			if (cmdRes == LASER_SUCCESS && thisVessel->getRemainLaserCD() > 0.0)
				cmdRes = LASER_FAIL;

			// Fail: angle is negative value or is over 359
			if (laserAngle < 0.0 || laserAngle > 359.0)
				cmdRes = LASER_FAIL;

			// Fail: only LV can use laser attack
			if (thisVessel != nullptr && thisVessel->getVesselType() != LV)
				cmdRes = LASER_FAIL;

			if (cmdRes == LASER_SUCCESS) {
				thisVessel->SetLaserAngle(laserAngle);
				thisVessel->setIsLaserShooting(true);

				thisVessel->setRemainLaserCD(thisVessel->getLaserCD());
			}

			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " " + vesselName + " use LASER -> " + ((cmdRes == LASER_SUCCESS) ? "Success\r\n" : "Fail\r\n");
			return (cmdRes == LASER_FAIL) ? resString : "";
		}

		// ENRICH [Vessel_Name] [Vessel_Name_whichNeedEnrichment]
		else if (cmdType == "ENRICH") {

			String^ enrichedVesselName = "";
			VesselObject^ enrichedVessel = gcnew VesselObject;
			VesselObject^ thisVessel = gcnew VesselObject;

			cmdRes = ENRICH_SUCCESS;

			// get the name of vessel which need enrichment
			for (k++; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {

					enrichedVesselName = elementOfCmd[k];
					break;
				}
			}

			// Fail: the AH vessel is NOT in the list
			if (!team->vesselList.ContainsKey(vesselName))
				cmdRes = ENRICH_FAIL;
			else
				thisVessel = team->vesselList[vesselName];

			// Fail: the vessel which need enrichment is NOT in the same-team-list
			if (!team->vesselList.ContainsKey(enrichedVesselName))
				cmdRes = ENRICH_FAIL;
			else
				enrichedVessel = team->vesselList[enrichedVesselName];

			// Fail: only AH can do enrichment
			if (cmdRes == ENRICH_SUCCESS && thisVessel->getVesselType() != AH)
				cmdRes = ENRICH_FAIL;

			// Fail: the location of the vessel which need enrichment is out of the enrich range of AH vessel
			if (cmdRes == ENRICH_SUCCESS && !thisVessel->isEnrichVessel(enrichedVessel->getCoord().X, enrichedVessel->getCoord().Y))
				cmdRes = ENRICH_FAIL;

			// Fail: Still in CD time
			if (cmdRes == ENRICH_SUCCESS && thisVessel->get_remain_Enrich_CD() > 0.0)
				cmdRes = ENRICH_FAIL;

			if (cmdRes == ENRICH_SUCCESS)
				enrichedVessel->setRemainHp(enrichedVessel->getRemainHp() + thisVessel->getEnrichValue());

			if (thisVessel != nullptr && thisVessel->get_remain_Enrich_CD() == 0.0) {
				thisVessel->set_remain_Enrich_CD(thisVessel->getEnrichValue_CD());
			}


			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " " + vesselName  + " ENRICH " + enrichedVesselName + " -> " + ((cmdRes == ENRICH_SUCCESS) ? "Success\r\n" : "Fail\r\n");
			return resString;
		}

		// LAUNCH [Vessel_Name] [2DCoordinate]
		else if (cmdType == "LAUNCH") {

			double newX = -10.0, newY = -10.0;
			double nowX = -10.0, nowY = -10.0, dis, dis2; // dis2 means the square of dis, that is, (dis * dis)
			String^ newTorpedoName;
			VesselObject^ thisVessel;

			cmdRes = LAUNCH_SUCCESS;

			// Get the coordinate
			for (k++, first = 1; k < elementOfCmd->Length; k++) {
				if (elementOfCmd[k] != "") {
					if (first == 1) {
						newX = findNumberInString(elementOfCmd[k]);
						first = 0;
					}
					else {
						newY = findNumberInString(elementOfCmd[k]);
						break;
					}
				}
			}

			// Set the name of new torpedo
			newTorpedoName = "Torpedo_" + ((team->getSymbol() == A) ? "A" : "B") + (team->getLaunchedTorpedoNum() + 1).ToString();

			// Find the vessel from lists
			if (team->vesselList.ContainsKey(vesselName))
				thisVessel = team->vesselList[vesselName];
			// Fail: Vessel not found
			else
				cmdRes = LAUNCH_FAIL;

			// Fail: LV & CV & BB & AH cannot LAUNCH torpedo, only CG and DD can
			if (cmdRes == LAUNCH_SUCCESS && !(thisVessel->getVesselType() == CG || thisVessel->getVesselType() == DD))
				cmdRes = LAUNCH_FAIL;

			// Fail: the location of goal is out of range
			if (newX < 0.0 || newX > 20.0 || newY < 0.0 || newY > 20.0)
				cmdRes = LAUNCH_FAIL;

			if (cmdRes == LAUNCH_SUCCESS) {

				// calculate the coordinate of vessel and attack distance
				nowX = thisVessel->getCoord().X; nowY = thisVessel->getCoord().Y;
				dis2 = ((nowX - newX) * (nowX - newX)) + ((nowY - newY) * (nowY - newY));
				dis = Math::Sqrt(dis2);

				// Fail: the attack distance is over than the max attack distance
				if (dis2 > thisVessel->getMaxAttackDistance() * thisVessel->getMaxAttackDistance())
					cmdRes = LAUNCH_FAIL;

				// Fail: still in CD time
				if (thisVessel->getRemainLaunchCD() > 0.0) {
					cmdRes = LAUNCH_FAIL;
				}
			}

			if (cmdRes == LAUNCH_SUCCESS) {
				team->plus1LauchShellNum();

				double angle;
				if (nowY == newY && nowX == newX)
					angle = 0.0, newY += 0.01, newX += 0.01;
				else
					angle = (180.0 / Math::PI) * Math::Atan2(nowY - newY, nowX - newX);

				Torpedo^ newTorpedo = gcnew Torpedo(newTorpedoName, thisVessel->getName(), team->getSymbol(), thisVessel->getTorpedoSpeed(), thisVessel->getTorpedoDamage(), angle, thisVessel->getCoord(), PointF(newX, newY));
				team->torpedoList.Add(newTorpedo);

				//Debug::WriteLine("New Torpedo: " + newTorpedo->getName() + ", " + newTorpedo->getNowCoord() + ", " + newTorpedo->getGoalCoord() + ", " + newTorpedo->getSpeed());
				//Debug::WriteLine(newTorpedo->getNowCoord4Draw());
			}

			// Enter launch CD time
			if (thisVessel != nullptr && thisVessel->getRemainLaunchCD() == 0.0) {
				thisVessel->setRemainLaunchCD(thisVessel->getLaunchCD());
			}

			resString = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (wchar_t)(team->getSymbol() + 65) + " " + vesselName + " LAUNCH a torpedo to " + "(" + newX.ToString() + ", " + newY.ToString() + ") -> " + ((cmdRes == LAUNCH_SUCCESS) ? (newTorpedoName + "\r\n") : "Fail\r\n");
			return resString;
		}

		// Unknown Command
		else {
			/*Reef^ reef = gcnew Reef(PointF(10, 10), SizeF(2, 4.5));
			GeographicSystem::geoList.Add(reef);

			Flatland^ flatland = gcnew Flatland(PointF(0, 1), SizeF(8, 10));
			GeographicSystem::geoList.Add(flatland);

			Mountain^ mountain = gcnew Mountain(PointF(17.5, 0), SizeF(2.5, 18));
			GeographicSystem::geoList.Add(mountain);*/

			return "Unknown command\r\n";
		}


		return ":(";
		return ":/";
		return ":|";
		return ":)";
		return ":D";
	}

	// ex: sEt -> SET
	String^ toUpper(String^ str) {
		String^ res = "";

		for (int i = 0; i < str->Length; i++) {

			if (str[i] >= 'a' && str[i] <= 'z')
				res += (wchar_t)((int)str[i] - 32);
			else
				res += str[i];
		}

		return res;
	}

	// find a number in a string, ex: "(,,12|3.2,"  -> 123.2
	double findNumberInString(String^ str) {
		double num = -10.0;
		double fracDigit = 0.1;
		bool isNeg = false;

		for (int i = 0, isIntegerPart = 1; i < str->Length; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				if (num == -10.0)
					num = 0.0;

				if (isIntegerPart == 1)
					num = (num * 10.0) + (double)((int)str[i] - 48);
				else
					num += (double)((int)str[i] - 48) * fracDigit, fracDigit *= 0.1;
			}
			else if (str[i] == '.')
				isIntegerPart = 0;
			else if (str[i] == '-')
				isNeg = true;
		}

		if (num == -10.0)
			return num;

		return (isNeg ? (-num) : num);
	}
}