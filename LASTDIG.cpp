#include <bits/stdc++.h>
using namespace std;
int main()
{	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	int a;
	long long b;
	while(t--)
	{
		cin>>a>>b;
		
		if(b == 0)
		{
			cout<<'1'<<endl;
			continue;
		}
		a %= 10;
		int index = b%4;
		index = ((index == 0) ? 4 : index);
		int last = int(pow(a,index));
		last %= 10;
		cout<<last<<endl;

		

	}
	
	return 0;
}
