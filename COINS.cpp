#include <iostream>
#include <tr1/unordered_map>
using namespace std;
typedef unsigned long long ll;
tr1::unordered_map<ll,ll> memo;
/*ll* arr = new ll [1000000005];
int main()
{
	ios::sync_with_stdio(false);
	for(ll i=2;i<=1000000000;i++)
	{
		arr[i]=max(i,arr[i/2]+arr[i/3]+arr[i/4]);
	}
	int t=10;
	ll n;
	while(t--)
	{
		cin>>n;
		cout<<arr[n]<<endl;
	}

	return 0;
}*/
ll exch(ll n)
{
	if(memo.find(n)!= memo.end())
		return memo[n];
	if(n <= 11)
		return n;
	else
	{
		ll X = exch(n/2) + exch(n/3) + exch(n/4);
		memo[n] = X;
		return X;
	}

		
}

// ll exch(ll n)
// {
	
// 	if(n>(n/2+n/3+n/4))
// 		return n;
// 	else
// 		return exch(n/2)+exch(n/3)+exch(n/4);
// }
int main()
{
	ios::sync_with_stdio(false);
	long n;
	int t=10;
	while(t--)
	{
		cin>>n;
		cout<<exch(n)<<endl;
	}

	return 0;
}
