#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;

	
	ull k;
	ull head,tail;
	while(t--)
	{	
		cin>>k;
		head = (k-1)/4;
		if(k%4==1)
			tail = 192;
		else if(k%4==2)
			tail = 442;
		else if(k%4==3)
			tail = 692;
		else if(k%4==0)
			tail = 942;
		
		cout<<head*1000 + tail<<endl;



	}	
	return 0;
}
