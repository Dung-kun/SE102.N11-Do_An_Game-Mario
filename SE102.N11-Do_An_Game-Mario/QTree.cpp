#include "QTree.h"

//lấy danh sách toàn bộ đối tượng từ map
//void QTree::getListObject(vector<CGameObject*> listObj)
//{
//	this->listObj = listObj;
//}

void CQTree::FindNodeInView(CQNode* node)
{
	if (node == NULL)
		return;

	//kiểm tra node có nằm trong khoảng của camera hay không
	float cam_x, cam_y, sw, sh;
	CGame::GetInstance()->GetCamPos(cam_x, cam_y);
	sw = CGame::GetInstance()->GetBackBufferWidth();
	sh = CGame::GetInstance()->GetBackBufferHeight();
	if (node->IntersectsWith(cam_x, cam_y, sw, sh))
		return;

	if (node->getNumNode() == 4)
	{
		FindNodeInView(node->tl);
		FindNodeInView(node->tr);
		FindNodeInView(node->bl);
		FindNodeInView(node->br);
		return;
	}
	if (node->getListObjInNode().size() == 0)
		return;

	//đưa toàn bộ đối tượng có trong node lá hiện thời vào ListNode của camera

}

CQNode* CQTree::getRootNode()
{
	return root_node;
}

void CQTree::Delete(CQNode* node)
{
	if (node->tl != NULL)
		Delete(node->tl);
	if (node->tr != NULL)
		Delete(node->tr);
	if (node->bl != NULL)
		Delete(node->tl);
	if (node->br != NULL)
		Delete(node->tl);
	if (node->tl == NULL && node->tr == NULL && node->bl == NULL && node->br == NULL)
	{
		delete node;
		node = nullptr;
	}
}

CQTree::~CQTree()
{}