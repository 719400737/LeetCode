#include<iostream>
#include<math.h>
using namespace std;
//二分查找
int divide(int dividend, int divisor) {
    if(dividend==0)
        return 0;
    if(divisor==1)
        return dividend;
    if(divisor==-1){
        if(dividend>INT_MIN)
            return -dividend;
        else
        {
            return INT_MAX;
        }    
    }
    long a=dividend,b=divisor;
    int fuhao=0;
    int res=1;
    if((a>0&b<0)||(b>0&&a<0)){
        fuhao=1;        
    }
    a=a>0?a:-a; 
    b=b>0?b:-b;
    if(a<b){
        return 0;
    }
    while(a>2*res*b){
        res*=2;
    }
    if(fuhao)
        return -res-divide(a-res*b, b);
    
    else
        return res+divide(a-res*b, b);
    
    
    
}

void a(int b){
    cout<<b<<endl;
}
int main(){
    
    
    cout<<divide(-100,300)<<endl;
    return 0;
}