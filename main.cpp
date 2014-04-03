#include <stdio.h>
#include "xlist.h"

int main()
{
	int i,*val ;
	XList <int> *A, *B=0;
	A=new XList <int>;
	for(i=200;i>0;--i)
	{
		val=new int(i);
		A->AddFirst(val);
		
	}
	for(i=0;i<5;++i)
	{
		A->RemoveLast();
	}
	
	printf("%d ",A->Length());
	
	for(A->BeginTrace();A->GoBackward();)
		{
		printf("%d ",A->GetCurrentValue()[0]);
		}

	printf("\n\n------------\n");

	A->ClearXList();

	val=new int(32767);
		A->AddFirst(val);

		A->RemoveFirst();
		printf("%d",!A->CheckEmpty());
	
	delete A;
	return 0;
}