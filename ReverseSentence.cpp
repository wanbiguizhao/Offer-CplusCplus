#include "ReverseSentence.h"
using namespace std;

void Reverse(char *pBegin,char *pEnd)
{
	if(!pBegin||!pEnd)
		return;
	while(pBegin<pEnd)
	{
		char temp;
		temp=*pBegin;
		*pBegin=*pEnd;
		*pEnd=temp;
		pBegin++;
		pEnd--;
	}
}
char* ReverseSentence(char *pData)
{
	if(!pData)
		return NULL;
	char *pBegin=pData;
	char *pEnd=pData;
	while(*pEnd!='\0')
	{
		pEnd++;
	}
	pEnd--;
	Reverse(pData,pEnd);
	pBegin=pEnd=pData;
	while(*pBegin!='\0')
	{
		if(' '==*pBegin)
		{
			pBegin++;
			pEnd++;
			continue;
		}
		else if(*pEnd==' '||*pEnd=='\0')
		{
			Reverse(pBegin,--pEnd);
			pBegin=++pEnd;
		}
		else
		{
			pEnd++;
		}				
	}
	return pData;
}
void TestReverseSentence()
{
	char pData[]="i am a student. ";
	cout<<pData<<endl;
	cout<<"##########"<<endl;
	char *rData=ReverseSentence(pData);
	cout<<pData<<endl;
	char key;
	cin>>key;
}
