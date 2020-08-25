#include<bits/stdc++.h>
using namespace std;
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n;
        while(l<r){
            if(l==r-1)
                break;
            long long mid=(l+r)/2;
            if(isBadVersion(mid)==false)
                l=mid+1;
            else    r=mid;
        }
        if(isBadVersion(l)==true)
            return l;
        return r;
    }
};

int main(){

    

    return 0;
}