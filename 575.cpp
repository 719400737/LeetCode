#include<iostream>
#include<vector>
#include<map>
using namespace std;

int distributeCandies(vector<int> &candies){
	int res=0;
	map<int,int>m;
	int s=candies.size();
	for(int i=0;i<s;i++){
		if(m[candies[i]]==0){
			m[candies[i]]++;
			res++;
		}

//		if(m[candies[i]]<1){
//			m[candies[i]]++;
//			res++;
//		}

	}
	return min(res,s/2);
}

int main(){
    int a[]={1,0,1,0,1,0};
    vector<int> vec(a,a+6);
    cout<<distributeCandies(vec);

    return 0;
}
