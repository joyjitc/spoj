#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N,M;
	int a,b;
	cin>>N>>M;
	for(int i = 0;i<M; i++)
		cin>>a>>b;
	if(N==M+1)
		cout<<"YES"<<endl;
	else 
		cout<<"NO"<<endl;
	return 0;
}