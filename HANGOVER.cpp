#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	float c;
	float n;
	int den;
	int card;
	
	while(cin>>c && c!= 0.00)
	{	
		n = 0;
		den = 2;
		card = 0;
		while(1)
		{	

			n += (1.0/den);
			den++;
			card++;
			
			if(n >= c)
				
				break;
		}
		cout<<card<<" card(s)"<<endl;

	}	
	return 0;
}
