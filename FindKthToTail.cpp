#include "FindKthToTail.h"
using namespace std;
ListNode* FindKthToTail(ListNode *head,int k)
{
	if(!head||k<1)
		return NULL;
	int Count=0;
	ListNode *p=head;
	ListNode *q=head;
	while(p!=NULL&&Count< k)
	{
		Count++;
		p=p->m_pNext;
	}
	if(Count>=k)
	{
		q=head;
	}
	else
		return NULL;
	while(p)
	{
		p=p->m_pNext;
		q=q->m_pNext;
	}
	return q;
}
void TestFindKthToTail()
{
	ListNode *head=new ListNode();
	ListNode *p=NULL;
	p=head;
	for(int i=10;i>1;i--)
	{
		p->m_nKey=i;
		p->m_pNext=new ListNode();
		p=p->m_pNext;
	}
	p->m_nKey=1;
	p->m_pNext=NULL;
	for(int i=5;i<15;i++)
	{
		p=FindKthToTail(head,i); 
		if(p)
			cout<<"<"<<i<<","<<p->m_nKey<<">"<<endl;
		else
			cout<<"<"<<i<<","<<"??"<<">"<<endl;
	}
}