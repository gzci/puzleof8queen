#include<stdio.h>
#include<windows.h>
#define N 4 //可以根据N来修改棋盘的格数 
int count = 0;//设置一个计数器 
int chess[N][N] = {0,0,0,0,
					0,1,0,0,
					0,0,0,0,
					0,0,0,0,};//用于存放棋盘的二维数组 

void print()//打印函数 
{	
	int i = 0;
	int j = 0;
	printf("*****************************************\n");
	for(i = 0; i<N ;i++)
	{
		for(j = 0; j<N ; j++)
		{
			printf("%d ",chess[i][j]);
		}
		printf("\n");
	}
	printf("*****************************************\n");
}


//返回1?表示存在互吃??
//返回0?表示正常
int check(int i, int j){//i是行 j是列 
	////先判断同行有没有1 先向右 
	for(int k=j;k<N;k++){
		if(chess[i][k]==1)
			return 1;
	} 
//	//在向左 
	for(int k=j;k>=0;k--){
		if(chess[i][k]==1)
		return 1;
	}
	
	//在判断同一列 up
	for(int k=i;k>=0;k--){
		if(chess[k][j]==1)
		return 1;
	}
	//down
	for(int k=j;k<N;k++){
		if(chess[k][j]==1)
		return 1;
	}
	//判断 正对角线 up 
	int c=i,w=j;
	while(c>=0&&w<c+w){
		c--;
		w++;
		if(chess[c][w]==1)
		return 1;
	} 
	////判断 正对角 down
	 c=i;
     w=j;
		while(c<c+w&&w>=0){
		c++;
		w--;
		if(chess[c][w]==1){
		}
		
	} 
	
////	判断负对角线 up
	
	
	for(c=0;c<N;c++){
		for(w=0;w<N;w++){
			if(c-w==i-j){
				if(chess[c][w]==1)
				return 1;
				
			}
		}
	}
}
int main(){
	printf("%d",check(1,1));
}
