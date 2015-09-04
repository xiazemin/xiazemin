#include <stdio.h>
#include <math.h>
#define  inf_distance 100001
#define dampfactor    10
#define  WrongNumber 100001


typedef struct  location
{
	int y;
	int x;
	int value;
	int dist;
	location operator =(location a)
	{
		dist=a.dist;
		value=a.value;
		x=a.x;
		y=a.y;
		return *this;
	}
	location()
	{

	}
	location(location &a)
	{
	    dist=a.dist;
		value=a.value;
		this->x=a.x;
		this->y=a.y;
	}
} location;
/*
________________right
|
|
|
|
|
|
up
*/

// up down left right
//up left   down left   up right  down right

void printMap(char Map[100][100],int H,int W )
{
	int i,j;
	for (i=0;i<H;i++)
	{
		for (j=0;j<W;j++)
		{
			printf("%c",Map[i][j]);
		}
		printf("\n");
		//delete []Map[i];
	}

	printf("\n\n");
}
void copyMap(char Map[100][100],char Map_copy[100][100],int H,int W )
{
	int i,j;
	for (i=0;i<H;i++)
	{
		for (j=0;j<W;j++)
		{
			Map_copy[i][j]=Map[i][j];
		}
		//delete []Map[i];
	}

	printf("\n\n");
}
int distance(int start[2],int end[2])
{
	return abs(start[0]-end[0])+abs(start[1]-end[1]);
}

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
void exchange(location&a,location&b)
{
	location temp;
	temp.dist=a.dist;
	temp.value=a.value;
	temp.x=a.x;
	temp.y=a.y;

	a.dist=b.dist;
	a.value=b.value;
	a.x=b.x;
	a.y=b.y;

	b.dist=temp.dist;
	b.value=temp.value;
	b.x=temp.x;
	b.y=temp.y;
}
//已i为根的最小堆
void MaxHeap(location A[10000],int i,int size)
{
	int l=LeftChild(i);
	int r=RightChild(i);
	int lest=0;
	if (l<size&&A[l].value<A[i].value)
	{
		lest=l;
	} 
	else
	{
		lest=i;
	}
	if (r<size&&A[r].value<A[lest].value)
	{
		lest=r;
	} 
	if (lest!=i)
	{
		exchange(A[i],A[lest]);
		MaxHeap(A,lest,size);
	}
}
//n/2+1 开始都是叶子节点
void BuildMaxHeap(location A[10000],int size)
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
void printHeap(location A[10000],int size)
{
	int k=2;
	int j=0;
	for (int i=0;i<size;i++)
	{
		printf("%d  ",A[i].value);
		if (i==((k<<j)-1-1))
		{
			printf("\n");
			j++;
		}
	}
	fflush(stdout);
}

void HeapSort(location A[10000],int size)
{
	BuildMaxHeap(A,size);
	for (int i=size-1;i>0;i--)//size(A)->2
	{
		exchange(A[0],A[i]);//1->i
		size=size-1;
		MaxHeap(A,0,size);//1->
	}
}
int HeapMinimum(location A[10000])
{
	return A[0].value;
}
location& HeapExtractMin(location A[10000],int &size,location&minimum)
{
	if (size<0)
	{
		minimum.value=inf_distance;
		minimum.value=inf_distance;
		minimum.x=-1;
		minimum.y=-1;
		return minimum; 
	}
	minimum.dist=A[0].dist;
	minimum.value=A[0].value;
	minimum.x=A[0].x;
	minimum.y=A[0].y;

	exchange(A[0],A[size-1]);
	size--;
	MaxHeap(A,0,size);
	return minimum;
}
void HeapIncreaseKey(location A[10000],int i,location &key,int size)
{
	if (key.value>A[i].value)
	{
		return ;
	}
	exchange(A[i],key);
	while(i>0&&A[parent(i)].value>A[i].value)
	{
		exchange(A[i],A[parent(i)]);
		i=parent(i);
	}
}
void MinHeapInsert(location A[10000],location &key,int& size)
{
	size++;
	location temp;
	temp.value=WrongNumber;
	exchange(A[size-1],temp);
	HeapIncreaseKey(A,size-1,key,size);
}

bool isReachable(int start[2],int direction[2],char map[100][100])
{
	if (map[start[0]+direction[0]][start[1]+direction[1]]=='#'||map[start[0]+direction[0]][start[1]+direction[1]]=='%'||map[start[0]+direction[0]][start[1]+direction[1]]=='$')
	{
		return false;
	} 
	else
	{
		return true;
	}
}
bool isHuisuable(int start[2],int direction[2],char map[100][100])
{
	if (map[start[0]+direction[0]][start[1]+direction[1]]=='#'||map[start[0]+direction[0]][start[1]+direction[1]]=='$')
	{
		return false;
	} 
	else
	{
		return true;
	}
}

/*
void getDistance(int start_star[2],int end[2],char map[100][100],int dis[8],int path0)
{	
	int direct[2];
	//up
	direct[0]=1;
	direct[1]=0;
	if (isReachable(start_star,direct,map))
	{
		int start[2];
		int path=path0+1;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[0]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[0]=inf_distance;
	}

	//down
	direct[0]=-1;
	direct[1]=0;
	if (isReachable(start_star,direct,map))
	{
		int start[2];
		int path=path0+1;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[1]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[1]=inf_distance;
	}
	//left
	direct[0]=0;
	direct[1]=-1;
	if (isReachable(start_star,direct,map))
	{
		int start[2];
		int path=path0+1;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[2]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[2]=inf_distance;
	}
	//right
	direct[0]=0;
	direct[1]=1;
	if (isReachable(start_star,direct,map))
	{
		int start[2];
		int path=path0+1;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[3]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[3]=inf_distance;
	}
	
	int direct1[2];
	int direct2[2];
	//up left 
	direct1[0]=1;
	direct1[1]=0;

	direct2[0]=0;
	direct2[1]=-1;

	direct[0]=1;
	direct[1]=-1;
	if (isReachable(start_star,direct,map)&&(isReachable(start_star,direct1,map)||isReachable(start_star,direct2,map)))
	{
		int start[2];
		int path=path0+2;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[4]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[4]=inf_distance;
	}
	//down left 
	direct1[0]=-1;
	direct1[1]=0;

	direct2[0]=0;
	direct2[1]=-1;

	direct[0]=-1;
	direct[1]=-1;
	if (isReachable(start_star,direct,map)&&(isReachable(start_star,direct1,map)||isReachable(start_star,direct2,map)))
	{
		int start[2];
		int path=path0+2;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[5]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[5]=inf_distance;
	}
	//up right 
	direct1[0]=1;
	direct1[1]=0;

	direct2[0]=0;
	direct2[1]=1;

	direct[0]=1;
	direct[1]=1;
	if (isReachable(start_star,direct,map)&&(isReachable(start_star,direct1,map)||isReachable(start_star,direct2,map)))
	{
		int start[2];
		int path=path0+2;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[6]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[6]=inf_distance;
	}
	//down right 
	direct1[0]=-1;
	direct1[1]=0;

	direct2[0]=0;
	direct2[1]=1;

	direct[0]=-1;
	direct[1]=1;
	if (isReachable(start_star,direct,map)&&(isReachable(start_star,direct1,map)||isReachable(start_star,direct2,map)))
	{
		int start[2];
		int path=path0+2;
		start[0]=start_star[0]+direct[0];
		start[1]=start_star[1]+direct[1];
		dis[7]=distance(start,end)+dampfactor*path;
	} 
	else
	{
		dis[7]=inf_distance;
	}
}
*/
int FourDirectionInHeap(char map[100][100],location Currentpoint,int end[2],location HeapValue[10000],int &HeapSize)
{
	int direct[2]={0,0};
	int point_temp[2];
	int cannotReach=0;
//up
	    direct[0]=1;
		direct[1]=0;
	point_temp[0]=Currentpoint.y;
	point_temp[1]=Currentpoint.x;
		if (isReachable(point_temp,direct,map))
		{
			location temp;
			point_temp[0]=point_temp[0]+direct[0];
			point_temp[1]=point_temp[1]+direct[1];
		   temp.value=dampfactor*(Currentpoint.dist+1)+distance(point_temp,end);	
		   temp.dist=Currentpoint.dist+1;
		   temp.y=point_temp[0];
		   temp.x=point_temp[1];
			MinHeapInsert(HeapValue,temp,HeapSize);
		}
		else
		{
			cannotReach++;
		}
//down
		direct[0]=-1;
		direct[1]=0;	
		point_temp[0]=Currentpoint.y;
		point_temp[1]=Currentpoint.x;
		if (isReachable(point_temp,direct,map))
		{
			location temp;
			point_temp[0]=point_temp[0]+direct[0];
			point_temp[1]=point_temp[1]+direct[1];
			temp.value=dampfactor*(Currentpoint.dist+1)+distance(point_temp,end);	
			temp.dist=Currentpoint.dist+1;
			temp.y=point_temp[0];
			temp.x=point_temp[1];
			MinHeapInsert(HeapValue,temp,HeapSize);
		}
		else
		{
			cannotReach++;
		}
//left
		direct[0]=0;
		direct[1]=-1;
		point_temp[0]=Currentpoint.y;
		point_temp[1]=Currentpoint.x;
		if (isReachable(point_temp,direct,map))
		{
			location temp;
			point_temp[0]=point_temp[0]+direct[0];
			point_temp[1]=point_temp[1]+direct[1];
			temp.value=dampfactor*(Currentpoint.dist+1)+distance(point_temp,end);	
			temp.dist=Currentpoint.dist+1;
			temp.y=point_temp[0];
			temp.x=point_temp[1];
			MinHeapInsert(HeapValue,temp,HeapSize);
		}
		else
		{
			cannotReach++;
		}
//right
		direct[0]=0;
		direct[1]=1;
		point_temp[0]=Currentpoint.y;
		point_temp[1]=Currentpoint.x;
		if (isReachable(point_temp,direct,map))
		{
			location temp;
			point_temp[0]=point_temp[0]+direct[0];
			point_temp[1]=point_temp[1]+direct[1];
			temp.value=dampfactor*(Currentpoint.dist+1)+distance(point_temp,end);	
			temp.dist=Currentpoint.dist+1;
			temp.y=point_temp[0];
			temp.x=point_temp[1];
			MinHeapInsert(HeapValue,temp,HeapSize);
		}
		else
		{
			cannotReach++;
		}
		if (cannotReach==4)
		{
			return 1;
		} 
		else
		{
			return 0;
		}
}

bool huiSu(location Currentpoint,int end[2],char map[100][100],location HeapValue[10000],int &HeapSize,int&distant)
{
	int direct[2]={0,0};
	int point_temp[2];
	int cannotReach=0;
	//up
	direct[0]=1;
	direct[1]=0;
	point_temp[0]=Currentpoint.y;
	point_temp[1]=Currentpoint.x;
	if (isHuisuable(point_temp,direct,map))
	{
		location temp;
		point_temp[0]=Currentpoint.y+direct[0];
		point_temp[1]=Currentpoint.x+direct[1];
		temp.value=dampfactor*(Currentpoint.dist)+distance(point_temp,end);	
		distant=temp.dist=Currentpoint.dist;
		temp.y=point_temp[0];
		temp.x=point_temp[1];
		MinHeapInsert(HeapValue,temp,HeapSize);
	}
	else
	{
		cannotReach++;
	}
	//down
	direct[0]=-1;
	direct[1]=0;	
	point_temp[0]=Currentpoint.y;
	point_temp[1]=Currentpoint.x;
	if (isHuisuable(point_temp,direct,map))
	{
		location temp;
		point_temp[0]=Currentpoint.y+direct[0];
		point_temp[1]=Currentpoint.x+direct[1];
		temp.value=dampfactor*(Currentpoint.dist)+distance(point_temp,end);	
		distant=temp.dist=Currentpoint.dist;
		temp.y=point_temp[0];
		temp.x=point_temp[1];
		MinHeapInsert(HeapValue,temp,HeapSize);
	}
	else
	{
		cannotReach++;
	}
	//left
	direct[0]=0;
	direct[1]=-1;
	point_temp[0]=Currentpoint.y;
	point_temp[1]=Currentpoint.x;
	if (isHuisuable(point_temp,direct,map))
	{
		location temp;
		point_temp[0]=Currentpoint.y+direct[0];
		point_temp[1]=Currentpoint.x+direct[1];
		temp.value=dampfactor*(Currentpoint.dist)+distance(point_temp,end);	
		distant=temp.dist=Currentpoint.dist;
		temp.y=point_temp[0];
		temp.x=point_temp[1];
		MinHeapInsert(HeapValue,temp,HeapSize);
	}
	else
	{
		cannotReach++;
	}
	//right
	direct[0]=0;
	direct[1]=1;
	point_temp[0]=Currentpoint.y;
	point_temp[1]=Currentpoint.x;
	if (isHuisuable(point_temp,direct,map))
	{
		location temp;
		point_temp[0]=Currentpoint.y+direct[0];
		point_temp[1]=Currentpoint.x+direct[1];
		temp.value=dampfactor*(Currentpoint.dist)+distance(point_temp,end);	
		distant=temp.dist=Currentpoint.dist;
		temp.y=point_temp[0];
		temp.x=point_temp[1];
		MinHeapInsert(HeapValue,temp,HeapSize);
	}
	else
	{
		cannotReach++;
	}
	if (cannotReach==4)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}
int search(location start,int end[2],char map[100][100],int& dist,location HeapValue[10000],int &HeapSize)
{
	if (start.y==end[0]&&start.x==end[1])
	{
		return start.dist;
	} 
	int needHuisu=FourDirectionInHeap(map,start,end,HeapValue,HeapSize);
	//printHeap(HeapValue,HeapSize);
	location CurrentLocation;
	CurrentLocation.dist=start.dist;
	CurrentLocation.value=start.value;
	CurrentLocation.x=start.x;
	CurrentLocation.y=start.y;
	if (needHuisu)
	{
		 map[start.y][start.x]='$';
		 int CantHuisu=huiSu(start,end,map,HeapValue,HeapSize,dist);
		 if (CantHuisu)
		 {
			 //return inf_distance;
			// dist++;
			 if (HeapSize==0)
			 {
				 return inf_distance;
			 } 
			 else
			 {

				 CurrentLocation=HeapExtractMin(HeapValue,HeapSize,CurrentLocation);
				 if (CurrentLocation.value==inf_distance)
				 {
					 return inf_distance;
				 }
			 }
		/*	 if (CurrentLocation.value==inf_distance)
			 {
				 return inf_distance;
			 }
			 else
			 {
				 dist=CurrentLocation.dist;
			 }*/
		 }
		 else		 
		 {
			// dist--;
			// flag++;
			 CurrentLocation=HeapExtractMin(HeapValue,HeapSize,CurrentLocation);
			 //map[CurrentLocation.y][CurrentLocation.y]='%';
			
		 } 
	}
	else
	{
		//dist++;
		 map[start.y][start.x]='%';
		 CurrentLocation=HeapExtractMin(HeapValue,HeapSize,CurrentLocation);
		 //if (CurrentLocation.value==inf_distance)
		 //{
			// //return inf_distance;
			// flag++;
		 //}
		
	}		
		/*printMap(map,10,7);
		fflush(stdout);*/
	if (CurrentLocation.value==inf_distance)
	{
		return inf_distance;
	}
	else
	{
		start=CurrentLocation;
		dist=start.dist;
		dist=search(start,end,map,dist,HeapValue,HeapSize);	
	}

	return dist;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int H,W;
	scanf("%d %d\n",&W,&H);
	int i,j,k=0;
	int S[2];//(y,x)
	int G[2];
	int checkPoints[18][2];
	char Map[100][100];
	char Map_copy[100][100];
	int distMatrix[100][100];
	location HeapValue[100*100];
	int HeapSize=0;
	if (W>0&&H>0)
	{
		//char **Map=new char*[H];
		for (i=0;i<H;i++)
		{
			//Map[i]=new char[W];
			for (j=0;j<W;j++)
			{
				HeapValue[i*W+j].dist=0;
				HeapValue[i*W+j].value=inf_distance;
				HeapValue[i*W+j].x=0;
				HeapValue[i*W+j].y=0;
				scanf("%c",&Map[i][j]);
				if (Map[i][j]=='S')
				{
					S[0]=i;
					S[1]=j;
				}
				else if (Map[i][j]=='G')
				{
					G[0]=i;
					G[1]=j;
				}
				else if (Map[i][j]=='@')
				{
					checkPoints[k][0]=i;
					checkPoints[k][1]=j;
					k++;
				}
			}
			scanf("\n");
		}

		printf("S:(%d,%d)\nG:(%d,%d)\n",S[0],S[1],G[0],G[1]);
		for (i=0;i<k;i++)
		{
			printf("@:(%d,%d)=>",checkPoints[i][0],checkPoints[i][1]);
		}
		printf("\n");
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				printf("%c",Map[i][j]);
			}
			printf("\n");
			//delete []Map[i];
		}
		//delete []Map;
		int dist=0;
		copyMap(Map,Map_copy,H,W);
		int start[2];
		int end[2];
		start[0]=S[0];
		start[1]=S[1];
		end[0]=G[0];
		end[1]=G[1];
		location StartLocation;
		StartLocation.y=start[0];
		StartLocation.x=start[1];
		StartLocation.dist=0;
		StartLocation.value=inf_distance;
		printf("%d\n", search(StartLocation,end,Map_copy,dist,HeapValue,HeapSize));
		printMap(Map_copy,H,W);

		int canReach=1;
		for (i=0;i<k;i++)
		{
			for (j=0;j<i;j++)
			{
				copyMap(Map,Map_copy,H,W);
				printf("(%d,%d)=>(%d,%d)",checkPoints[i][0],checkPoints[i][1],checkPoints[j][0],checkPoints[j][1]);
				fflush(stdout);
				start[0]=checkPoints[i][0];
				start[1]=checkPoints[i][1];
				end[0]=checkPoints[j][0];
				end[1]=checkPoints[j][1];
				dist=0;
				Map_copy[start[0]][start[1]]='%';
				StartLocation.y=start[0];
				StartLocation.x=start[1];
				StartLocation.dist=0;
				StartLocation.value=inf_distance;
				printf("%8d \n",distMatrix[i][j]=search(StartLocation,end,Map_copy,dist,HeapValue,HeapSize));
				printMap(Map_copy,H,W);
				if (distMatrix[i][j]==inf_distance)
				{
					printf("can't reach\n");
					canReach=0;
					break;
				}
			}
			printf("\n");
			if (!canReach)
			{
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}