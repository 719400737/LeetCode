#include<bits/stdc++.h>

using namespace std;
int helper(vector<int>& vec,int K){
    sort(vec.begin(),vec.end());
    int res=0;
    for(int i=0;i<vec.size();i++){
        res+=vec[i];
        for(int j=i;j<i+K;j++){
            
        }
    }
}

int main(){
    
    int N,K;
    cin>>N>>K;
    vector<int> vec;
    while(N--){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    int res=helper(vec,K);
    cout<<res<<endl;
    return 0;
}