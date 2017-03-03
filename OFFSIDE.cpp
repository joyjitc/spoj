#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int A,D;
	int temp;
	int min_A;
	int min_D,min2_D;
	while(cin>>A>>D){
		if(A==0)
			break;
		min_A = INT_MAX;
		for(int i=0;i<A;i++){
			cin>>temp;
			min_A = min(min_A,temp);			
		}
		// cout<<min_A<<endl;
		min_D = min2_D = INT_MAX;
		for(int i=0;i<D;i++){
			cin>>temp;
			if(temp<min2_D)
				min2_D = temp;
			if(min2_D<min_D)
				swap(min_D,min2_D);
			// cout<<min_D<<" "<<min2_D<<endl;
		}
		if(min_A<min2_D)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}