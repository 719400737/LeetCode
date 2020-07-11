#include<bits/stdc++.h>
using namespace std;
class Solution {
    int res=0;
    void DFS(vector<vector<char>>& grid,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        if(grid[r][c]=='1'){
            grid[r][c]='#';
            if(r-1>=0) DFS(grid,r-1,c);
            if(r+1<m) DFS(grid,r+1,c);
            if(c-1>=0) DFS(grid,r,c-1);
            if(c+1<n) DFS(grid,r,c+1);
        }
        else
            return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        //解析：采用DFS搜索，每次寻找1的最大连续区域，并将其改成其他字符以免重复计算
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    res++;
                    DFS(grid,i,j);
                }
            }
        }
        return res;
    }
};

int main(){


    return 0;
}