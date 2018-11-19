#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	string line,word;
	char x;
	bool flag;
	while(getline(cin,line)){
		if(line[0]=='*')
			break;
		x=tolower(line[0]);
		flag=true;
		istringstream iss(line);
		while(iss>>word){
			if(tolower(word[0])!=x){
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<"Y\n";
		else
			cout<<"N\n";
	}
}

