#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

// void calBitMap(int i, int j, int dist){
// 	if(i<0||j<0||i>n-1||j>m-1)
// 		return;
// 	if(bitmap[i][j]<=dist&&dist!=0)
// 		return;
// 	else{
// 		bitmap[i][j]=dist;
// 		calBitMap(i-1,j,dist+1);
// 		calBitMap(i+1,j,dist+1);
// 		calBitMap(i,j-1,dist+1);
// 		calBitMap(i,j+1,dist+1);
// 	}
// }

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	vector<vector<int> > bitmap;
	int n,m;
	while(t--){
		cin>>n>>m;
		string input;
		bitmap.resize(n,vector<int>(m,INT_MAX));
		queue<pair<int,int> > index;
		for(int i=0;i<n;i++){
			cin>>input;
			for(int j=0;j<m;j++){
				if(input[j]=='1'){
					index.push(pair<int,int>(i,j));
					bitmap[i][j]=0;
				}
			}
		}
		// for(vector<pair<int,int> >::iterator it = index.begin();it!=index.end();++it)
		// 	bitmap[(*it).first][(*it).second] = 0;
		// for(vector<pair<int,int> >::iterator it = index.begin();it!=index.end();++it){
		// 	calBitMap((*it).first,(*it).second,0);
		int a,b;
		while(!index.empty()){
			pair<int,int> cur = index.front();
			index.pop();
			a = cur.first;
			b = cur.second;
			if(a-1>=0&&a-1<n&&b>=0&&b<m&&bitmap[a-1][b]==INT_MAX){
				bitmap[a-1][b] = bitmap[a][b]+1;
				index.push(pair<int,int>(a-1,b));
			}
			if(a+1>=0&&a+1<n&&b>=0&&b<m&&bitmap[a+1][b]==INT_MAX){
				bitmap[a+1][b] = bitmap[a][b]+1;
				index.push(pair<int,int>(a+1,b));
			}
			if(a>=0&&a<n&&b-1>=0&&b-1<m&&bitmap[a][b-1]==INT_MAX){
				bitmap[a][b-1] = bitmap[a][b]+1;
				index.push(pair<int,int>(a,b-1));
			}
			if(a>=0&&a<n&&b+1>=0&&b+1<m&&bitmap[a][b+1]==INT_MAX){
				bitmap[a][b+1] = bitmap[a][b]+1;
				index.push(pair<int,int>(a,b+1));
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<bitmap[i][j]<<" ";
			cout<<endl;
		}
		bitmap.clear();
	}
	return 0;
}