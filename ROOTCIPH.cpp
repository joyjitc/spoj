#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long long b,c,d;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&b,&c,&d);
		printf("%lld\n",b*b-2*c);
	}
}
