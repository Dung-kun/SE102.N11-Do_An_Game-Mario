#pragma once
//windown
#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"04 - Collision"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DXCOLOR(156.0f/255, 252.0f/255, 240.0f/255, 0.0f)

#define SCREEN_WIDTH 272
#define SCREEN_HEIGHT 256

#define MAX_FRAME_RATE 100

//directX
#define KEYBOARD_BUFFER_SIZE 1024
#define KEYBOARD_STATE_SIZE 256
#define BBOX_ALPHA 0.25f

//0 = Mario, 1 = Brick, 2 = Goomba, 3 = Koopas

enum eType
{
	MARIO = 0,
	BRICK = 1,
	GOOMBA = 2,
	KOOPAS = 3,
	COIN = 4,
	PLATFORM = 5
};