#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;

	int x,y;

	while(t--)
	{	
		cin>>x>>y;
		if(x==y)
		{
			if(x%2==0)
				cout<<2*x;
			else
				cout<<(2*x)-1;
		}
		else if(y==x-2)
		{
			if(x%2==0)
				cout<<x+y;
			else
				cout<<x+y-1;
		}
		else
			cout<<"No Number";

		cout<<endl;

	}	
	return 0;
}
