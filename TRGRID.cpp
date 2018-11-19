#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	int m,n;
	cin>>t;
	double x;
//	int y;
	while(t--){
		cin>>m>>n;
		x = min(ceil((double)m/2.0),ceil((double)n/2.0));
		x--;
		m = m-(x*2);
		n = n-(x*2);
		if(m==1) cout<<"R\n";
		else if(n==1) cout<<"D\n";
		else if(m==2) cout<<"L\n";
		else if(n==2) cout<<"U\n";		
	}
}
