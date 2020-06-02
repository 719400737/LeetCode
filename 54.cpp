#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        vector<int> res;
        if(m==0)
            return res;
        int n=matrix[0].size();
        char fx='d';//wasd 表示上下左右
        
        int r=0,c=0;//当前的行列
        while(res.size()<m*n){
            if(matrix[r][c]!=INT_MAX){
                res.push_back(matrix[r][c]);
                matrix[r][c]=INT_MAX;
            }
            if(fx=='d'){
                c+=1;
                if(c==n || matrix[r][c]==INT_MAX){
                    fx='s';
                    c-=1;
                }
            }
            if(fx=='s'){
                r+=1;
                if(r==m || matrix[r][c]==INT_MAX){
                    fx='a';
                    r-=1;
                }
            }
            if(fx=='a'){
                c-=1;
                if(c<0 || matrix[r][c]==INT_MAX){
                    fx='w';
                    c+=1;
                }
            }
            if(fx=='w'){
                r-=1;
                if(r<0 || matrix[r][c]==INT_MAX){
                    fx='d';
                    r+=1;
                }
            }

        }
        return res;
    }
};

int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.spiralOrder(m);
    return 0;
}