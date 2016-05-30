//c++14
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	mp::cpp_int fact = 1;
	int n;
	while(t--)
	{
		cin>>n;
		fact = 1;
		while(n>1)
		{
			fact *= n;
			n--;
		}
		cout<<fact<<"\n";
	}
	return 0;
}