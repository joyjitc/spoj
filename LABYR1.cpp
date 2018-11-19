#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int C,R;
	vector<vector<char> > maze;
	vector<vector<int> > dist;	
	while(t--){
		cin>>C>>R;
		maze.resize(R,vector<char>(C));
		dist.resize(R,vector<int>(C,-1));
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin>>maze[i][j];
			}
		}
		int x,y;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(maze[i][j]=='.'&&dist[i][j]==-1){
					queue<pair<int,int> > q;
					q.push(pair<int,int>(i,j));
					dist[i][j]=0;
					while(!q.empty()){
						x = q.front().first;
						y = q.front().second;
						q.pop();
						if(x+1<R&&maze[x+1][y]=='.'&&dist[x+1][y]==-1){
							q.push(pair<int,int>(x+1,y));
							dist[x+1][y]=dist[x][y]+1;
						}
						if(x-1>=0&&maze[x-1][y]=='.'&&dist[x-1][y]==-1){
							q.push(pair<int,int>(x-1,y));
							dist[x-1][y]=dist[x][y]+1;
						}
						if(y+1<C&&maze[x][y+1]=='.'&&dist[x][y+1]==-1){
							q.push(pair<int,int>(x,y+1));
							dist[x][y+1]=dist[x][y]+1;
						}
						if(y-1>=0&&maze[x][y-1]=='.'&&dist[x][y-1]==-1){
							q.push(pair<int,int>(x,y-1));
							dist[x][y-1]=dist[x][y]+1;
						}
					}
				}
			}
		}

		int max_dis = -1;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(dist[i][j]>max_dis){
					max_dis = dist[i][j];
					x=i,y=j;
				}
				dist[i][j]=-1;
			}
		}

		queue<pair<int,int> > q;
		q.push(pair<int,int>(x,y));
		dist[x][y]=0;
		while(!q.empty()){
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if(x+1<R&&maze[x+1][y]=='.'&&dist[x+1][y]==-1){
				q.push(pair<int,int>(x+1,y));
				dist[x+1][y]=dist[x][y]+1;
			}
			if(x-1>=0&&maze[x-1][y]=='.'&&dist[x-1][y]==-1){
				q.push(pair<int,int>(x-1,y));
				dist[x-1][y]=dist[x][y]+1;
			}
			if(y+1<C&&maze[x][y+1]=='.'&&dist[x][y+1]==-1){
				q.push(pair<int,int>(x,y+1));
				dist[x][y+1]=dist[x][y]+1;
			}
			if(y-1>=0&&maze[x][y-1]=='.'&&dist[x][y-1]==-1){
				q.push(pair<int,int>(x,y-1));
				dist[x][y-1]=dist[x][y]+1;
			}
		}

		max_dis = 0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(dist[i][j]>max_dis){
					max_dis = dist[i][j];
				}
			}
		}
		cout<<"Maximum rope length is "<<max_dis<<".\n";
		dist.clear();
		maze.clear();	
	}
}
