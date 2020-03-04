int maxArea(vector<int>& height) {
    int head=0;
    int tail=height.size()-1;
    int res=0;
    while(head<tail){
        if(height[head]<height[tail]){
            res=max(res,height[head]*(tail-head));
            int n=height[head];
            head++;
            while(n>height[head]&&head<tail)
                head++;
        }
        else{
            res=max(res,height[tail]*(tail-head));
            int n=height[tail];
            tail--;
            while(n>height[tail]&&head<tail)
                tail--;
        }
    }
    return res;
}
//双指针法
//从头和尾指针找到较小的，将其更新，更新时找到比现在指针大的。