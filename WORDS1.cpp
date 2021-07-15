#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int a[26] = {0};
		string word;
		vector<char> g[26];
		unordered_set<char> set;
		for(int i=0;i<n;i++){
			cin>>word;
			set.insert(word.front());
			set.insert(word.back());
			a[word.front()-97]--;
			a[word.back()-97]++;
			g[word.front()-97].push_back(word.back());
			g[word.back()-97].push_back(word.front());
		}
		stack<char> s;
		s.push(*set.begin());
		while(!s.empty()){
			char top = s.top();
			s.pop();
			if(set.count(top)>0){
				set.erase(top);
				for(char& x:g[top-97]){
					if(set.count(x)>0)
						s.push(x);
				}
			}
			else
				continue;
		}


		int neg=0,pos=0,zero=0,rando=0;
		for(int i=0;i<26;i++){
			if(a[i]==-1)
				neg++;
			else if(a[i]==1)
				pos++;
			else if(a[i]==0)
				zero++;
			else
				rando++;
		}
		if(((neg==1&&pos==1)||(neg==0&&pos==0))&&rando==0&& set.size()==0)
			cout<<"Ordering is possible.\n";
		else
			cout<<"The door cannot be opened.\n";
	}
}