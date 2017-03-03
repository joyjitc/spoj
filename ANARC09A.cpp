#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int stack;
	string inp;
	int right;
	int ans;
	int t=1;
	while(1){
		cin>>inp;
		if(inp[0]=='-')
			exit(0);
		stack=0,right=0;
		for(int i=0;i<inp.size();i++){
			if(inp[i]=='{')
				stack++;
			if(inp[i]=='}'){
				if(stack>0)
					stack--;
				else if(stack==0)
					right++;
			}
		}
		if(stack%2==0){
			ans = (stack+right)/2;
		}
		else{
			ans = (stack+right)/2+1;
		}
		cout<<t++<<". "<<ans<<"\n";
	}
}