#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int i,j;
void setVisited(vector<vector<int>>& x,pii v,int dist){
	x[v.first][v.second]=dist;
}
int getVisited(vector<vector<int>>& x,pii v){
	return x[v.first][v.second];
}
void checkSetVisitPushQ(vector<vector<int>>& x,queue<pii>& q,pii v,int dist){
	if(v.first>0&&v.first<=i&&v.second>0&&v.second<=j&&x[v.first][v.second]==0){
		setVisited(x,v,dist);
		q.push(v);
	}
}
void checkSetVisitPushQMouse(vector<vector<int>>& x,vector<vector<int>>& ax,vector<vector<int>>& bx,queue<pii>& q,pii v,int dist){
	if(v.first>0&&v.first<=i&&v.second>0&&v.second<=j&&ax[v.first][v.second]!=dist-1&&bx[v.first][v.second]!=dist-1&&x[v.first][v.second]==0){
		checkSetVisitPushQ(x,q,v,dist);
	}
}
int main(){
	ios::sync_with_stdio(0);
	// int n,m;
	cin>>i>>j;
	int t;cin>>t;
	while(t--){
		int mi,mj,ai,aj,bi,bj;
		cin>>mi>>mj>>ai>>aj>>bi>>bj;
		pii m(mi,mj),a(ai,aj),b(bi,bj);
		// if(m==a||m==b){
		// 	cout<<"NO\n";
		// 	continue;
		// }
		bool escape = false;
		vector<vector<int>> mv(i+1,vector<int>(j+1,0)),av(i+1,vector<int>(j+1,0)),bv(i+1,vector<int>(j+1,0));
		queue<pii> mq,aq,bq;
		// setVisited(mv,m,1);setVisited(av,a,1);setVisited(bv,b,1);
		checkSetVisitPushQ(mv,mq,m,1);
		checkSetVisitPushQ(av,aq,a,1);
		checkSetVisitPushQ(bv,bq,b,1);
		int it=2;
		pii cur;
		while(!mq.empty()&&!escape){
			while(!mq.empty()&&getVisited(mv,mq.front())==it-1){
				cur=mq.front();mq.pop();
				if(getVisited(av,cur)==it-1||getVisited(bv,cur)==it-1)
					continue;
				if(cur.first==1||cur.first==i||cur.second==1||cur.second==j){
					escape = true;
					break;
				}
				checkSetVisitPushQMouse(mv,av,bv,mq,pii(cur.first+1,cur.second),it);
				checkSetVisitPushQMouse(mv,av,bv,mq,pii(cur.first-1,cur.second),it);
				checkSetVisitPushQMouse(mv,av,bv,mq,pii(cur.first,cur.second+1),it);
				checkSetVisitPushQMouse(mv,av,bv,mq,pii(cur.first,cur.second-1),it);
			}
			if(escape) break;
			while(!aq.empty()&&getVisited(av,aq.front())==it-1){
				cur = aq.front();aq.pop();
				checkSetVisitPushQ(av,aq,pii(cur.first+1,cur.second),it);
				checkSetVisitPushQ(av,aq,pii(cur.first-1,cur.second),it);
				checkSetVisitPushQ(av,aq,pii(cur.first,cur.second+1),it);
				checkSetVisitPushQ(av,aq,pii(cur.first,cur.second-1),it);
			}
			while(!bq.empty()&&getVisited(bv,bq.front())==it-1){
				cur = bq.front();bq.pop();
				checkSetVisitPushQ(bv,bq,pii(cur.first+1,cur.second),it);
				checkSetVisitPushQ(bv,bq,pii(cur.first-1,cur.second),it);
				checkSetVisitPushQ(bv,bq,pii(cur.first,cur.second+1),it);
				checkSetVisitPushQ(bv,bq,pii(cur.first,cur.second-1),it);
			}
			it++;
		}

		if(escape) cout<<"YES\n";
		else cout<<"NO\n";
	}
}