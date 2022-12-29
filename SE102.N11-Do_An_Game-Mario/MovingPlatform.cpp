#include "MovingPlatform.h"

void CMovingPlatform::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	y += dt * vy;

	if (y < this->topBlock || y > this->bottomBlock) {
		vy = - vy;
	}
	//CGameObject::Update(dt, coObjects);
	//CCollision::GetInstance()->Process(this, dt, coObjects);
}

//void CMovingPlatform::Render() {
//	if (this->length <= 0) return;
//	float xx = x;
//	CSprites* s = CSprites::GetInstance();
//
//	s->Get(this->spriteIdBegin)->Draw(xx, y);
//	xx += this->cellWidth;
//	for (int i = 1; i < this->length - 1; i++)
//	{
//		s->Get(this->spriteIdMiddle)->Draw(xx, y);
//		xx += this->cellWidth;
//	}
//	if (length > 1)
//		s->Get(this->spriteIdEnd)->Draw(xx, y);
//
//	RenderBoundingBox();
//}