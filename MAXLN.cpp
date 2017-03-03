#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int r;
	double ans;
	for(int i=1;i<=t;i++){
		cin>>r;
		ans = (0.5)+(4.0*r*r*(1.0-(1.0/(long double)(16*r*r))));
		cout<<ans<<endl;
		// ans = (double)4*r*r + 0.25;
		cout<<"Case "<<i<<": "<<setprecision(2)<<fixed<<ans<<endl;
	}
	return 0;
}