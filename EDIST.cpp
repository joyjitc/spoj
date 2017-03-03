#include <iostream>
#include <vector>

using namespace std;

int EDIST(string a,string b){//Tabular,bottom-up approach
	int size_a = a.size();
	int size_b = b.size();
	vector<vector<int> > matrix;
	matrix.resize(size_b+1,vector<int>(size_a+1));
	for(int i = 0;i<=size_b;i++)
		matrix[i][0] = i;
	for(int j = 0;j<=size_a;j++)
		matrix[0][j] = j;
	for(int i = 1;i<=size_b;i++){
		for(int j=1;j<=size_a;j++){
			if(a[j-1]==b[i-1])
				matrix[i][j]=matrix[i-1][j-1];
			else{
				int min_val = min(matrix[i-1][j],matrix[i][j-1]);
				min_val = min(min_val,matrix[i-1][j-1]);
				matrix[i][j] = 1 + min_val;
			}
		}
	}
	return matrix[size_b][size_a];
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string a,b;
	while(t--){
		cin>>a>>b;
		// cout<<lcs<<endl;
		cout<<EDIST(a,b)<<endl;
	}
	return 0;
}
