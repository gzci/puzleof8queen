#include<iostream>
using namespace std;
int g_count=0;
const int N=4;
int chess[N][N]={0};
void print(){
	for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<chess[i][j]<<' ';
			}
			cout<<endl; 
		}
		cout<<endl;
		g_count++;
} 
bool CanPlace(int row,int col){
	
	for(int i=0;i<N;i++){
		if(chess[i][col]==1){//check col
			return false;
		}
		if(chess[row][i]==1){//check row
			return false;
		}
	}


	for(int i=0;i<N;i++){//check left-front
		if(row-i<0||col-i<0){
			break;
		}
		if(chess[row-i][col-i]==1){
			return false;
		}
	}
	

	for(int i=0;i<N;i++){//check right-front
		if(row-i<0||col+i>N-1){
			break;
		}
		if(chess[row-i][col+i]==1){
			return false;
		}

	}	
		

	for(int i=0;i<N;i++){//check left-below
		if(row+i>N-1||col-i<0){
			break;
		}
		if(chess[row+i][col-i]==1){
			return false;
		}
	}	
	

	for(int i=0;i<N;i++){//check right-below
		if(row+i>N-1||col+i>N-1){
			break;
		}
		if(chess[row+i][col+i]==1){
			return false;
		}
	}
	
	return true;
}
void EightQueen(int row,int col){
	
	

	if(row==N){//show result
		print();
	}
	else{
		for(int j=0;j<N;j++){
			if(CanPlace(row,j)){
				
				chess[row][j]=1;//put chess
				
				EightQueen(row+1,j);//这里每次返回到上一个row j也是上一个j 就是上次皇后的位置 
				
				chess[row][j]=0;//remove chess to use for next by same chess 2Darray
				
			}
		} 
	}
};

int main(){

	
	EightQueen(0,0);
	
	cout<<g_count<<endl;
	
	return 0;
}
