#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
       long res=0;
       while(x){
           int shang=x/10;
           int yu=x%10;
           res=res*10+yu;
           x=shang;
       }
       if(res>INT_MAX || res<INT_MIN)
        return 0; 
       return res;
    }
};

int main(){
    int x=-12345;
    Solution s;
    s.reverse(x);

    return 0;
}