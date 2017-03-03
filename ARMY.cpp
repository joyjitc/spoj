#include <iostream>

using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	int t;
	int NG,G,maxG,NM,M,maxM;
	cin>>t;

	while(t--)
	{
		cin.ignore();
		cin>>NG>>NM;
		maxM = maxG = 0;
		for(int i = 0; i<NG ; i++)
		{
			cin>>G;
			maxG = max(maxG,G);
		}
		for(int i = 0; i<NM ; i++)
		{
			cin>>M;
			maxM = max(maxM,M);
		}
		if(maxM>maxG)
			cout<<"MechaGodzilla"<<endl;
		else
			cout<<"Godzilla"<<endl;
	}
	return 0;
}