#include<bits/stdc++.h>
using namespace std;
int w,h;
vector<vector<char>> mp;
vector<vector<int>> dist;
struct DjS{
	int i,j,score;
	DjS(int _i,int _j, int _score):i(_i),j(_j),score(_score){}
};
struct comp{
	bool operator()(DjS& l,DjS& r){
		return l.score>r.score;
	}
};
void checkPush(int i,int j, int score, auto& pq){
	if(i>=0&&i<h&&j>=0&&j<w&&dist[i][j]==-1&&mp[i][j]!='X'){
		if(mp[i][j]=='D'){
			pq.push(DjS(i,j,score));
		}
		else{
			pq.push(DjS(i,j,score+(mp[i][j]-'0')));
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	while(1){
		cin>>w>>h;
		if(w==0&&h==0)
			break;
		mp.resize(h,vector<char>(w));
		dist.resize(h,vector<int>(w,-1));
		pair<int,int> s,d;
		string line;
		cin.ignore();
		for(int i=0;i<h;i++){
			getline(cin,line);
			int j=0;
			for(char x:line) mp[i][j++] = x;
			// for(int j=0;j<w;j++){
			// 	cin>>mp[i][j];
			// 	if(mp[i][j]=='S')
			// 		s=pair<int,int>(i,j);
			// 	else if(mp[i][j]=='D');
			// 		d=pair<int,int>(i,j);
			// }
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				// cout<<i<<" "<<j<<" : "<<mp[i][j]<<"\n";
				if(mp[i][j]=='S')
					s=pair<int,int>(i,j);
				else if(mp[i][j]=='D')
					d=pair<int,int>(i,j);
			}
		}
		// cout<<s.first<<" -> "<<s.second<<"\n";
		// cout<<d.first<<" -> "<<d.second<<"\n";
		priority_queue<DjS,vector<DjS>,comp> pq;
		pq.push(DjS(s.first,s.second,0));
		DjS cur(0,0,0);
		while(!pq.empty()){
			cur = pq.top();pq.pop();
			if(dist[cur.i][cur.j]==-1){
				dist[cur.i][cur.j]=cur.score;
				// cout<<"Dist : "<<cur.i<<" "<<cur.j<<" = "<<dist[cur.i][cur.j]<<"\n";
				if(mp[cur.i][cur.j]=='D')
					break;
				else{
					checkPush(cur.i+1,cur.j,cur.score,pq);
					checkPush(cur.i-1,cur.j,cur.score,pq);
					checkPush(cur.i,cur.j+1,cur.score,pq);
					checkPush(cur.i,cur.j-1,cur.score,pq);
				}
			}
		}
		// cout<<d.first<<" -> "<<d.second<<"\n";
		cout<<dist[d.first][d.second]<<"\n";
		mp.clear();dist.clear();
	}

}