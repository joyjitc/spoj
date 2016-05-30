#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;

	stack<char> opr;
	string expr;
	string rpn;

	int i,j;

	while(t--)
	{	
		cin>>expr;
		//cout<<"magic is "<<int(expr[expr.size()]);

		i = 0;
		j = 0;
		while(i<expr.size())
		{
			//cout<<"i = "<<i<<endl;

			if(isalpha(expr[i]))
			{
				rpn[j]=expr[i];
				//cout<<"j = "<<j<<" "<<rpn[j]<<endl;
				j++;
			}
			else if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'||expr[i]=='^')
				{
					opr.push(expr[i]);
					//cout<<opr.top()<<endl;
				}
			else if(expr[i]==')')
			{
				//cout<<"opr.top()="<<opr.top()<<endl;
				rpn[j]=opr.top();
				//cout<<"j = "<<j<<" "<<rpn[j]<<endl;
				//cout<<opr.top()<<endl;
				opr.pop();
				j++;
			}
			i++;
		}
		while(!opr.empty())
			{
				//cout<<"stack not empty:"<<opr.top()<<endl;
				rpn[j]=opr.top();
				opr.pop();
				j++;
			}

		//rpn[j]=char(0);
		//cout<<rpn<<endl;
		i=0;
		while(i<j)
			{
				cout<<rpn[i];
				i++;
			}
		cout<<endl;
		

	}	
	return 0;
}
