#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int sum,moves,avg;
	
	int packet[10000];
	while(cin>>n && n!=-1)
	{	
		avg = moves = sum = 0;
		for(int i=0;i<n;i++)
		{
			cin>>packet[i];
			sum += packet[i];
		}
		if(sum%n != 0)
			cout<<"-1"<<endl;
		else
		{
			avg = sum/n;
			for(int i=0;i<n;i++)
			{
				if(packet[i]>avg)
					moves += packet[i] - avg;
			}
			cout<<moves<<endl;
		}

	}	
	return 0;
}