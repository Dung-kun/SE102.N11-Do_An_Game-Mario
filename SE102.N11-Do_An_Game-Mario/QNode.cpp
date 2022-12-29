#include "QNode.h"

CQNode::CQNode()
{}

//lấy danh sách các đối tượng trong node
vector<CGameObject*> CQNode::getListObjInNode()
{
	return listObjectInNode;
}

//lấy giá trị của một số thuộc tính của lớp quadnode (nodeid, số lượng node, số lượng đối tượng)
int CQNode::getNodeID()
{
	return nodeID;
}

int CQNode::getNumNode()
{
	return num_node;
}

int CQNode::getNumObj()
{
	return num_obj;
}


bool CQNode::IntersectsWith(float obj_x, float obj_y, float obj_w, float obj_h) {
	return (obj_x + obj_w > x) && (x + w > obj_x) && (obj_y + obj_h > y) && (y + h > obj_y);
}