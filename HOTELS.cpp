#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	unsigned long long M;
	cin>>N>>M;
	vector<int> inp(N+1);
	for(int i=1;i<=N;i++)
		cin>>inp[i];
	int i,j;
	i=j=1;
	unsigned long long max_sum = 0, sum;
	sum = inp[i];
	while(1){
		if(sum<=M)
			max_sum = max(sum, max_sum);
		if(sum==M)
			break;
		else if(sum<M){
			if(j==N)
				break;
			j++;
			sum+=inp[j];
		}
		else if(sum>M){
			if(i==N)
				break;
			sum-=inp[i];
			i++;
		}
	}
	cout<<max_sum<<endl;
	return 0;
}
