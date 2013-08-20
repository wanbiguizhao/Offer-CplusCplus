#include "stdafx.h"
#include "FindPath.h"

using namespace std;
void FindPath(
BinaryTreeNode* pTreeNode,
int expectedSum,
std::vector<int>&path,
int& currentSum
)
{
    if(!pTreeNode)
		return;
	currentSum+=pTreeNode->m_nValue;
	path.push_back(pTreeNode->m_nValue);
	bool isLeaf=(!pTreeNode->m_pLeft&&!pTreeNode->m_pRight);
	if(isLeaf&&currentSum==expectedSum)
	{
		for (std::vector<int>::iterator i = path.begin(); i != path.end(); ++i)
		{
			std::cout<<*i<<'\t';
		}
		std::cout<<std::endl;
	}
	if(pTreeNode->m_pLeft)
    	FindPath(pTreeNode->m_pLeft,expectedSum,path,currentSum);
    if(pTreeNode->m_pRight)
    	FindPath(pTreeNode->m_pRight,expectedSum,path,currentSum);
    path.pop_back();
	currentSum-=pTreeNode->m_nValue;
}
void TestFindPath()
{
	BinaryTreeNode* root=new BinaryTreeNode();
	BinaryTreeNode* PLS=new BinaryTreeNode();
	BinaryTreeNode* PRS=new BinaryTreeNode();
	root->m_nValue=10;
		root->m_pRight=PRS;
		root->m_pLeft=PLS;
		PLS->m_nValue=5;
		PRS->m_nValue=12;
		PRS->m_pRight=NULL;
		PRS->m_pLeft=NULL;	
			
			PLS->m_pLeft=new BinaryTreeNode();
			PLS->m_pRight=new BinaryTreeNode();
				PRS=PLS->m_pRight;
				PLS=PLS->m_pLeft;

				PLS->m_nValue=4;
				PLS->m_pRight=NULL;
				PLS->m_pLeft=NULL;


				PRS->m_nValue=7;	
				PRS->m_pRight=NULL;
				PRS->m_pLeft=NULL;	
		int currentSum=0;
		int expectedSum=22;
		std::vector<int> path;
		FindPath(root,expectedSum,path,currentSum);
}