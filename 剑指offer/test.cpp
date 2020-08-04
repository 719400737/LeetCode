#include<bits/stdc++.h>
using namespace std;
int helper(multimap<int,pair<int,int>>& m,int s,int n){
    int res=0;
    auto it=m.equal_range(s);
    if(it.first!=end(m)){
        for(auto iter=it.first;iter!=it.second;iter++){
            int so=iter->second.first;
            int num=iter->second.second;
            if(m.count(so)){
                int temp=min(n,num);
                int temp2=helper(m,so,temp);
                res+=min(temp,temp2);
            }
            else
                res+=min(num,n);
        }
    }
    return res;
}

int main(){
    int N,S;
    cin>>N;//S为根
    cin>>S;
    multimap<int,pair<int,int>> m;
    while(N!=1){
        int a,b,c;
        cin>>a>>b>>c;
        pair<int,int> p=make_pair(b,c);
        m.insert(make_pair(a,p));
        N--;
    }
    int res=helper(m,S,1000);
    cout<<res<<endl;


    return 1;
}