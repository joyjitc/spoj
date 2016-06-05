#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exch(ll n)
{
	if(n==1||n==0)
		return n;
	else
		return max(n,exch(n/2)+exch(n/3)+exch(n/4));
}
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	while(1)
	{
		cin>>n;
		cout<<exch(n)<<endl;
	}

	return 0;
}