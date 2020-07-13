#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //拓扑排序
        vector<int> res;
        unordered_map<int,vector<int>> m;
        vector<int> indegree(numCourses,0);
        for(auto i:prerequisites){
            int a=i[0];//学习a需要先学习b
            for(int j=1;j<i.size();j++){
                int b=i[j];
                m[b].push_back(a);//b的邻接表中加入a
                indegree[a]++;
            } 
        }
        queue<int> que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int v=que.front();
            res.push_back(v);
            que.pop();
            count++;
            //把与v相邻的入度－1
            auto k=m[v];
            for(auto l:k){
                indegree[l]--;
                if(indegree[l]==0)
                    que.push(l);
            }
        }
        if(count==numCourses)
            return res;
        else{
            res.clear();
            return res;
        }
    }
};

int main(){


    return 0;
}