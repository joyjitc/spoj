#include <iostream>

typedef unsigned long long ull;

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ull ans;
	ull inp;
	char op;
	bool flag;
	while(t--){
		cin>>ans;
		flag = true;
		do{
			if(flag){
				cin>>op;
				flag = false;
			}
			else
			{
				cin>>inp;
				flag = true;
				if(op=='+')
					ans+=inp;
				else if(op=='-')
					ans -= inp;
				else if(op=='*')
					ans *= inp;
				else if(op=='/')
					ans /= inp;
			}

		}while(op!='=');
		cout<<ans<<endl;
	}

	return 0;
}