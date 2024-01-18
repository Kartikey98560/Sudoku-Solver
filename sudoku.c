#include<stdio.h>
#include<math.h>
int arr[9][9][9];
int exi[9]={0,0,0,0,0,0,0,0,0};
void print();
void giv_exi();
void slbb();
int main()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&arr[i][j][0]);
		}
		printf("\n");
	}
	print();
	slbb();
	print();
}
void giv_exi(int i, int j)
{
	int x,y;
	for(x=0;x<9;x++)
	{
		if(arr[i][x][0]!=0)
			exi[(arr[i][x][0])-1]=1;
	}
	for(x=0;x<9;x++)
	{
		if(arr[x][j][0]!=0)
			exi[(arr[x][j][0])-1]=1;
	}
	for(x=(i/3)*3;x<=2+((i/3)*3);x++)
	{
		for(y=(j/3)*3;y<=2+((j/3)*3);y++)
		{
			printf("\t\ti=%d  j=%d  x=%d   y=%d\n",i,j,x,y);
			if(arr[x][j][0]!=0)
				exi[(arr[x][y][0])-1]=1;
		}
	}
}
void slbb()
{
	int i,j,k,t=1;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			t=1;
			if (arr[i][j][0]==0)
			{
				for(k=0;k<9;k++)
				{
				exi[k]=0;
				}
				giv_exi(i,j);
				for(k=0;k<9;k++)
				{
					if(exi[k]!=0)
					{
						printf("i=%d j=%d pussi=%d\n",i,j,k+1);
						arr[i][j][t]=k+1;
						t++;
					}
				}
			}
		}
	}
	
}
void print()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			
			printf("%d  ",arr[i][j][0]);
			if((j+1)%3==0)
				printf("|");
		}
		if((i+1)%3==0)
		{
			printf("\n");
			printf("______________________");
		}
		printf("\n");
	}
}

