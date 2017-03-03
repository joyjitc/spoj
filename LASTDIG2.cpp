#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	// string a,b;
	string a;
	unsigned long long b;

	int A,B;
	int last;
	int index;
	while(t--){
		cin>>a>>b;
		// if(b=="0"){
		// 	cout<<'1'<<endl;
		// 	continue;
		// }
		if(b==0){
			cout<<'1'<<endl;
			continue;
		}
		A = stoi(string(1,a[a.size()-1]));
		string temp;
		// if(b.size()==1)
		// 	temp = string(1,b[b.size()-1]);
		// else
		// 	temp = string(1,b[b.size()-2])+string(1,b[b.size()-1]);
		// B = stoi(temp);
		// cout<<"A = "<<A<<endl;
		// cout<<"B = "<<B<<endl;
		index = b%4;
		// index = B%4;
		// cout<<"Index = "<<index<<endl;
		index = ((index==0)?4:index);
		last = (int)pow(A,index);
		last %= 10;
		cout<<last<<endl;		
	}

	return 0;
}