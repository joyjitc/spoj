#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	const long double PI = 3.141592653589793238463;
	while(cin>>n){
		if(n==0)
			break;
		long double ans = n*n/(2*PI);
		cout<<setprecision(2)<<fixed<<ans<<endl;//rounds it off to two digits after decimal

	}
	return 0;
}