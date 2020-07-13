#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //解析：该题考察拓扑排序，主要查看拓扑中是否有环存在
        //使用map来表示每个节点向对应的邻接节点，
        //使用数组来表示每个节点的入度。
        //当某个节点的入度为0时进入队列，表明该节点是没有依赖与其他节点的。同时将其邻接节点的度-1
        unordered_map<int,vector<int>> m;
        vector<int> indegree(numCourses,0);
        for(auto i:prerequisites){
            int a=i[0];
            for(int j=1;j<i.size();j++){
                int b=i[j];
                m[b].push_back(a);
                indegree[a]++;
            } 
        }
        queue<int> que;
        int res=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                que.push(i);
        }
        while(!que.empty()){
            int v=que.front();
            que.pop();
            res++;
            auto x=m[v];
            for(auto i:x){
                indegree[i]--;
                if(indegree[i]==0)
                    que.push(i);
            }
        }
        return res==numCourses;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec={{1,0}};
    s.canFinish(2,vec);

    return 0;
}