#include<iostream>
using namespace std;
//considers cyclic 0-indexed array
int josephus(int n, int k){
	if(n==1) return 0;
	else return ((k-1)%n+1+josephus(n-1,k))%n;
}
int main(){
	ios::sync_with_stdio(0);
	int n,d;
	while(1){
		cin>>n>>d;
		if(n==0&&d==0)
			break;
		cout<<n<<" "<<d<<" "<<josephus(n,d)+1<<"\n";
	}
}