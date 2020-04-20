#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                if(i==grid.size()-1 && j==grid[0].size()-1)
                    continue;
                else if(i==grid.size()-1)
                    grid[i][j]=grid[i][j]+grid[i][j+1];
                else if(j==grid[0].size()-1)
                    grid[i][j]=grid[i][j]+grid[i+1][j];
                else    
                    grid[i][j]=grid[i][j]+min(grid[i+1][j],grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};
int main(){



    return 0;
}