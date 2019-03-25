#include<iostream>

unsigned long long sumOfDigits (int limit){
	unsigned long long ans =  0;
	
	return ans;
}

using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int a,b;
	while(1){
		cin>>a>>b;
		if(a==-1&&b==-1) break;
		cout<<sumOfDigits(b)-sumOfDigits(a-1)<<"\n";
	}
}