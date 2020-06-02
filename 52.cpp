#include<bits/stdc++.h>
using namespace std;

class Solution {
int res=0;  
vector<int> path;
  
public:
    void gen(vector<vector<int>>& board){
        int n=board.size();
        vector<vector<int>> temp(n,vector<int>(n,0));
        board=temp;
        for(int i=0;i<path.size();i++){
            int j=path[i];
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    if(a==i || b==j)
                        board[a][b]=1;
                    else if(a-i==b-j || a-i==j-b)
                        board[a][b]=1;
                }
            }
        }
    }
    void DFS(vector<vector<int>>& board,int begin){
        int n=board.size();
        if(path.size()==n){
            res++;
            return;
        }
        int i=begin;
        for(int j=0;j<n;j++){
            if(board[i][j]==1)//若棋盘上该位置为1，表示不能放皇后
                continue;
            path.push_back(j);
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    if(a==i || b==j)
                        board[a][b]=1;
                    if(a-i==b-j || a-i==j-b)
                        board[a][b]=1;
                }
            }
            DFS(board,i+1);
            path.pop_back();
            gen(board);
        }        
        
    }

     int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        DFS(board,0);
        return res;
    }
};

int main(){
    int n=8;
    Solution s;
    int res;
    res=s.totalNQueens(n);
    cout<<res<<endl;
    return 0;
}