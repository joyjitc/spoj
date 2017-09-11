#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int val;
	int tot=0;
	vector<int> rew;
	for(int i=0;i<10;i++){
		cin>>val;
		rew.push_back(val);
	}
	for(int i=0;i<10;i++){
		val=rew[i];
		if(tot+val<100){
			tot+=val;
			continue;
		}
		else{
			if(100-tot<val+tot-100)
				break;
			else{
				tot+=val;
				break;
			}
		}
	}
	cout<<tot<<"\n";
}