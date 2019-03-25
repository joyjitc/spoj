#include<iostream>
using namespace std;
//considers cyclic 1-indexed array
int josephus(int n, int k){
	if(n==1) return 1;
	else return ((k-1)%n+josephus(n-1,k))%n+1;
}
int main(){
	ios::sync_with_stdio(0);
	int n,d;
	while(1){
		cin>>n>>d;
		if(n==0&&d==0)
			break;
		cout<<n<<" "<<d<<" "<<josephus(n,d)<<"\n";
	}
}