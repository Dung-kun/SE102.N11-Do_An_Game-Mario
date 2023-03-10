#ifndef __GRID_H__
#define	__GRID_H__

#include "Game.h" 
//#include "GSprite.h"  
//#include "Torch.h"
#include "Brick.h"
#include "define.h"
#include "Coin.h"
#include "Platform.h"
//#include "ObjectHidden.h"
//#include "Candle.h"
//#include "StairTop.h"
//#include "StairBottom.h"
//#include "Gate.h"

using namespace std;

#define GRID_CELL_WIDTH (SCREEN_WIDTH/4.0f)
#define GRID_CELL_HEIGHT (SCREEN_HEIGHT/4.0f)

#define GRID_INSERT_OBJECT__DIXUONGHONUOC_LEFT 41, eType::OBJECT_HIDDEN, -1, 3190 ,423, 40, 10, 0 // object ẩn đụng vào sẽ đi xuống hồ nước, phía trái
#define GRID_INSERT_OBJECT__DIRAKHOIHONUOC_LEFT 45, eType::OBJECT_HIDDEN, -1, 3135, 435, 20, 20, 0 // object ẩn đụng vào sẽ đi ra khỏi hồ nước, phía trái

#define GRID_INSERT_OBJECT__DIXUONGHONUOC_RIGHT 86, eType::OBJECT_HIDDEN, -1, 3835, 423, 25, 10, 0 // object ẩn đụng vào sẽ đi ra khỏi hồ nước, phía trái
#define GRID_INSERT_OBJECT__DIRAKHOIHONUOC_RIGHT 81, eType::OBJECT_HIDDEN, -1, 3807, 460, 30, 20, 0 // object ẩn đụng vào sẽ đi ra khỏi hồ nước, phía trái

#define GRID_CELL_MAX_ROW 40 // số dòng tối đa;
#define GRID_CELL_MAX_COLUMN 200 // số cột tối đa


class CGrid
{
private:
	vector<CGameObject*> cells[GRID_CELL_MAX_ROW][GRID_CELL_MAX_COLUMN];


public:
	CGrid();
	~CGrid();

	void Clear();


	CGameObject* GetNewObject(int type, float x, float y, int w, int h, int Model);
	void Insert(int id, int type, int direction, float x, float y, int w, int h, int Model); //Thêm object vào grid
	void Insert(CGameObject* obj); //Thêm object vào grid
	void GetListObject(vector<CGameObject*>& ListObj);
	void UpdateGrid(vector<CGameObject*>& ListObj);
};

#endif