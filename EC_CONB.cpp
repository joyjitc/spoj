#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	unsigned int num,temp,bits;
	cin>>n;
	while(n--){
		cin>>num;
		if(num&1)
			cout<<num<<"\n";
		else{
			temp=0;
			while(num){
				temp=temp<<1;
				if(num&1)
					temp=temp|1;
				num=num>>1;
			}
			cout<<temp<<"\n";
		}
	}
}
