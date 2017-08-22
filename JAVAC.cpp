#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	string input;
	int status;//Detection -1 error 0 undefined 1 C++ 2 Java
	

	while(getline(cin,input)){
		vector<string> s;
		status = 0;
		if(input[0]=='_'||isupper(input[0])||isdigit(input[0])){
			cout<<"Error!\n";
			continue;
		}
		string cur;
		for(int i=0;i<input.size();i++){
			if(isalnum(input[i])&&islower(input[i]))
				cur.push_back(input[i]);
			else if(input[i]=='_'){
				if(status==2){
					status=-1;
					break;
				}
				if(status==0) status = 1;
				s.push_back(cur);
				cur.clear();
			}
			else if(isupper(input[i])){
				if(status==1){
					status=-1;
					break;
				}
				if(status==0) status = 2;
				s.push_back(cur);
				cur.clear();
				cur.push_back(input[i]);
			}
			else{
				status=-1;
				break;
			}
		}
		if(status==-1){
			cout<<"Error!\n";
			continue;
		}
		s.push_back(cur);
		if(status==1){
			for(int i=1;i<s.size();i++)
				s[i][0] = toupper(s[i][0]);
			for(int i=0;i<s.size();i++)
				cout<<s[i];
			cout<<"\n";
		}
		else if(status==2){
			for(int i=1;i<s.size();i++)
				s[i][0] = tolower(s[i][0]);
			for(int i=0;i<s.size()-1;i++)
				s[i].push_back('_');
			for(int i=0;i<s.size();i++)
				cout<<s[i];
			cout<<"\n";
		}
		else if(status==0){
			for(int i=0;i<s.size();i++)
				cout<<s[i];
			cout<<"\n";
		}
	}
}