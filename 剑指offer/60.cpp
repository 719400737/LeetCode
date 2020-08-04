#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> twoSum(int n) {
        int temp=6*n;
        vector<vector<int>> dp(n+1,vector<int>(temp+1,0));
        int num_sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=6*i;j++){
                if(i==1){
                    dp[i][j]=1;
                    continue;
                }
                int k=1;
                while(j-k>0 && k<=6){
                    num_sum+=dp[i-1][j-k];
                    k++;
                }    
                dp[i][j]=num_sum;
                num_sum=0;
            }
        }
        int all=pow(6,n);
        vector<double> res;
        for(int i=n;i<=6*n;i++){
            res.push_back(dp[n][i]*1.0/all);
        }
        return res;

    }
};

int main(){



    return 0;
}