#include <iostream>
#include <cmath>
 using namespace std;
 
 int main()
 {
 	ios::sync_with_stdio(false);
 	int G,B;
 	while(cin>>G>>B)
 	{
 		if(G==-1)
 			break;
 		if(G==B)
 		{
 			if(G==0)
 			    cout<<"0"<<endl;
 			else
 			    cout<<"1"<<endl;
 		}
 		else if(G==0 || B==0)
 		{
 			if(G==0)
 				cout<<B<<endl;
 			else
 				cout<<G<<endl;
 		}
 		else
 		{
 			int big,small;
 			if(G>B)
 			{
 				big = G;
 				small = B;
 			}
 			else
 			{
 				big = B;
 				small = G;
 			}
 			cout<<ceil((double)big/(double)(small+1))<<endl;
 
 		}
 	}
 } 
