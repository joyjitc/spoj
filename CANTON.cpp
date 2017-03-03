#include <iostream>
#include <cmath>

using namespace std;

int cantorRow(int input)
{
	double temp = (sqrt(1+(8*input))-1)/2.0;
	return (int)ceil(temp);
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int i;
		cin>>i;
		int num,denum;
		// cout<<cantorRow(i)<<endl;
		int row = cantorRow(i);
		int offset = i - (row*(row-1)/2);
		// cout<<offset;		
		if(row%2==0)
		{
			num = offset;
			denum = row - num + 1; 
		}
		else
		{
			denum = offset;
			num = row - denum + 1;
		}
		cout<<"TERM "<<i<<" IS "<<num<<"/"<<denum<<endl;

	}

	return 0;
}