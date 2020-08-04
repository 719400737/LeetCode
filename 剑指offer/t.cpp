#include<bits/stdc++.h>
using namespace std;
    int res=INT_MIN;
int helper(multimap<int,int>& m,vector<int>& v,int s){
    auto it=m.equal_range(s);
    int root=v[s];
    int max_num=root,min_num=root,rres=INT_MIN;
    bool b=false;
    if(it.first!=end(m)){
        for(auto iter=it.first;iter!=it.second;iter++){
            int index=iter->second;
            int num=v[index];
            if(m.count(index)){
                int temp=helper(m,v,index);
                num=temp;
            }
            if(b==false){
                b=true;
                if(num>0)
                    rres=max(rres,num*max_num);
                else    rres=max(rres,num*min_num);
                max_num=num*root;
                min_num=num*root;
                continue;
            }
            if(num>0){
                rres=max(rres,num*max_num);
                res=max(res,num*max_num);
            }
            else{
                rres=max(rres,num*min_num);
                res=max(res,num*min_num);
            }
            max_num=max(max_num,num*root);
            min_num=min(min_num,num*root);
            
        }
    }
    return rres;
}

int main(){
    int N;
    cin>>N;//S为根
    multimap<int,int> m;
    vector<int> vec(N+1,0);
    for(int i=1;i<=N;i++){
        int temp;
        cin>>temp;
        vec[i]=temp;
    }
    while(N!=1){
        int a,b;
        cin>>a>>b;
        m.insert(make_pair(a,b));
        N--;
    }
    int rres=helper(m,vec,1);
    cout<<res<<endl;
    return 1;
}