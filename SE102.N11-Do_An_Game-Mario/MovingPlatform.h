#pragma once
#include "Platform.h"

class CMovingPlatform :
    public CPlatform
{
protected:
    float topBlock;
    float bottomBlock;
    /*float leftBlock;
    float rightBlock;*/

public:
	CMovingPlatform(float x, float y,
		float cell_width, float cell_height, int length,
		float top_block, float bottom_block,
		int sprite_id_begin, int sprite_id_middle, int sprite_id_end) :CPlatform(x, y, cell_width, cell_height, length, sprite_id_begin, sprite_id_middle, sprite_id_end)
	{
		this->topBlock = top_block;
		this->bottomBlock = bottom_block;
		this->vy = 0.1f;
	}

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	//virtual void Update(DWORD dt);
};

class MovingPlatform
{
};

