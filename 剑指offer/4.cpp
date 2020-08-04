#include<bits/stdc++.h>

using namespace std;
bool com(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}
void helper(vector<vector<int>>& vec){
    unordered_map<int,int> m;
    for(auto i:vec){
        //i转换
        vector<int> path;
        int t1=min(i[0],i[1]);
        int t2=min(i[2],i[3]);
        int t3=min(i[4],i[5]);
        int min_t=min(min(t1,t2),t3);
        if(t1==min_t){
            path.push_back(i[0]);
            path.push_back(i[1]);
            if(t2<t3){
                path.push_back(i[2]);
                path.push_back(i[3]);
                path.push_back(i[4]);
                path.push_back(i[5]);
            }
            else{
                path.push_back(i[4]);
                path.push_back(i[5]);
                path.push_back(i[2]);
                path.push_back(i[3]);
            }
            
        }
        if(t2==min_t){
            path.push_back(i[2]);
            path.push_back(i[3]);
            if(t1<t3){
                path.push_back(i[0]);
                path.push_back(i[1]);
                path.push_back(i[4]);
                path.push_back(i[5]);
            }
            else{
                path.push_back(i[4]);
                path.push_back(i[5]);
                path.push_back(i[0]);
                path.push_back(i[1]);
            }
            
            
            
        }
        if(t3==min_t){
            path.push_back(i[4]);
            path.push_back(i[5]);
            if(t1<t2){
                path.push_back(i[0]);
                path.push_back(i[1]);
                path.push_back(i[2]);
                path.push_back(i[3]);
            }
            else{
                path.push_back(i[2]);
                path.push_back(i[3]);
                path.push_back(i[0]);
                path.push_back(i[1]);
            }
            
        }
        for(int k=0;k<5;k+=2){
            if(path[k]>path[k+1]){
                int temp=path[k];
                path[k]=path[k+1];
                path[k+1]=temp;
            }
        }
        
        int zz=0;
        for(auto i:path){
            zz=zz*10+i;
        }
        m[zz]++;
        
    }
    vector<pair<int,int>> res;
    int count=0;
    for(auto i:m){
        res.push_back(i);
        count++;
    }
    cout<<count<<endl;
    sort(res.begin(),res.end(),com);
    for(auto i:res){
        cout<<i.second<<" ";
    }
}

int main(){
    int M;
    cin>>M;
    vector<vector<int>> vec;
    vector<int> path;
    while(M--){
        for(int i=0;i<6;i++){
            int temp;
            cin>>temp;
            path.push_back(temp);
        }
        vec.push_back(path);
        path.clear();
    }
    helper(vec);

    return 0;
}
