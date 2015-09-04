#include <stdio.h>
#include <math.h>
#define  inf_distance 100001
#define dampfactor    100

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

bool chooseDirection(int dis[8],int direc[2])
{
	int i,j,temp=inf_distance;
	j=0;
	int flag=0;
	for (i=0;i<8;i++)
	{
      if (temp>dis[i])
      {
		  temp=dis[i];
		  j=i;
      } 
	}
	if (temp==inf_distance)
	{
      direc[0]=0;
	  direc[1]=0;
	} 
	else
	{
		switch (j)
		{
		case 0:
			direc[0]=1;
			direc[1]=0;
			break;
		case 1:
			direc[0]=-1;
			direc[1]=0;
			break;
		case 2:
			direc[0]=0;
			direc[1]=-1;
			break;
		case 3:
			direc[0]=0;
			direc[1]=1;
			break;
		case 4://up left
			direc[0]=1;
			direc[1]=-1;
			flag=1;
			break;
		case 5:// down left
			direc[0]=-1;
			direc[1]=-1;
			flag=1;
			break;
		case 6:// up right
			direc[0]=1;
			direc[1]=1;
			flag=1;
			break;
		case 7:// down right
			direc[0]=-1;
			direc[1]=1;
			flag=1;
			break;
		default:
			direc[0]=0;
			direc[1]=0;
			break;
		}
	}
	return flag;
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
	if (map[start[0]+direction[0]][start[1]+direction[1]]!='#'&&map[start[0]+direction[0]][start[1]+direction[1]]!='$')
	{
		return true;
	} 
	else
	{
		return false;
	}
}
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
bool huiSu(int start[2],int end[2],char map[100][100],int direct[2],int path0)
{
	int dist[8]={inf_distance,inf_distance,inf_distance,inf_distance,inf_distance,inf_distance,inf_distance,inf_distance};
	int start_temp[2];
	int directions[2];
	//up
	directions[0]=1;
	directions[1]=0;
	if (isHuisuable(start,directions,map))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+1;
		dist[0]=distance(start_temp,end)+dampfactor*path;
	}
	//down
	directions[0]=-1;
	directions[1]=0;
	if (isHuisuable(start,directions,map))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+1;
		dist[1]=distance(start_temp,end)+dampfactor*path;
	}
	//left
	directions[0]=0;
	directions[1]=-1;
	if (isHuisuable(start,directions,map))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+1;
		dist[2]=distance(start_temp,end)+dampfactor*path;
	}
	//right
	directions[0]=0;
	directions[1]=1;
	if (isHuisuable(start,directions,map))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+1;
		dist[3]=distance(start_temp,end)+dampfactor*path;
	}

	int directions1[2];
	int directions2[2];
	//up left
	directions1[0]=1;
	directions1[1]=0;
	directions2[0]=0;
	directions2[1]=-1;
	directions[0]=1;
	directions[1]=-1;
	if (isHuisuable(start,directions,map)&&(isHuisuable(start,directions1,map)||isHuisuable(start,directions2,map)))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+2;
		dist[4]=distance(start_temp,end)+dampfactor*path;
	}
	//down left
	directions1[0]=-1;
	directions1[1]=0;
	directions2[0]=0;
	directions2[1]=-1;
	directions[0]=-1;
	directions[1]=-1;
	if (isHuisuable(start,directions,map)&&(isHuisuable(start,directions1,map)||isHuisuable(start,directions2,map)))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+2;
		dist[5]=distance(start_temp,end)+dampfactor*path;
	}
	//up right
	directions1[0]=1;
	directions1[1]=0;
	directions2[0]=0;
	directions2[1]=1;
	directions[0]=1;
	directions[1]=1;
	if (isHuisuable(start,directions,map)&&(isHuisuable(start,directions1,map)||isHuisuable(start,directions2,map)))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+2;
		dist[6]=distance(start_temp,end)+dampfactor*path;
	}
	//down right
	directions1[0]=-1;
	directions1[1]=0;
	directions2[0]=0;
	directions2[1]=1;
	directions[0]=-1;
	directions[1]=1;
	if (isHuisuable(start,directions,map)&&(isHuisuable(start,directions1,map)||isHuisuable(start,directions2,map)))
	{
		start_temp[0]=start[0]+directions[0];
		start_temp[1]=start[1]+directions[1];
		int path=path0+2;
		dist[7]=distance(start_temp,end)+dampfactor*path;
	}

	return chooseDirection(dist,direct);
}

int search(int start[2],int end[2],char map[100][100],int& dist)
{
	if (start[0]==end[0]&&start[1]==end[1])
	{
		return dist;
	} 
	int dis[8]={inf_distance,inf_distance,inf_distance,inf_distance,inf_distance,inf_distance,inf_distance,inf_distance};	
	getDistance(start,end,map,dis,dist);
	int direc[2];
	int flag=chooseDirection(dis,direc);
	if (direc[0]==0&&direc[1]==0)
	{
         map[start[0]][start[1]]='$';
		int flag1=huiSu(start,end,map,direc,dist);
		 if (direc[0]==0&&direc[1]==0)
		 {
			 return inf_distance;
		 }
		 else
		 {
			 if (flag1)
			 {
				//dist+=2;
				 dist-=2;
				 int direct22[2];
				 direct22[0]=direc[0];
				 direct22[1]=0;
				 if (isHuisuable(start,direct22,map))
				 {
                      map[start[0]+direc[0]][start[1]]='$';
				 } 
				 else
				 {
					   map[start[0]][start[1]+direc[1]]='$';
				 }
				 // map[start[0]+direc[0]][start[1]+direc[1]]='$';
			 }
			 else
			 {
                 //dist++;
				 dist--;
				// map[start[0]+direc[0]][start[1]+direc[1]]='$';
			 }
			
			 start[0]+=direc[0];
			 start[1]+=direc[1];
			// map[start[0]][start[1]]='$';
			// printMap(map,8,7);
			 search(start,end,map,dist);

		 }
	} 
	else
	{
		if (flag)
		{
			dist+=2;
			int direct22[2];
			direct22[0]=direc[0];
			direct22[1]=0;
			if (isReachable(start,direct22,map))
			{
				map[start[0]+direc[0]][start[1]]='%';
			} 
			else
			{
				map[start[0]][start[1]+direc[1]]='%';
			}
			map[start[0]+direc[0]][start[1]+direc[1]]='%';
		}
		else
		{
			dist++;
			map[start[0]+direc[0]][start[1]+direc[1]]='%';
		}
		start[0]+=direc[0];
		start[1]+=direc[1];
		
	/*	printMap(map,8,7);
		fflush(stdout);*/
		search(start,end,map,dist);
	}
	
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
	if (W>0&&H>0)
	{
		//char **Map=new char*[H];
		for (i=0;i<H;i++)
		{
			//Map[i]=new char[W];
			for (j=0;j<W;j++)
			{
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
		printf("%d\n", search(start,end,Map_copy,dist));
		printMap(Map_copy,H,W);


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
				printf("%8d \n",distMatrix[i][j]=search(start,end,Map_copy,dist));
				printMap(Map_copy,H,W);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
}