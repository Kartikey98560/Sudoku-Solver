#include<stdio.h>
int arr[9][9][9];
int exi[9]={0,0,0,0,0,0,0,0,0};
int pos[9],posy[9];


void print();
void print2();
void giv_exi();
void slbb();
void slbb2(int);
int algo1(int);
void algo2(int);
int checkIfSolved();
int givCount(int,int,int);

int main()
{
	int i,j,z;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&arr[i][j][0]);
		}
		printf("\n");
	}
	printf("Question:-\n");
	print();
	int not_solved=1;
	z=0;
//	while(not_solved)
//	{
//		algo1(1);
//		for(i=1;i<=9;i++)
//		{
//		algo2(i);
//		}
//		not_solved=checkIfSolved();
//		z++;
//		if(z>100)
//			break;
//	}
	slbb();
	//print2();
	for(j=1;j<=9;j++)
	{
		slbb2(j);
	}
	print2();
//	printf("\n\nSolution:-\n");
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
			if(arr[x][y][0]!=0)
				exi[(arr[x][y][0])-1]=1;
		}
	}
}

void slbb()
{
	int i,j,k,l,t=1;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{		
			if (arr[i][j][0]==0)
			{
				for(k=0;k<9;k++)
				{
				exi[k]=0;
				}
				giv_exi(i,j);
				t=1;
				for(k=0;k<9;k++)
				{
					arr[i][j][t]=0;
					if(exi[k]==0)
					{
						//printf("i=%d j=%d pussi=%d\n",i,j,k+1);
						arr[i][j][t]=k+1;
						t++;
					}
					arr[i][j][t+1]=0;
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
			printf("%d ",arr[i][j][0]);
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

int algo1(int x)
{
	int i,j,k=0;
	x=0;
	for(i=0;i<9;i++)
	{
	slbb2(i);
	}
	slbb();
	if(x==0)
		return 0;
	else
	{
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if((arr[i][j][0])==0 && (arr[i][j][2]==0))
			{
				x=1;
				for(k=0;k<9;k++)
					k==0?(arr[i][j][k]=arr[i][j][1]):(arr[i][j][k]=0);
			}
		}
	}	
		return algo1(x);
	}
}
void algo2(int k)
{
	int x,y,z,count;
	int i=0,j=0;
	slbb2(k);
	while(i<8 && j<8)
	{
		count=0;
		for(x=(i/3)*3;x<=2+((i/3)*3);x++)
		{
			for(y=(j/3)*3;y<=(2+((j/3)*3));y++)
			{
				z=1;
				if(arr[x][y][0]==k)
					x=9,y=9;
				count=givCount(k,x,y);	
			}			
		}
		if (count==1)
			{
				for(z=0;z<9;z++)
					z==0?(arr[(pos[0])][(posy[0])][z]=k):(arr[(pos[0])][(posy[0])][z]=0);
			}

		if (j!=6)
			j+=3;
		else
		{
			j=0;
			i+=3;
		}
	}
}

void slbb2(int k)
{
	int x,y,z,n,count,flag;
	int i=0,j=0;
//	slbb();
	while(i<8 && j<8)
	{
		count=0;
		for(n=0;n<9;n++)
		{
			pos[n]=0;
			posy[n]=0;
		}
		for(x=(i/3)*3;x<=2+((i/3)*3);x++)
		{
			for(y=(j/3)*3;y<=(2+((j/3)*3));y++)
			{
				if(arr[x][y][0]==k)
					x=9,y=9;
				z=1;
				while(arr[x][y][0]==0 && arr[x][y][z]!=0)
				{
					if(arr[x][y][z]==k)
					{
						pos[count]=x;
						posy[count]=y;
						count++;
					}
					z++;
				}
	//			count=givCount(k,x,y);	
			}			
		}
		printf("k=%d    i=%d  j=%d  count=%d\n",k,i,j,count);
	
		if(count==2 || count==3)
		{
			printf("true\n");
			if(count==3?(pos[0]==pos[1] && pos[1]==pos[2]):(pos[0]==pos[1]))
			{
				printf("i=%d true\n",pos[0]);
				for(y=0;y<9;y++)
				{
					z=1,flag=0;
					while(arr[(pos[0])][y][0]==0 && arr[(pos[0])][y][z]!=0)
					{
						if(arr[(pos[0])][y][z]==k && flag==0)
						{
							arr[(pos[0])][y][z]=arr[(pos[0])][y][z+1];
							flag=1;
						}
						else if(flag==1)
						{
							arr[(pos[0])][y][z]=arr[(pos[0])][y][z+1];
						}
						z++;
					}
				}
			}
			else if(count==3?(posy[0]==posy[1] && posy[1]==posy[2]):(posy[0]==posy[1]))
			{
				printf("j=%d  true\n",posy[0]);
				for(x=0;x<9;x++)
				{
					z=1,flag=0;
					while(arr[x][(posy[0])][0]==0 && arr[x][(posy[0])][z]!=0)
					{
						if(arr[x][(posy[0])][z]==k && flag==0)
						{
							arr[x][(posy[0])][z]=arr[x][(posy[0])][z+1];
							flag=1;
						}
						else if(flag==1)
						{
							arr[x][(posy[0])][z]=arr[x][(posy[0])][z+1];
						}
						z++;
					}
				}
			}
			
		}
		if (j!=6)
			j+=3;
		else
		{
			j=0;
			i+=3;
		
		}
	}
}

int givCount(int k,int x,int y)
{
	int z=1,ct;
	while(arr[x][y][0]==0 && arr[x][y][z]!=0)
		{
			if(arr[x][y][z]==k)
			{
				pos[ct]=x;
				posy[ct]=y;
				ct++;
			}
		z++;
		}
	return ct;
}

int checkIfSolved()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(arr[i][j][0]==0)
				return 1;
		}
		//printf("\n");
	}
	return 0;
}

void print2()
{
	int i,j,k=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			
			for(k=0;k<9;k++)
			{
				printf("i=%d j=%d k=%d\t%d\n",i,j,k,arr[i][j][k]);
			}
			printf("______________________________________________________________________________________________________________________\n");
		}
	}
}



