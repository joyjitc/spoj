#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a,b,c;
	int next;
	while(cin>>a>>b>>c && !(a==0&&b==0&&c==0))
	{	
		if(a+c==2*b)
		{
			cout<<"AP ";
			next=c+b-a;
		}
		else
		{
			cout<<"GP ";
			next=c*(b/a);
		}
		cout<<next<<endl;
	}	
	return 0;
}
