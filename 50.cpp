#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(x==1)
            return 1;
        long n1=n;
        if(n1<0){
            n1=-n1;
            x=1/x;
        }
        double half=myPow(x,n1/2);
        double full=half*half;
        if(n1%2){
            return full*x;
        }
        return full;
    }
};

int main(){
    double a;
    Solution s;
    a=s.myPow(2.1,5);
    cout<<a<<endl;
    return 0;
}