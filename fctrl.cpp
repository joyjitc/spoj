#include<bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int zero,i,num,n;
	while(t--)
	{
		cin>>n;
		zero = 0;
		i = 1;
		while(1)
		{
			num = n/int(pow(5,i));
			if (num==0){break;}
			zero += num;
			i++;
		}
		cout<<zero<<"\n";
	}
	return 0;
}