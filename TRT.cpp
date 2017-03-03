#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > memo;
vector<int> input;

int trt(int i,int j, int age){
	if(i==j){
		memo[i][j] = age*input[i];
		return memo[i][j];
	}
	else if(memo[i][j]!=-1){
		return memo[i][j];
	}
	else{
		memo[i][j]=max(input[i]*age+trt(i+1,j,age+1),input[j]*age+trt(i,j-1,age+1));
		return memo[i][j];
	}
}

int main(){
	int N;
	cin>>N;
	memo.resize(N,vector<int>(N,-1));
	input.reserve(N);
	for(int i=0;i<N;i++)
		cin>>input[i];
	cout<<trt(0,N-1,1)<<"\n";
}