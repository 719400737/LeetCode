#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<char>> board;
    vector<vector<int>> tag;
    bool res=false;
public:
    void DFS(string word,int start,int i,int j){//4个相邻的元素 i,j-1  i,j+1
                                                //            i-1,j  i+1,j

        if(board[i][j]==word[start] && tag[i][j]==0){
            if(start+1==word.size()){                 
                res=true;
                return;
            }
            tag[i][j]=1;
            if(j-1>=0) {
                DFS(word,start+1,i,j-1);
                if(res)
                    return;
            }
            if(j+1<board[0].size()){
                DFS(word,start+1,i,j+1);
                if(res)
                    return;
            }
            if(i-1>=0){
                DFS(word,start+1,i-1,j);
                if(res)
                    return;
            }
            if(i+1<board.size()){
                DFS(word,start+1,i+1,j);
                if(res)
                    return;
            }
            tag[i][j]=0;
        }  
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        vector<vector<int>> tag(board.size(),vector<int>(board[0].size(),0));
        this->tag=tag;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                    DFS(word,0,i,j);
                if(res)
                    return res;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board={{'A'}};
    string word="A";
    bool res=s.exist(board,word);
    cout<<res<<endl;

    return 0;
}