#pragma once
#include "GameObject.h"
#include <vector>
class CQNode
{
private:
	int nodeID;
	float x, y, w, h;
	int num_node;
	int num_obj;

	vector<CGameObject*> listObjectInNode;
	RECT* rect;

public:
	int level;
	CQNode* tl;
	CQNode* tr;
	CQNode* bl;
	CQNode* br;
	CQNode* parent;

	CQNode();
	int getNodeID();
	int getNumObj();
	int getNumNode();
	void getBoundingBox();
	bool IntersectsWith(float, float, float, float);
	vector<CGameObject*> getListObjInNode();
};

