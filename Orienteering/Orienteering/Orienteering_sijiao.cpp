#include <stdio.h>
#include <math.h>
#define  inf_distance 10001

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

void chooseDirection(int dis[4],int direc[2])
{
	int i,j,temp=inf_distance;
	j=0;
	for (i=0;i<4;i++)
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
		default:
			direc[0]=0;
			direc[1]=0;
			break;
		}
	}
}

void getDistance(int start_star[2],int end[2],char map[100][100],int dis[4])
{	
	//up
	start_star[0]++;
	if(map[start_star[0]][start_star[1]]=='#'||map[start_star[0]][start_star[1]]=='%'||map[start_star[0]][start_star[1]]=='$')
	{
		dis[0]=inf_distance;
	}
	else
	{
		dis[0]=distance(start_star,end);
	}

	start_star[0]--;
	//down
	start_star[0]--;
	if(map[start_star[0]][start_star[1]]=='#'||map[start_star[0]][start_star[1]]=='%'||map[start_star[0]][start_star[1]]=='$')
	{
		dis[1]=inf_distance;
	}
	else
	{
		dis[1]=distance(start_star,end);
	}
	start_star[0]++;
	//left
	start_star[1]--;
	if(map[start_star[0]][start_star[1]]=='#'||map[start_star[0]][start_star[1]]=='%'||map[start_star[0]][start_star[1]]=='$')
	{
		dis[2]=inf_distance;
	}
	else
	{
		dis[2]=distance(start_star,end);
	}
	start_star[1]++;
	//right
	start_star[1]++;
	if(map[start_star[0]][start_star[1]]=='#'||map[start_star[0]][start_star[1]]=='%'||map[start_star[0]][start_star[1]]=='$')
	{
		dis[3]=inf_distance;
	}
	else
	{
		dis[3]=distance(start_star,end);
	}
	start_star[1]--;
}
void huiSu(int start[2],int end[2],char map[100][100],int direct[2])
{
	int dist[4]={inf_distance,inf_distance,inf_distance,inf_distance};
	int start_temp[2];
	//up
	if (map[start[0]+1][start[1]]!='#'&&map[start[0]+1][start[1]]!='$')
	{
		start_temp[0]=start[0]+1;
		start_temp[1]=start[1];
		dist[0]=distance(start_temp,end);
	}
	//down
	else if (map[start[0]-1][start[1]]!='#'&&map[start[0]-1][start[1]]!='$')
	{
		start_temp[0]=start[0]-1;
		start_temp[1]=start[1];
		dist[1]=distance(start_temp,end);
	}
	//left
	else if (map[start[0]][start[1]-1]!='#'&&map[start[0]][start[1]-1]!='$')
	{
		start_temp[0]=start[0];
		start_temp[1]=start[1]-1;
		dist[2]=distance(start_temp,end);
	}
	//right
	else if (map[start[0]][start[1]+1]!='#'&&map[start[0]+1][start[1]+1]!='$')
	{
		start_temp[0]=start[0];
		start_temp[1]=start[1]+1;
		dist[3]=distance(start_temp,end);
	}
	chooseDirection(dist,direct);
}

int search(int start[2],int end[2],char map[100][100],int& dist)
{
	if (start[0]==end[0]&&start[1]==end[1])
	{
		return dist;
	} 
	int dis[4]={inf_distance,inf_distance,inf_distance,inf_distance};	
	getDistance(start,end,map,dis);
	int direc[2];
	chooseDirection(dis,direc);
	if (direc[0]==0&&direc[1]==0)
	{
         map[start[0]][start[1]]='$';
		 huiSu(start,end,map,direc);
		 if (direc[0]==0&&direc[1]==0)
		 {
			 return inf_distance;
		 }
		 else
		 {
			 dist++;
			 start[0]+=direc[0];
			 start[1]+=direc[1];
			 map[start[0]][start[1]]='$';
			// printMap(map,8,7);
			 search(start,end,map,dist);

		 }
	} 
	else
	{
		dist++;
		start[0]+=direc[0];
		start[1]+=direc[1];
		map[start[0]][start[1]]='%';
		//printMap(map,8,7);
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
				start[0]=checkPoints[i][0];
				start[1]=checkPoints[i][1];
				end[0]=checkPoints[j][0];
				end[1]=checkPoints[j][1];
				dist=0;
				printf("%8d \n",distMatrix[i][j]=search(start,end,Map_copy,dist));
				printMap(Map_copy,H,W);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
}