#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> array;
	int inp;
	for(int i=0;i<n;i++){
		cin>>inp;
		array.push_back(inp);
	}
	int m;
	cin>>m;
	int x,y;
	int max_ending_here,max_so_far;
	while(m--){
		cin>>x>>y;
		x-=1;
		y-=1;
		max_ending_here = max_so_far = array[x];
		for(int i = x+1;i<=y;i++){
			max_ending_here = max(max_ending_here+array[i],array[i]);
			max_so_far = max(max_so_far,max_ending_here);
		}
		cout<<max_so_far<<endl;

	}
	return 0;
}