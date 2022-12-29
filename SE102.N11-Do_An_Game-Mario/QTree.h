#pragma once
#include "QNode.h"

class CQTree
{

private:
	RECT rect;
	vector<CQNode*> listNodeInView;
	vector<CGameObject*> listObjectInView;
	CQNode* root_node;

public:
	CQTree();

	//lấy danh sách toàn bộ đối tượng từ map
	void getListObject(vector<CGameObject*> listObj);

	//lấy node gốc
	CQNode* getRootNode();
	void FindNodeInView(CQNode* node);
	void Delete(CQNode* node);

	//destructor of QuadTree class
	~CQTree();
};

