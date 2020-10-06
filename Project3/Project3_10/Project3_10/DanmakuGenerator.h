#pragma once


// ¼u¹õ¼Ò¦¡¡GBoss ®gÀ»¼u¹õ
bool shootDanmaku(int level) {
	//level = 11;

	const double R = 50.0;
	static double torpedoLocTheta1 = 0.0;
	static double torpedoLocTheta2 = 0.0;
	double x1, y1, x2, y2;
	double angle1, angle2;

	if (level == 1) {
		if (second % 2 == 0) {
			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			torpedoLocTheta1 += 0.5;
			if (torpedoLocTheta1 > 360.0) torpedoLocTheta1 -= 360.0;
		}
	}

	else if (level == 2) {
		if (second % 1 == 0) {
			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			torpedoLocTheta1 -= 0.4;
			//if (torpedoLocTheta1 < 0.0) torpedoLocTheta1 += 360.0;
		}
	}

	else if (level == 3) {
		if (second % 1 == 0) {
			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			torpedoLocTheta1 += 0.4;
			//if (torpedoLocTheta1 < 0.0) torpedoLocTheta1 += 360.0;

			x2 = R * Math::Cos(torpedoLocTheta2);
			y2 = R * Math::Sin(torpedoLocTheta2);
			angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

			Torpedo^ newTorpedo2 = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
			team_B->torpedoList.Add(newTorpedo2);

			torpedoLocTheta2 -= 0.4;
			//if (torpedoLocTheta1 < 0.0) torpedoLocTheta1 += 360.0;
		}
	}

	else if (level == 4) {
		for (int i = 0; i < 4; i++) {
			torpedoLocTheta1 = r4danmaku->NextDouble() * 180.0;

			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);
		}
	}

	else if (level == 5) {
		if (((minute * 60) + second) % 8 == 0) {
			int startLoc = r4danmaku->Next(360);

			for (int i = startLoc; i < 360 + startLoc; i += 10) {
				torpedoLocTheta1 = i;

				x1 = R * Math::Cos(torpedoLocTheta1);
				y1 = R * Math::Sin(torpedoLocTheta1);
				angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
				team_B->torpedoList.Add(newTorpedo);
			}
		}
	}

	else if (level == 6) {
		if (second % 1 == 0) {
			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			x1 = R * Math::Cos(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
			y1 = R * Math::Sin(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			x1 = R * Math::Cos(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
			y1 = R * Math::Sin(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);


			torpedoLocTheta1 += 0.2;
			if (torpedoLocTheta1 > 360.0) torpedoLocTheta1 -= 360.0;
		}
	}

	else if (level == 7) {
		if (second % 1 == 0) {
			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			x1 = R * Math::Cos(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
			y1 = R * Math::Sin(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			x1 = R * Math::Cos(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
			y1 = R * Math::Sin(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);

			torpedoLocTheta1 += 0.2;
			if (torpedoLocTheta1 > 360.0) torpedoLocTheta1 -= 360.0;

			/* ================================================================== */

			x2 = R * Math::Cos(torpedoLocTheta2);
			y2 = R * Math::Sin(torpedoLocTheta2);
			angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
			team_B->torpedoList.Add(newTorpedo);

			x2 = R * Math::Cos(torpedoLocTheta2 + ANGLE_TO_RADIUS(120.0));
			y2 = R * Math::Sin(torpedoLocTheta2 + ANGLE_TO_RADIUS(120.0));
			angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
			team_B->torpedoList.Add(newTorpedo);

			x2 = R * Math::Cos(torpedoLocTheta2 - ANGLE_TO_RADIUS(120.0));
			y2 = R * Math::Sin(torpedoLocTheta2 - ANGLE_TO_RADIUS(120.0));
			angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

			newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
			team_B->torpedoList.Add(newTorpedo);


			torpedoLocTheta2 -= 0.2;
			if (torpedoLocTheta2 > 360.0) torpedoLocTheta2 -= 360.0;
		}
	}

	else if (level == 8) {
		if (second % 3 == 0) {

			torpedoLocTheta1 = r4danmaku->NextDouble() * 120.0 + 30.0;
			torpedoLocTheta2 = torpedoLocTheta1 - 10.0;

			for (int i = 0; i < 21; i++) {
				x1 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta2));
				y1 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta2));
				angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
				team_B->torpedoList.Add(newTorpedo);

				torpedoLocTheta2 += 1.0;
			}
		}
	}

	else if (level == 9) {
		if (second % 5 == 0) {
			for (int i = 0; i < 7; i++) {

				x1 = r4danmaku->NextDouble() * (double)BOARD_SIZE;
				x2 = x1;
				y1 = -5.0;
				y2 = 31.0;
				angle1 = (180.0 / Math::PI) * Math::Atan2(y2 - y1, x2 - x1);

				double dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
				newTorpedo->setSpeed(r4danmaku->NextDouble() * 1.5 + 0.1);
				newTorpedo->setTotalFlyingTime(dis / newTorpedo->getSpeed() + 4.5);
				team_B->torpedoList.Add(newTorpedo);
			}
		}

		torpedoLocTheta1 = 270;
		torpedoLocTheta2 = 240;
	}

	else if (level == 10) {
		for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
			for (int i = -2; i <= 2; i++) {
				x1 = vessel_A.Value->getCoord().X + (double)i * 3.0;
				y1 = vessel_A.Value->getCoord().Y;

				angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
				team_B->torpedoList.Add(newTorpedo);
			}
		}
	}

	else if (level == 11) {
		for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
			for (int i = -2; i <= 2; i++) {
				x1 = vessel_A.Value->getCoord().X + (double)i * (Math::Abs(i) == 2 ? 5.0 : 1.0);
				y1 = vessel_A.Value->getCoord().Y;

				angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
				team_B->torpedoList.Add(newTorpedo);
			}

			for (int i = -2; i <= 2; i++) {
				x1 = (double)BOARD_SIZE - vessel_A.Value->getCoord().X + (double)i * (Math::Abs(i) == 2 ? 6.0 : 1.0);
				y1 = -vessel_A.Value->getCoord().Y;

				angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
				team_B->torpedoList.Add(newTorpedo);
			}
		}
	}

	else if (level == 11) {

		x1 = -2.0; y1 = -2.0;

		x2 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta1));
		y2 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta1));
		angle1 = (180.0 / Math::PI) * Math::Atan2(y2 - y1, x2 - x1);

		Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
		team_B->torpedoList.Add(newTorpedo);


		/* =================================================================== */

		x1 = 22.0; y1 = -2.0;

		x2 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta1 + 180.0));
		y2 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta1 + 180.0));
		angle1 = (180.0 / Math::PI) * Math::Atan2(y2 - y1, x2 - x1);

		newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
		team_B->torpedoList.Add(newTorpedo);


		torpedoLocTheta1 += 8.0;
		if (torpedoLocTheta1 >= 480.0)
			torpedoLocTheta1 = 270.0;
	}

	else if (level >= 20) {
		for (int i = 0; i < 8; i++) {
			torpedoLocTheta1 = r4danmaku->NextDouble() * 180.0;

			x1 = R * Math::Cos(torpedoLocTheta1);
			y1 = R * Math::Sin(torpedoLocTheta1);
			angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

			Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
			team_B->torpedoList.Add(newTorpedo);
		}
	}

	return true;
}