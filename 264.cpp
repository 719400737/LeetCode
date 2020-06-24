#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(1);
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++){
            int num2=2*dp[p2],num3=3*dp[p3],num5=5*dp[p5];
            int num=min(min(num2,num3),num5);
            dp.push_back(num);
            if(num==num2)
                p2++;
            if(num==num3)
                p3++;
            if(num==num5)
                p5++;
        }
        return dp.back();
    }
};

int main(){
    Solution s;
    int res=s.nthUglyNumber(10);
    cout<<res<<endl;

    return 0;
}