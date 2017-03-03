#include <iostream>
#include <cmath>
 
typedef unsigned long long ull;
 
using namespace std;
void printAP(ull a,ull d,ull n)
{
	for(int i = 0; i<n ;i++)
		cout<<(a+(i*d))<<" ";
	cout<<endl;
}
 
// ull cal_n(ull t1, ull t2, ull s)
// {
// 	ull n = (long double)((5*t1+5*t2+2*s)+sqrt((5*t1+5*t2+2*s)*
//			(5*t1+5*t2+2*s)-40*s*(t1+t2)))/(long double)(2*(t1+t2));
// 	return n;
// }
ull cal_n(ull t1, ull t2, ull s)
{
	ull n = (2*s)/(t1+t2);
	return n;
}
ull cal_d(ull t1, ull t2, ull n)
{
	ull d = (t2-t1)/(n-5);
	return d;
}
ull cal_a(ull t1,ull d)
{
	ull a = t1 - 2*d;
	return a;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ull a,d,n;
	ull t1,t2,s;
	while(t--)
	{
		cin>>t1>>t2>>s;
		n = cal_n(t1,t2,s);
		d = cal_d(t1,t2,n);
		a = cal_a(t1,d);
 
		cout<<n<<endl;
		printAP(a,d,n);
		//Testing
		// cout<<cal_d(2,11,7)<<endl;
		// printAP(t1,t2,s);
	}
	return 0;
}