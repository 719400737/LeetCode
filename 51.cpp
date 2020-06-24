#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>> res;  
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
            res.push_back(path);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        DFS(board,0);
        vector<vector<string>> vec;
        for(int a=0;a<res.size();a++){
            vector<int> tmp=res[a];
            vector<string> tmp1;
            string tmp2(n,'.');
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(tmp[i]==j)
                        tmp2[j]='Q';
                }
                tmp1.push_back(tmp2);
                tmp2[tmp[i]]='.';
            }
            vec.push_back(tmp1);
        }
        return vec;
    }
};

int main(){
    vector<vector<string>> res;
    int n=4;
    Solution s;
    res=s.solveNQueens(n);
    for(auto i:res){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}