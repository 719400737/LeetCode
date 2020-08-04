#include<bits/stdc++.h>
using namespace std;
class Solution {
    int m,n;
    vector<vector<int>> flag;
    int res=0;
    void helper(int x,int y,int k){
        flag[x][y]=1;
        int temp=0,i=x,j=y;
        while(i){
            temp+=i%10;
            i/=10;
        }
        while(j){
            temp+=j%10;
            j/=10;
        }
        if(temp<=k){
            res++;
            if(x+1<m && flag[x+1][y]==0) helper(x+1,y,k);
            if(x-1>=0 && flag[x-1][y]==0) helper(x-1,y,k);
            if(y+1<n && flag[x][y+1]==0) helper(x,y+1,k);
            if(y-1>=0 && flag[x][y-1]==0) helper(x,y-1,k);
        }

    }
public:
    int movingCount(int m, int n, int k) {
        this->m=m,this->n=n;
        vector<vector<int>> v(m,vector<int>(n,0));
        this->flag=v;
        helper(0,0,k);
        return res;
    }
};

int main(){



    return 1;
}