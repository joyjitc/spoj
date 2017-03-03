#include <iostream>
// #include <cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	unsigned long long N;
	bool starter;
	while(t--){
		cin>>N>>starter;
		// N = ceil((long double)N/2.0);
		if(N&1==0)
			starter = !starter;
		if(starter)
			cout<<"Pagfloyd wins."<<endl;
		else
			cout<<"Airborne wins."<<endl;
	}
	return 0;
}