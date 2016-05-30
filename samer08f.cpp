#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	long long squares;
	
	while(n!=0)
	{	
		squares = 0;
		for(int i=1;i<=n;i++)
		{
			squares += i*i;
		}

		cout<<squares<<endl;
		cin>>n;
	}	
	return 0;
}
