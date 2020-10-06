#pragma once




enum TeamSymbol { A = 0, B = 1, BOTH = 2, NONE = 3 };

#ifndef BOARD_SIZE
#define BOARD_SIZE 20 /* !!! should NOT be changed due to the rule of project !!! */
#endif // !BOARD_SIZE

#ifndef BLOCK_LENGTH
#define BLOCK_LENGTH 19
#endif // !BLOCK_LENGTH

#ifndef BOARD_LENGTH
#define BOARD_LENGTH (BOARD_SIZE * BLOCK_LENGTH)
#endif // !BOARD_LENGTH

#ifndef BIAS_X
#define BIAS_X 19
#endif // !BIAS_X

#ifndef BIAS_Y
#define BIAS_Y 19
#endif // !BIAS_Y

#ifndef VESSEL_ICON_LENGTH
#define VESSEL_ICON_LENGTH 15.0F
#endif // !ICON_LENGTH

#ifndef COLLAPSE_DISTANCE
#define COLLAPSE_DISTANCE 0.8
#endif // !COLLAPSE_DISTANCE

#ifndef SHELL_ICON_LENGTH
#define SHELL_ICON_LENGTH 8.0F
#endif // !ICON_LENGTH

#ifndef COORD_TO_DRAWING_COORD(x, y)
#define COORD_TO_DRAWING_COORD(x, y) PointF((float)x * BLOCK_LENGTH + BIAS_X, (float)y * BLOCK_LENGTH + BIAS_Y)
#endif // !COORD_TO_DRAWING_COORD(x, y)

#ifndef DRAWING_COORD_TO_COORD(x, y)
#define DRAWING_COORD_TO_COORD(x, y) PointF(((float)x - BIAS_X) / (float)BLOCK_LENGTH, ((float)y - BIAS_Y) / (float)BLOCK_LENGTH)
#endif // !DRAWING_COORD_TO_COORD(x, y)

#ifndef SIZE_TO_DRAWING_SIZE(w, h)
#define SIZE_TO_DRAWING_SIZE(w, h) SizeF((float)w * BLOCK_LENGTH, (float)h * BLOCK_LENGTH);
#endif // !SIZE_TO_DRAWING_SIZE

#ifndef DRAWING_SIZE_TO_SIZE(w, h)
#define DRAWING_SIZE_TO_SIZE(w, h) SizeF((float)w / BLOCK_LENGTH, (float)h / BLOCK_LENGTH);
#endif // !SIZE_TO_DRAWING_SIZE

#ifndef EPS
#define EPS 0.5
#endif // !EPS

#ifndef ANGLE_TO_RADIUS(x)
#define ANGLE_TO_RADIUS(x) ((x * Math::Acos(-1.0)) / 180.0)
#endif

#ifndef BIAS_Y_4_DRAW_NAME
#define BIAS_Y_4_DRAW_NAME 17.0
#endif // !BIAS_Y_4_DRAW_NAME

#ifndef BIAS_X_4_DRAW_NAME
#define BIAS_X_4_DRAW_NAME 7.0
#endif // !BIAS_X_4_DRAW_NAME
