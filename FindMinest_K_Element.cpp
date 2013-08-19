#include <iostream>
#include "FindMinest_K_Element.h"
#include <vector>
using namespace std;
int* FindMinest_K_Element(
	 int *data,
	const int count,
	int k
	)
{
	if(!data||count<=0||k<=0||count<k)
	{
		std::cout<<"the input is illeage"<<endl;
		return NULL;
	}
	int begin=0;
	int end=count-1;
	int prek=QuickSortCore(data,begin,end);
	while(prek!=k)
	{
		if(prek<k)
		{
			begin=prek;
		}
		else
		{
			end=prek;
		}
		prek=QuickSortCore(data,begin,prek);
	}	
	int *outPut=new int [k];
	for(int i=0;i<k;i++)
	{
		outPut[i]=data[i];
	}
	return outPut;
}
int QuickSortCore( int * data,int begin,int end)
{
	int i,j,key;
	key=data[begin];
	i=begin;
	j=end;	
	while(i<j)
	{
		while(i<j&&key>data[j])
		{
			j--;	
		}
		if(i<j)
		{
			data[i]=data[j];
			i++;	
		}

		while(i<j&&key<=data[i])
		{
			i++;
		}
		if(i<j)
		{
			data[j]=data[i];	
			j--;
		}
	
	}
	data[i]=key;;
	return i;
}
void TestFindK()
{
	int data[]={1,2,3,4,5,6,7,9,0};
	int k=3;
	int *res=new int[3];
	res=FindMinest_K_Element(data,10,3);
	for(int i=0;i<k;i++)
	{
		std::cout<<res[i]<<'\t';
	}

}