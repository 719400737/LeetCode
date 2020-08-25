#include<bits/stdc++.h>
using namespace std;

int main()
{
	/*
	int n=5;
	vector<int> v1={3,2,4,4,5};
	vector<int> v2={4,3,5,2,1};*/
	int n;
	cin>>n;
	vector<int> v1;
	vector<int> v2;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v1.push_back(temp);
	}
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v2.push_back(temp);
	}
	//构建矩阵
	
	int sum=0;
	for(auto i:v1)
		sum+=i;
	vector<vector<int>> vec(n,vector<int>(2,0));
	for(int i=0;i<n;i++){
		if(i==0){
			vec[i][0]=0;
			vec[i][1]=sum-v1[i];
		}
		else{
			vec[i][0]=vec[i-1][0]+v1[i-1];
			vec[i][1]=vec[i-1][1]-v1[i];
		}
	}
	for(int i=0;i<n;i++){
		int col=v2[i]-1;//取走列
		int num=v1[col];//列数值
		for(int j=0;j<n;j++){
			if(j<col){
				vec[j][1]-=num;
			}
			else if(j>col){
				vec[j][0]-=num;
			}
		}
		int res=max(vec[col][0],vec[col][1]);
		cout<<res<<endl;
	}
	return 0;
}
