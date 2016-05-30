#include<bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	long n1,n2,n1r,n2r,sumr,sum;

	cin>>t;
	while(t--)
	{
		n1r=n2r=sum=0;
		cin>>n1>>n2;
		while (n1!=0)
		{
			n1r = (n1r*10) + (n1%10);
			n1 /= 10;
		}
		while (n2!=0)
		{
			n2r = (n2r*10) + (n2%10);
			n2 /= 10;
		}
		sumr = n1r + n2r;
		while (sumr!=0)
		{
			sum = (sum*10) + (sumr%10);
			sumr /= 10;
		}
		cout<<sum<<"\n";


	}
	return 0;
}