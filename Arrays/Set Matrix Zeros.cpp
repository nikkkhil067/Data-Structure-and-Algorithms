//Set Matrix Zeros
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        bool firstrow=false,firstcol=false;
        for(int i=0;i<n;i++) 
        {
            if(matrix[i][0]==0)
                firstcol=true;
        }
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]==0)
                firstrow=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrow)
        {
            for(int j=0;j<m;j++)
                matrix[0][j]=0;
        }
        if(firstcol)
        {
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
    }
int main(){
	vector<vector<int>> matrix;
	int n,m;
	cin>>n>>m; // rows and columns
	for(int i=0;i<n;i++){
		for(int j=0;i<m;j++){
			cin>>matrix[i][j];
		}
	}
	void setZeroes(vector<vector<int>>matrix);
return 0;
}
// Time Complexity - O(n*m)
// Space Complexity - O(1)
