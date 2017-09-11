#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);

	string input1,input2;
	while(getline(cin,input1)){
		getline(cin,input2);
		int c1[26]={0},c2[26]={0};
		for(char x:input1) c1[x-'a']++;
		for(char x:input2) c2[x-'a']++;
		string output;
		int count;
		for(int i=0;i<26;i++){
			count = min(c1[i],c2[i]);
			for(int j=0;j<count;j++)
				output.push_back(i+'a');
		}
		cout<<output<<"\n";
	}
}
