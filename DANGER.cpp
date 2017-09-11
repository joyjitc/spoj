#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	string input;
	int n;
	int l;
	while(1){
		cin>>input;
		if(input[0]=='0'&&input[1]=='0'&&input[3]=='0')
			break;
		n=((input[0]-'0')*10+(input[1]-'0'))*pow(10,input[3]-'0');
		l = log2(n);
		l = n-pow(2,l);
		l = 1+2*l;
		cout<<l<<"\n";
	}
}