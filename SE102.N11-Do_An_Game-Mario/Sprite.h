#pragma once

#include "Texture.h"
#include "Game.h"



#define BBOX_ALPHA 0.25f

class CSprite
{
	int id;				// Sprite ID in the sprite database

	int left;
	int top;
	int right;
	int bottom;

	LPTEXTURE texture;
	D3DX10_SPRITE sprite;
	D3DXMATRIX matScaling;
public:
	CSprite(int id, int left, int top, int right, int bottom, LPTEXTURE tex);

	void Draw(float x, float y, string tile = "OBJECT");
};

typedef CSprite* LPSPRITE;

