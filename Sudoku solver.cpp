#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0  
#define N 9  
class Solution 
{
    public:
   bool isSafe(int grid[N][N],int row ,int col,int k){
        for(int i=0;i<N;i++){
            if(grid[i][col]==k) return false;
        }
        for(int i=0;i<N;i++){
            if(grid[row][i]==k) return false;
        }
        if(row<=2) row=0;
        if(row>2 && row<=5 ) row=3;
        if(row>=6 && row<=8) row =6;

        if(col<=2) col=0;
        if(col>2 && col<=5 ) col=3;
        if(col>=6 && col<=8) col =6;
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2 ;j++){
                if(grid[i][j]==k) return false;
            }
        }
        return true;
    }
    bool solve(int grid[N][N],int i,int j){
        if(j >= N){
            return true;
        }
        if(grid[i][j]==0){
            for(int k=1;k<=9;k++){
                if(isSafe(grid,i,j,k)){
                    grid[i][j]=k;
                    if(i < N-1 ){
                        if(solve(grid,i+1,j)){
                            return true;
                        }
                    }else if(j < N-1){
                        if( solve(grid,0,j+1)){
                            return true;
                        }
                    }else if(i == N-1 && j == N-1){
                        return true;
                    }
                    grid[i][j]=0;
                }
            }
        }else{
            if(i < N-1 ){
                if(solve(grid,i+1,j)){
                    return true;
                }
            }else if(j < N-1){
                if( solve(grid,0,j+1)){
                    return true;
                }
            }else if(i == N-1 && j == N-1){
                return true;
            }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid,0,0);
    }
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
    
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
} 