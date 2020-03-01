bool isPowerOfFour(int num){
	if(num<1)
		return false;
	int x=log2(num);
	return (x==log2(num)&&x%2==0);
}
