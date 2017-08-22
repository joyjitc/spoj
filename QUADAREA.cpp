#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	double a,b,c,d,s,area;
	cout<<fixed;
	cout.precision(2);
	while(t--){
		cin>>a>>b>>c>>d;
		s = (a+b+c+d)/(double)2.0;
		area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		cout<<(double)area<<"\n";
	}
}