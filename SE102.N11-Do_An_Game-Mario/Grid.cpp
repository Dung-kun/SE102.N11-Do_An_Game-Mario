#include "Grid.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "Define.h"
#include "debug.h"



CGrid::CGrid()
{
	//for (int i = 0; i < GRID_CELL_MAX_ROW; i++)
	//	for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
	//	{
	//		cells[i][j].clear();
	//	}
}


CGrid::~CGrid()
{
	for (int i = 0; i < GRID_CELL_MAX_ROW; i++)
		for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
		{
			cells[i][j].clear();
		}
}


void CGrid::Clear()
{
	for (int i = 0; i < GRID_CELL_MAX_ROW; i++)
		for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
		{
			cells[i][j].clear();
		}
}

CGameObject* CGrid::GetNewObject(int type, float x, float y, int w, int h, int Model)
{
	switch (type)
	{
	case eType::BRICK:
		return new CBrick(x, y);

	case eType::COIN:
		return new CCoin(x, y);

	//case eType::PLATFORM:
	//	return new CPlatform(x, y, w, h);
	}
	return NULL;
}

void CGrid::GetListObject(vector<CGameObject*>& ListObj)
{

	ListObj.clear();
	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);
	unordered_map<int, CGameObject*> mapObject;

	int bottom = (int)((cy + SCREEN_HEIGHT + 1) / GRID_CELL_HEIGHT);
	int top = (int)((cy - 1) / GRID_CELL_HEIGHT);

	int left = (int)((cx - 1) / GRID_CELL_WIDTH);
	int right = (int)((cx + SCREEN_WIDTH + 1) / GRID_CELL_WIDTH);

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++) {
			for (UINT k = 0; k < cells[i][j].size(); k++)
			{
				if (!cells[i][j].at(k)->IsDeleted()) // còn tồn tại
				{
					ListObj.push_back(cells[i][j].at(k));
				}
				else
				{
					//cells[i][j].at(k) = nullptr;
					//cells[i][j].erase(cells[i][j].begin() + k); 
				}
			}
		}

	//for (auto& x : mapObject)
	//{
	//	ListObj.push_back(x.second);
	//}
}

void CGrid::Insert(int id, int type, int direction, float x, float y, int w, int h, int Model)
{
	int top = (int)(y / GRID_CELL_HEIGHT);
	int bottom = (int)((y + h) / GRID_CELL_HEIGHT);
	int left = (int)(x / GRID_CELL_WIDTH);
	int right = (int)((x + w) / GRID_CELL_WIDTH);

	CGameObject* obj = GetNewObject(type, x, y, w, h, Model);
	if (obj == NULL)
		return;

	//obj->SetId(id);
	//obj->SetDirection(direction);

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			cells[i][j].push_back(obj);
}

void CGrid::Insert(CGameObject* obj)
{
	float l, t, r, b;


	obj->GetBoundingBox(l, t, r, b);
	int top = (int)(t / GRID_CELL_HEIGHT);
	int bottom = (int)(b / GRID_CELL_HEIGHT);
	int left = (int)(l / GRID_CELL_WIDTH);
	int right = (int)(r / GRID_CELL_WIDTH);


	if (obj == NULL)
		return;

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++) {
			cells[i][j].push_back(obj);
		}

}

void CGrid::UpdateGrid(vector<CGameObject*>& ListObj)
{
	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);
	unordered_map<int, CGameObject*> mapObject;

	int index = 0;

	int bottom = (int)((cy + SCREEN_HEIGHT + 1) / GRID_CELL_HEIGHT);
	int top = (int)((cy - 1) / GRID_CELL_HEIGHT);

	int left = (int)((cx - 1) / GRID_CELL_WIDTH);
	int right = (int)((cx + SCREEN_WIDTH + 1) / GRID_CELL_WIDTH);

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++) {
			for (UINT k = 0; k < cells[i][j].size(); k++)
			{
				if (index >= ListObj.size()) return;
				if ((!cells[i][j].at(k)->IsDeleted()) && cells[i][j].at(k)->isAlive()) // còn tồn tại
				{
					float l, t, r, b;
					ListObj.at(index)->GetBoundingBox(l, t, r, b);
					int topObj = (int)(t / GRID_CELL_HEIGHT);
					int bottomObj = (int)(b / GRID_CELL_HEIGHT);
					int leftObj = (int)(l / GRID_CELL_WIDTH);
					int rightObj = (int)(r / GRID_CELL_WIDTH);
					if ((topObj < top || bottomObj > bottom || leftObj < left || rightObj > right)) {
						cells[i][j].erase(cells[i][j].begin() + k);
						this->Insert(ListObj[index++]);
						--k;
					}
				}
			}
		}

	//for (auto& x : mapObject)
	//{
	//	ListObj.push_back(x.second);
	//}
}