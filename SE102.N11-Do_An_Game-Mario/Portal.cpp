#include "Portal.h"
#include "Game.h"
#include "Textures.h"

CPortal::CPortal(float l, float t, float r, float b, int scene_id, int spriteId)
{
	this->scene_id = scene_id;
	this->spriteId = spriteId;
	x = l; 
	y = t;
	width = r - l;
	height = b - t;
}

void CPortal::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);

	CGame::GetInstance()->Draw(x - cx, y - cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

void CPortal::Render()
{
	float xx = x;
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteId)->Draw(xx, y);
	RenderBoundingBox();
}

void CPortal::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - width/2;
	t = y - height/2;
	r = x + width/2;
	b = y + height/2;
}