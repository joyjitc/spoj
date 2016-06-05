#include <bits/stdc++.h>
using namespace std;

int recs(int n)
{
	if(n==1)
		return 1;
	else 
	{
		int divisible = 0;
		int sqroot = int(sqrt(n));
		for(int i=1;i<=sqroot;i++)
		{
			if(n%i==0)
				divisible++;
		}
		return divisible + recs(n-1);

	}
}

int main()
{	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	cout<<recs(n)<<endl;
	
	return 0;
}
