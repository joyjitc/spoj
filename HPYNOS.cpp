#include <iostream>
#include <tr1/unordered_set>
typedef unsigned long long ull;

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ull input;
	cin>>input;
	tr1::unordered_set<ull> mySet;
	ull ans = 0;
	ull temp = input;
	ull store;
	mySet.insert(input);
	bool flag = false;
	while(temp!=1){
		ans++;
		store = 0;
		while(temp!=0){
			int a = temp%10;
			store += a*a;
			temp /= 10;
		}
		temp = store;
		if(mySet.find(temp)!=mySet.end()){
			flag = true;
			break;
		}
		else
			mySet.insert(temp);
	}
	if(flag)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}