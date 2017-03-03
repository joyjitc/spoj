#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int noOfStamp, noOfFriend;

	vector<int> elements;
	for(int j = 1; j<=t; j++ )
	{
		cin>>noOfStamp>>noOfFriend;
		// elements.resize(noOfFriend);
		int z = noOfFriend;
		int element;
		int sum = 0;
		while(z--)
		{
			cin>>element;
			sum += element;
			elements.push_back(element);
		}
		cout<<"Scenario #"<<j<<":"<<endl;
		// cout<<elements.size()<<endl;
		int reqFr = 0; 
		int curSum = 0;
		if(sum<noOfStamp)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			sort(elements.begin(),elements.end(),greater<int>());
			for(auto it = elements.begin(); it!= elements.end();++it)
			{
				
				curSum += (*it);
				reqFr++;
				// cout<<"curSum = "<<curSum<<" (*it) = "<<(*it)<<" reqFr = "<<reqFr<<" sum = "<<sum<<endl;
				if(curSum>=noOfStamp)
					break;
			}
			cout<<reqFr<<endl;
		}

		elements.clear();
	}
	return 0;

}