#include<stdio.h>
#include<windows.h>
#define N 4 //���Ը���N���޸����̵ĸ��� 
int count = 0;//����һ�������� 
int chess[N][N] = {0,0,0,0,
					0,1,0,0,
					0,0,0,0,
					0,0,0,0,};//���ڴ�����̵Ķ�ά���� 

void print()//��ӡ���� 
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


//����1?��ʾ���ڻ���??
//����0?��ʾ����
int check(int i, int j){//i���� j���� 
	////���ж�ͬ����û��1 ������ 
	for(int k=j;k<N;k++){
		if(chess[i][k]==1)
			return 1;
	} 
//	//������ 
	for(int k=j;k>=0;k--){
		if(chess[i][k]==1)
		return 1;
	}
	
	//���ж�ͬһ�� up
	for(int k=i;k>=0;k--){
		if(chess[k][j]==1)
		return 1;
	}
	//down
	for(int k=j;k<N;k++){
		if(chess[k][j]==1)
		return 1;
	}
	//�ж� ���Խ��� up 
	int c=i,w=j;
	while(c>=0&&w<c+w){
		c--;
		w++;
		if(chess[c][w]==1)
		return 1;
	} 
	////�ж� ���Խ� down
	 c=i;
     w=j;
		while(c<c+w&&w>=0){
		c++;
		w--;
		if(chess[c][w]==1){
		}
		
	} 
	
////	�жϸ��Խ��� up
	
	
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
