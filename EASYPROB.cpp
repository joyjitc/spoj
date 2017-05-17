#include <iostream>
#include <fstream>

using namespace std;

string easyprob(int N){
	if(N==3)
		return "2+2(0)";
	if(N==2)
		return "2";
	if(N==1)
		return "2(0)";
	// if(N==0)
	// 	return NULL;
	int num = 4;
	int power = 2;
	while(num<=N){
		num = num<<1;
		power++;
	}
	num = num>>1;
	power--;
	N = N-num;
	if(N==0)
		return "2("+easyprob(power)+")";
	else 
		return "2("+easyprob(power)+")+"+easyprob(N);
}

int main(){
	ios::sync_with_stdio(false);
	fstream file("easyprob.txt",ios::out);
	// int arr[] = {1315};
	int arr[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int i = 0; i<(sizeof(arr)/sizeof(int));i++){
		file<<arr[i]<<"="<<easyprob(arr[i])<<endl;
	}
	return 0;
}