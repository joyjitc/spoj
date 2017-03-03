#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	string key, input;
	int found;
	while(cin>>n){
		cin>>key;
		cin>>input;
		found = input.find(key);
		while(found!=string::npos){
			cout<<found<<"\n";
			found = input.find(key,found+1);
		}
		cout<<"\n";
	}
}