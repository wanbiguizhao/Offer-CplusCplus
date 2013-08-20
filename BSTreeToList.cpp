// BSTreeToList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct BSTreeNode
{
	int m_nValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
};
BSTreeNode* ConvertNodeCore(BSTreeNode * head,bool asLeftSon)
{
	if(head==NULL)
		return NULL;


	BSTreeNode* p_node=NULL;
	p_node=ConvertNodeCore(head->m_pLeft,true);
	if(!p_node)
	{
		p_node->m_pRight=head;
		head->m_pLeft=p_node;
	}
	p_node=ConvertNodeCore(head->m_pRight,false);
	if(!p_node)
	{
		p_node->m_pLeft=head;
		head->m_pRight=p_node;		
	}

	if(!asLeftSon)
	{
		BSTreeNode* p_post=head;
		while(p_post->m_pRight)
		{
			p_post=p_post->m_pRight->m_pRight;
		}
		return p_post;
	}else
	{
			BSTreeNode* p_pre=NULL;
			while(p_pre->m_pLeft)
				p_pre=p_pre->m_pLeft;
			return p_pre;
	}
}
BSTreeNode *ConvertNode(BSTreeNode *head)
{
	if(!head)
		return NULL;
	
	BSTreeNode* p_post=NULL;
	BSTreeNode* p_pre=NULL;
	p_pre=ConvertNodeCore(head->m_pLeft,true);
	p_post=ConvertNodeCore(head->m_pRight,false);

	p_pre->m_pRight=head;
	head->m_pLeft=p_pre;

	head->m_pRight=p_post;
	p_post=head->m_pRight;

	while(!p_pre->m_pLeft)
		p_pre=p_pre->m_pLeft;
	return p_pre;
}
