#include<bits/stdc++.h>
using namespace std;
class Solution {
    double helper(double x,int n){//递归每次先求1半的值
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        double res=helper(x,n/2);
        if(n%2==0)
            return res*res;
        else    return res*res*x;
            
    }
public:
    double myPow(double x, int n) {
        if(n>=0)
            return helper(x,n);
        else
            return 1/helper(x,n);
    }
};

int main(){



    return 1;
}