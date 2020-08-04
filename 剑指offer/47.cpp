#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int a=0,b=0;
                if(i-1>=0)
                    a=grid[i-1][j];
                if(j-1>=0)
                    b=grid[i][j-1];
                grid[i][j]+=max(a,b);
            }
        }
        return grid[m-1][n-1];
    }
};

int main(){



    return 1;
}