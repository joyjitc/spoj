#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	
	while(cin>>n)
	{
		if(n==0)
			break;
		stack<int> wait;
		int flag = 0;
		int inp;
		int toFind = 1;
		for(int i = 0; i<n; i++)
		{
			cin>>inp;
			// cout<<inp<<endl;
			if(flag==1)
				continue;
			if(inp == toFind)
			{
				toFind++;
				while(!wait.empty()&&wait.top()==toFind)
				{
					wait.pop();
					toFind++;
				}
			}
			else
			{
				if(wait.empty())
					wait.push(inp);
				else if(inp>wait.top())
				{
					flag = 1;
	 			}
      			else
      				wait.push(inp);
	      	}


		}
		if(flag==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}