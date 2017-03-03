#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;

	
	ull n;
	ull sum;
	while(t--)
	{	
		
		cin>>n;
		sum = 0;
		ull candy;
		ull number = n;
		while(number--)
		{
			cin>>candy;

			sum = (sum + candy%n)%n;
			
		}
		if(sum==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;


	}	
	return 0;
}
