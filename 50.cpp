#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double helper(double x,int n){
        if(n==0)
            return 1.0;
        double res=helper(x,n/2);
        return n%2==0 ? res*res:res*res*x;
    }
    double myPow(double x, int n) {
        bool b=false;
        if(n<0)
            b=true;
        double res=helper(x,n);
        if(b)
            res=1/res;
        return res;
    }
};

int main(){
    double a=2;   
    int b=-2;
    Solution s;
    double res=s.myPow(a,b);
    cout<<res<<endl;

    return 0;
}