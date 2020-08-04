#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWays(int n) {
        long long t1=1,t2=2;
        long long cur=0;
        long long mod=pow(10,9)+7;
        if(n==0)
            return 1;
        for(int i=1;i<=n;i++){
            if(i==1)
                cur=t1;
            else if(i==2)
                cur=t2;
            else{
                cur=(t1+t2)%mod;
                t1=t2;
                t2=cur;
            }
            
        }
        return cur;
    }
};

int main(){



    return 1;
}