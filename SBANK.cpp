#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	// vector<A> input;
	vector<string> input;
	int control_digit;
	int bank_code;
	int ac_1;
	int ac_2;
	int ac_3;
	int ac_4;
	string inp;
	while(t--){
		cin>>n;
		input.reserve(n);
		cin.ignore();
		for(int i=0;i<n;i++){
			getline(cin,inp);
			inp.resize(31);
			input.push_back(inp);
		}
		sort(input.begin(),input.end());
		int count;
		string temp = input[0];
		count = 1;
		for(int i=1;i<n;i++){
			if(input[i]==temp){
				count++;
			}
			else{
				cout<<temp<<" "<<count<<"\n";
				count=1;
				temp = input[i];
			}
		}
		cout<<temp<<" "<<count<<"\n\n";
		input.clear();		
	}
}
