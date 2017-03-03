
#include<bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int carry,size,p,temp;
	int n;
	while(t--)
	{
		cin>>n;
		int fact[200]={0};
		fact[0] = 1;
		size = 1;
		for(int i=1;i<=n;i++)
		{
			carry = 0;
			p = 0;
			while(p<size)
			{
				temp = fact[p]*i + carry;
				fact[p] = temp%10;
				carry = temp/10;
				p++;

			}
			while(carry!=0)
			{
				fact[p] = carry%10;
				carry = carry / 10;
				size++;
				p++;
			}

		}
		for(int i =size -1;i>= 0 ;i--)
		{
			cout<<fact[i];
		}
		cout<<endl;
	}
	return 0;
}