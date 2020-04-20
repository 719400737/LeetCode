#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(j==n-1 && i==m-1)
                    dp[i][j]=1;
                else if(j==n-1)
                    dp[i][j]=dp[i+1][j];
                else if(i==m-1)
                    dp[i][j]=dp[i][j+1];
                else
                    dp[i][j]=dp[i][j+1]+dp[i+1][j];
                
            }
        }
        return dp[0][0];
    }
};
int main(){
    vector<vector<int>> res{{0,1}};
    Solution s;
    int a=s.uniquePathsWithObstacles(res);
    cout<<a<<endl;

    return 0;
}