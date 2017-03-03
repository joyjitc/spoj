#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int elem;
	vector<int> arr;

	while(1)
	{	
		cin>>n;
		if(n==0)
			break;
		for(int i = 0; i<n ;i++)
		{
			cin>>elem;
			arr.push_back(elem);
		}
		int flag = 0;
		for(int i = 0; i<n ;i++)
		{
			if(arr[arr[i]-1]!=i+1)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
			cout<<"ambiguous"<<endl;
		else
			cout<<"not ambiguous"<<endl;
		arr.clear();
	}

	return 0;
}