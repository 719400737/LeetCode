#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int n=1;
        while(pow(n,2)<x){
            n*=2;//结果肯定在n/2--n之间
        }
        if(pow(n,2)==x)
            return n;
        int f=n/2,s=n;
        while(f<s){
            int m=(f+s)/2;
            if(pow(m,2)>x)
                s=m;
            else{
                if(f==m)
                    return f;
                f=m;
            }
        }
        return f;
    }
};

int main(){
    int n=25;
    Solution s;
    int res=s.mySqrt(n);
    cout<<res<<endl;
    return 0;
}