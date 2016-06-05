#include <bits/stdc++.h>
using namespace std;
int main()
{	ios::sync_with_stdio(false);
	int n;
	char input[100][200];
	while(cin>>n && n!=0)
	{
		string inp;
		cin>>inp;
		int size=inp.size();
		int x = 0;
		int j=0;
		int col = size/n;
		while(j<col)
		{
			for(int i = 0;i<n;i++)
			{
				input[j][i] = inp[x];
				x++;
			}
			j++;
			for(int i = n-1;i>=0;i--)
			{
				input[j][i] = inp[x];
				x++;
			}
			j++;
		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<col;j++)
			{
				cout<<input[j][i];
			}
		}

		cout<<endl;
	}
	return 0;
}
