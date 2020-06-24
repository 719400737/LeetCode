#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nmax=0;
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                {
                    if(j>0 && i>0)
                        dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
                    else dp[i][j]=1;
                }
                nmax=max(nmax,dp[i][j]);
            }
        }
        return nmax*nmax;
    }
};
int main(){



    return 0;
}