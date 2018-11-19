#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	float x[2][4],max_val;
	while(1){
		for(int i=0;i<2;i++)
			for(int j=0;j<4;j++)
				cin>>x[i][j];
		if(x[0][0]==-1)
			break;
		max_val=0;
		for(int j=0;j<4;j++){
			max_val = max(max_val,ceil(x[0][j]/x[1][j]));
		}
		for(int j=0;j<4;j++){
			cout<<(int)(x[1][j]*max_val-x[0][j])<<" ";
		}
		cout<<"\n";
	}
}
