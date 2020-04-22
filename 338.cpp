#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,num);
        dp[0]=0;
        for(int i=1;i<=num;i++){     
            int j=0;
            while(pow(2,j)<=i)
                j++;
            dp[i]=min(dp[i],1+dp[i-pow(2,j-1)]);
        }
        return dp;
    }
};

int main(){



    return 0;
}