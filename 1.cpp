#include<bits/stdc++.h>
using namespace std;
class Solution {
    int minnum=INT_MAX;
    int res=0;
    vector<int> flag;
    void helper(vector<vector<int>>& vec,int num){
        if(num<=0){
            minnum=min(minnum,res);
            return;
        }
        for(int i=0;i<vec.size();i++){
            if(flag[i]==1)
                continue;
            flag[i]=1;
            int temp=0;
            if(num<=vec[i][1])
                temp=2*vec[i][0];
            else
                temp=vec[i][0];
            num-=temp;
            res++;
            helper(vec,num);
            num+=temp;
            flag[i]=0;
            res--;
        }

    }
public:
    int result(vector<vector<int>>& vec,int num){
        int m=vec.size();
        vector<int> flag(m,0);
        this->flag=flag;
        helper(vec,num);
        return minnum;
    }
};


int main(){
    
    int T;
    cin>>T;
    vector<int> vv;
    while(T--){
        int n,m;
        cin>>n>>m;
        Solution s;
        vector<vector<int>> vec;
        while(n--){
            int a,b;
            cin>>a>>b;
            vector<int> temp={a,b};
            vec.push_back(temp);
        }
        int res=s.result(vec,m);
        if(res==INT_MAX)
            res=-1;
        vv.push_back(res);
    }
    for(auto i:vv)
        cout<<i<<endl;

    return 0;
}
