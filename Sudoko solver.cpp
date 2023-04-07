// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.

    bool issafe(int grid[N][N],int val,int row,int col){
        for(int i=0;i<col-1;i++){
            if(grid[row][i]==val) return false;
        }
        for(int i=col+1;i<N;i++){
            if(grid[row][i]==val) return false;
        }
        for(int i=0;i<row-1;i++){
            if(grid[i][col]==val) return false;
        }
        for(int i=row+1;i<N;i++){
            if(grid[i][col]==val) return false;
        }
        return true;
    }
    
    vector<int> remain (int grid[N][N],int strow,int endrow,int stcol,int endcol){
        vector<int>v;
        vector<int>ans;
        for(int i=strow;i<endrow;i++){
            for(int j=stcol;j<endcol;j++){
                if(grid[i][j]!=0){
                    v.push_back(grid[i][j]);
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp.insert({v[i],i});
        }
        for(int i=1;i<=9;i++){
            auto itr=mp.find(i);
            if(itr==mp.end()){
                ans.push_back(i);
            }
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends