#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n,true);// 常规的暴力判断是否素数+相加会导致超时
                                //从2开始每个其倍数都被设定为非素数
        int res=0;
        for(int i=2;i<n;i++){
            if(vec[i]){
                res++;
                if(i<sqrt(n))
                for(int j=i*i;j<=n;j+=i)
                    vec[j]=false;
                
            }
        }
        return res;
    }
};

int main(){


    return 0;
}