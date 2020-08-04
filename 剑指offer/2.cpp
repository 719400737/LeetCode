#include <bits/stdc++.h>
using namespace std;
struct cube {
	int up;
	int down;
	int front;
	int back;
	int right;
	int left;
};

struct cube targetcube1 = {1, 2, 3, 4, 5, 6};
struct cube targetcube2 = {1, 2, 3, 5, 4, 6};
struct cube targetcube3 = {1, 2, 3, 6, 4, 5};
struct cube targetcube4 = {1, 3, 2, 4, 5, 6};
struct cube targetcube5 = {1, 3, 2, 5, 4, 6};
struct cube targetcube6 = {1, 3, 2, 6, 4, 5};
struct cube targetcube7 = {1, 4, 2, 3, 5, 6};
struct cube targetcube8 = {1, 4, 2, 5, 3, 6};
struct cube targetcube9 = {1, 4, 2, 6, 3, 5};

bool operator <(struct cube a, struct cube b)
    {
       if(a.up==b.up && a.down==b.down && a.front==b.front && a.back==b.back && a.right==b.right && a.left==b.left)
           return true;
        else
            return false;
    }

int cubematch(struct cube testcube);
 
int main()
{
    int N;
    cin>>N;

    int zhonglei=0;
    vector<int> nums={0};
    while(N){
        struct cube testcube;
        scanf("%d %d %d %d %d %d", &testcube.up, &testcube.down, &testcube.front, &testcube.back, &testcube.right, &testcube.left);
        if(testcube.up>testcube.down){
            swap(testcube.up,testcube.down);
        }
        if(testcube.front>testcube.back){
            swap(testcube.front,testcube.back);
        }
        if(testcube.right>testcube.left){
            swap(testcube.right,testcube.left);
        }
        
        if(testcube.up>testcube.front){
            swap(testcube.up,testcube.front);
            swap(testcube.down,testcube.back);
        }
        if(testcube.front>testcube.right){
            swap(testcube.front,testcube.right);
            swap(testcube.back,testcube.left);
        }
        if(testcube.up>testcube.front){
            swap(testcube.up,testcube.front);
            swap(testcube.down,testcube.back);
        }
        
        if(testcube<targetcube1){
            nums[1]++;
        }
        if(testcube<targetcube2){
            nums[2]++;
        }
        if(testcube<targetcube3){
            nums[3]++;
        }
        if(testcube<targetcube4){
            nums[4]++;
        }
        if(testcube<targetcube5){
            nums[5]++;
        }
        if(testcube<targetcube6){
            nums[6]++;
        }
        if(testcube<targetcube7){
            nums[7]++;
        }
        if(testcube<targetcube8){
            nums[8]++;
        }
        if(testcube<targetcube9){
            nums[9]++;
        }

        N--;
        
    }
    
    std::vector<int>::iterator biggest = std::max_element(std::begin(nums), std::end(nums));
    vector<int> output;
	for(int i=0;i<=9;i++){
        if(nums[i]!=0){
            zhonglei++;
            output.push_back(nums[i]);
        }
    }
    std::sort(output.begin(), output.end(), greater<int>());
    cout<<zhonglei<<endl;
    for(int j=0;j<output.size();j++){
        cout<<output[j];
        if(j==output.size()-1)
            return 0;
        else
            cout<<" ";
    }
    
}