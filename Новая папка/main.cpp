#include <stdio.h>
#include "xlist.h"

int main()
{
	int i;
	XList <int> testlist;

	for(i=200; i>0; --i)
		testlist.AddFirst(i);

	for(i=0;i<5;++i)
		testlist.RemoveLast();
	
	printf("%d ",testlist.Length());
	
	for(testlist.BeginTrace(); testlist.GoBackward();)
		printf("%d ",testlist.GetCurrentValue());

	printf("\n\n------------\n");

	testlist.ClearXList();
	testlist.AddFirst(32767);
	printf("%d\n",testlist.Length());

	testlist.RemoveFirst();
	printf("%d",!testlist.CheckEmpty());
	
	return 0;
}