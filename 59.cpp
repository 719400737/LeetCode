#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {        
        int m=n;
        vector<vector<int>> res(m,vector<int>(n,0));
        if(m==0)
            return res;
        char fx='d'; //wasd 表示上下左右
        int r=0,c=0,num=1;;//当前的行列
        while(num<=m*n){
            if(res[r][c]==0){
                res[r][c]=num;
                num++;
            }
            if(fx=='d'){
                c+=1;
                if(c==n || res[r][c]!=0){
                    fx='s';
                    c-=1;
                }
            }
            if(fx=='s'){
                r+=1;
                if(r==m || res[r][c]!=0){
                    fx='a';
                    r-=1;
                }
            }
            if(fx=='a'){
                c-=1;
                if(c<0 || res[r][c]!=0){
                    fx='w';
                    c+=1;
                }
            }
            if(fx=='w'){
                r-=1;
                if(r<0 || res[r][c]!=0){
                    fx='d';
                    r+=1;
                }
            }

        }
        return res;
    }
};

int main(){
    int n=3;
    Solution s;
    s.generateMatrix(n);
    return 0;
}