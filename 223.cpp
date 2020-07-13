#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool cross(int A, int B, int C, int D, int E, int F, int G, int H){
        if(F>=D || H<=B)
            return true;
        else if(E>=C || G<=A)
            return true;
        else    return false;
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        long long m=max(A,E),n=max(B,F),k=min(C,G),l=min(D,H);
        long long s=0;
        if(cross(A,B,C,D,E,F,G,H))//判断两个矩形是否相交
            s=0;
        else
            s=abs(k-m)*abs(l-n);//重叠面积
        cout<<s<<endl;
        long long s1=abs(D-B)*abs(C-A);
        long long s2=abs(G-E)*abs(H-F);
        cout<<s1<<endl;cout<<s2<<endl;
        long long res=s1+s2-s;
        return res;
    }
};
int main(){


    return 0;
}