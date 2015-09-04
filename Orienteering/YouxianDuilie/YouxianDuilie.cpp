#include <stdio.h>
#define  WrongNumber 10001

int parent(int i)
{
	return (i+1)/2-1;
}

int LeftChild(int i)
{
	return 2*(i+1)-1;
}

int RightChild(int i)
{
	return 2*(i+1)+1-1;
}
void exchange(int&a,int&b)
{
	int temp=a;
	a=b;
	b=temp;
}
//已i为根的最大堆
void MaxHeap(int A[100],int i,int size)
{
	int l=LeftChild(i);
	int r=RightChild(i);
	int largest=0;
	if (l<size&&A[l]>A[i])
	{
		largest=l;
	} 
	else
	{
		largest=i;
	}
	if (r<size&&A[r]>A[largest])
	{
		largest=r;
	} 
	if (largest!=i)
	{
       exchange(A[i],A[largest]);
	   MaxHeap(A,largest,size);
	}
}
//n/2+1 开始都是叶子节点
void BuildMaxHeap(int A[100],int size)
{
	for (int i=size/2-1;i>=0;i--)
	{
		MaxHeap(A,i,size);
	}
}
//int Mod2n(int i)
//{
//	int k=i%2;
//	if (k==1)
//	{
//		return 0;
//	}
//	else
//	{
//		i=i/2;
//		if (i==1)
//		{
//			return 1;
//		}
//	  while (i!=0)
//	  {
//		  k=i%2;
//		  if (k==1)
//		  {
//			  return 0;
//		  }
//		  else
//		  {
//			    i=i/2;
//				if (i==1)
//				{
//					return 1;
//				}
//		  }
//	  }
//	}
//		return 1;
//}
void printHeap(int A[100],int size)
{
	int k=2;
	int j=0;
	for (int i=0;i<size;i++)
	{
		printf("%d  ",A[i]);
		if (i==((k<<j)-1-1))
		{
			printf("\n");
			j++;
		}
	}
}

void HeapSort(int A[100],int size)
{
	BuildMaxHeap(A,size);
	for (int i=size-1;i>0;i--)//size(A)->2
	{
		exchange(A[0],A[i]);//1->i
		size=size-1;
		MaxHeap(A,0,size);//1->
	}
}
int HeapMaximum(int A[100])
{
	return A[0];
}
int HeapExtractMax(int A[100],int &size)
{
	if (size<1)
	{
		return WrongNumber; 
	}
	int maximum=A[0];
	A[0]=A[size-1];
	size--;
	MaxHeap(A,0,size);
	return maximum;
}
void HeapIncreaseKey(int A[100],int i,int key,int size)
{
	if (key<A[i])
	{
		return ;
	}
	A[i]=key;
	while(i>0&&A[parent(i)]<A[i])
	{
		exchange(A[i],A[parent(i)]);
		i=parent(i);
	}
}
void MaxHeapInsert(int A[100],int key,int& size)
{
	size++;
	A[size-1]=-WrongNumber;
	HeapIncreaseKey(A,size-1,key,size);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	/*for (int i=0;i<=16;i++)
	{
		printf("%d:%d\n",i,Mod2n(i));
	}*/
	int N;
	int A[100];
	scanf("%d",&N);
	if (N>0)
	{
		for (int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		
		HeapSort(A,N);
		printHeap(A,N);
		printHeap(A,N);
		printf("\n");
		BuildMaxHeap(A,N);
		printHeap(A,N);
		printf("\n%d\n",N);
		printf("\nmax:%d \n",HeapExtractMax(A,N));
		printf("before insert:%d\n",N);
		printf("\n");
		MaxHeapInsert(A,20,N);
		printHeap(A,N);
		printf("\nafter insert%d\n",N);
		printf("\nmax:%d   %d\n",HeapExtractMax(A,N),N);
		printf("\nafter extract%d\n",N);

	}

	fclose(stdin);
	fclose(stdout);
}