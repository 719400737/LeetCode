#include "bits/stdc++.h" 

using namespace std;

unsigned DFS_Clock=0;
stack<unsigned> Stack;
//最大联通子域的问题
void getEWD(unordered_map<unsigned, vector<unsigned>> &EWD, 
            unordered_map<unsigned, unsigned> &DFN,
            unordered_map<unsigned, bool> &InSt)
{   
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        if (EWD.find(id1) == EWD.end()) {
            EWD[id1] = vector<unsigned>();
        }
        if (EWD.find(id2) == EWD.end()) {
            EWD[id2] = vector<unsigned>();
        }
        EWD[id1].push_back(id2);
        DFN[id1] = 0; DFN[id2] = 0;
        InSt[id1] = false; InSt[id2] = false;
    }
}

unsigned Min(unsigned a, unsigned b) {
    if (a < b)
        return a;
    else
        return b;
}


long factorial(long number)
{	if(number<=1)
		return 1;
	else 
		return number*factorial(number-1);
}
 
int combinator(int n,int m)
{	int temp;
	if(n<m)
	{	temp=n;
		n=m;
		m=temp;}
	return factorial(n)/(factorial(m)*factorial(n-m));
}

void Tarjan(unsigned now,
            const unordered_map<unsigned, vector<unsigned>> &EWD, 
            unordered_map<unsigned, unsigned> &LOW,
            unordered_map<unsigned, unsigned> &DFN,
            unordered_map<unsigned, bool> &InSt,
            vector<vector<unsigned>> &res,
            int &ans)
{
	LOW[now] = DFN[now] = ++DFS_Clock;//建立DFS遍历时序DFN，LOW初始化为DFN 
	Stack.push(now);//当前顶点入栈 
	InSt[now] = true;//入栈标记 
    for(auto next : EWD.at(now)) {
        //枚举now连接的所有顶点next 
        if (!DFN[next]){//如果next还没有遍历到
            Tarjan(next, EWD, LOW, DFN, InSt, res, ans);//递归遍历next，以此建立LOW[next] 
            LOW[now] = Min(LOW[now], LOW[next]);//递归返回LOW[next]，以此建立LOW[now] 
        } else if (InSt[next]) {//如果next遍历过了且还在栈中，递归的边界之一
            LOW[now] = Min(LOW[now], DFN[next]);
        }
    }

	if (LOW[now] == DFN[now]) {//如果now为强连通分量根，输出栈中now及其之后元素，即为一个强连通分量 
		unsigned top_elem;
        vector<unsigned> cssVec;
		do {
			top_elem=Stack.top();
			Stack.pop();
			cssVec.push_back(top_elem);
			InSt[top_elem] = false;
		} while (top_elem != now);
        ans += combinator(cssVec.size(), 2);
	}
}



int main() {
    unordered_map<unsigned, vector<unsigned>> EWD;
    unordered_map<unsigned, unsigned> LOW, DFN;
    unordered_map<unsigned, bool> InSt;

    vector<vector<unsigned>> res;
	
    getEWD(EWD, DFN, InSt);

    int ans = 0;

	for(auto w : EWD) {
	    if(!DFN[w.first]) 
            Tarjan(w.first, EWD, LOW, DFN, InSt, res, ans);
    }

    cout << ans << endl;
    
    system("pause");
    return 0;
}