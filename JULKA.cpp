//c++14
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	t = 10;
	mp::cpp_int sum,diff;
	
	
	while(t--)
	{
		mp::cpp_int sum,diff;
		cin>>sum>>diff;
		cout<<(sum+diff)/2<<endl<<(sum-diff)/2<<endl;
		
	}
	return 0;
}