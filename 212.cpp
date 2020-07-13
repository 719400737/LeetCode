#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> res;
    string path;
    vector<vector<char>> board;
    vector<vector<int>> tag;

    bool flag=true;
    void DFS(string word,int index,int i,int j){
        if(word[index]==board[i][j] && tag[i][j]==0){
            path.push_back(word[index]);
            tag[i][j]=1;
            if(path.size()==word.size()){
                res.push_back(word);
                path.pop_back();
                flag=false;
                tag[i][j]=0;
                return;
            }
            if(flag && j-1>=0) DFS(word,index+1,i,j-1);
            if(flag && j+1<board[0].size()) DFS(word,index+1,i,j+1);
            if(flag && i-1>=0) DFS(word,index+1,i-1,j);
            if(flag && i+1<board.size()) DFS(word,index+1,i+1,j);
            path.pop_back();
            tag[i][j]=0;
        }
        else    return;
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board=board;
        vector<vector<int>> tag(board.size(),vector<int>(board[0].size(),0));
        this->tag=tag;
        for(auto c:words){
            int m=res.size();
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    flag=true;
                    DFS(c,0,i,j);
                    if(res.size()==m+1)
                        break;
                }
                if(res.size()==m+1)
                        break;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char>> board={{'a','b'}};
    vector<string> str={"a","b"};
    Solution s;
    vector<string> res;
    res=s.findWords(board,str);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}