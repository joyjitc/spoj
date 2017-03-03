#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ios::sync_with_stdio(false);
	ull n;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<(n*(n+2)*(2*n + 1)/8)<<endl;
	}
	return 0;
}
//http://math.stackexchange.com/questions/203873/how-many-triangles