#include <bits/stdc++.h>
using namespace std;
int main()
{	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int input1[1000];
	int input2[1000];
	int sum,n;
	int inp;
	while(t--)
	{
		sum = 0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>input1[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>input2[i];
		}
		sort(input1,input1 + n);
		sort(input2,input2 + n);
		for(int i=0;i<n;i++)
		{
			
			sum += input2[i]*input1[i];
		}
		cout<<sum<<endl;


	}
	
	return 0;
}
