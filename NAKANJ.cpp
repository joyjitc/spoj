#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
void q_push(pair<int,int> pos,int new_d,queue<pair<int,int> >& q,vector<vector<int> >& dis){
	if(pos.first>0&&pos.first<9&&pos.second>0&&pos.second<9&&dis[pos.first][pos.second]==-1){
		q.push(pos);
		dis[pos.first][pos.second]=new_d;
	}
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	string src,des;
	vector<vector<int> > dis;
	pair<int,int> s,d;
	int ans;
	pii cur;
	while(t--){
		cin>>src>>des;
		s=pair<int,int>(src[0]-'a'+1,src[1]-'0');
		d=pair<int,int>(des[0]-'a'+1,des[1]-'0');
	//	cout<<s.first<<" "<<s.second<<"\n";
	//	cout<<d.first<<" "<<d.second<<"\n";
		queue<pair<int,int> > q;
		dis.resize(9,vector<int>(9,-1));
		q_push(s,0,q,dis);
		while(!q.empty()){
			cur=q.front();
			q.pop();
			ans=dis[cur.first][cur.second];
			if(cur==d)
				break;
			q_push(pii(cur.first+2,cur.second-1),ans+1,q,dis);
			q_push(pii(cur.first+2,cur.second+1),ans+1,q,dis);
			q_push(pii(cur.first-2,cur.second+1),ans+1,q,dis);
			q_push(pii(cur.first-2,cur.second-1),ans+1,q,dis);
			q_push(pii(cur.first+1,cur.second+2),ans+1,q,dis);
			q_push(pii(cur.first-1,cur.second+2),ans+1,q,dis);
			q_push(pii(cur.first+1,cur.second-2),ans+1,q,dis);
			q_push(pii(cur.first-1,cur.second-2),ans+1,q,dis);
		}
		cout<<ans<<"\n";
		dis.clear();
	}
}

