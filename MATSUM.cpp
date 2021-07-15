//Solution using 2D segment Tree and scanf/printf - Time Limit Exceeded

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int t,n,x1,y1,x2,y2,num;
// string type;
char type[4];
vector<vector<int> > segTree;

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int num){
	// cout<<"update y"<<vx<<" "<<lx<<" "<<rx<<" "<<vy<<" "<<ly<<" "<<ry<<"\n";
	if(ly==ry){
		if(lx==rx) segTree[vx][vy] = num;
		else segTree[vx][vy] = segTree[vx*2][vy]+segTree[vx*2+1][vy];
	}
	else{
		int my = (ly+ry)/2;
		if(y<=my) update_y(vx,lx,rx,vy*2,ly,my,x,y,num);
		else update_y(vx,lx,rx,vy*2+1,my+1,ry,x,y,num);
		segTree[vx][vy] = segTree[vx][vy*2]+segTree[vx][vy*2+1];
	}
}

void update_x(int vx, int lx, int rx, int x, int y, int num){
	// cout<<"update x"<<vx<<" "<<lx<<" "<<rx<<"\n";
	if(lx!=rx){
		int mx = (lx+rx)/2;
		if(x<=mx) update_x(vx*2,lx,mx,x,y,num);
		else update_x(vx*2+1,mx+1,rx,x,y,num);
	}
	update_y(vx,lx,rx,1,0,n-1,x,y,num);
}
void set(int x,int y,int num){
	update_x(1,0,n-1,x,y,num);
}

int sum_y(int vx, int vy,int tly,int try_, int ly, int ry){
	if(ly>ry) return 0;
	if(ly==tly && ry== try_) return segTree[vx][vy];
	int tmy = (tly+try_)/2;
	return sum_y(vx,vy*2,tly,tmy,ly,min(ry,tmy))+sum_y(vx,vy*2+1,tmy+1,try_,max(tmy+1,ly),ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry){
	if(lx>rx) return 0;
	if(lx==tlx&&rx==trx)
		return sum_y(vx,1,0,n-1,ly,ry);
	int tmx = (tlx + trx)/2;
	return sum_x(vx*2,tlx,tmx,lx,min(rx,tmx),ly,ry)+sum_x(vx*2+1,tmx+1,trx,max(tmx+1,lx),rx,ly,ry);
}

int sum(int x1,int y1,int x2,int y2){
	return sum_x(1,0,n-1,x1,x2,y1,y2);
}

int main(){
	// ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		
		cin>>n;
		scanf("%d",&n);
		segTree.clear();
		segTree.resize(4*n,vector<int>(4*n,0));

		while(1){
			// cin>>type;
			scanf("%s",type);
			if(strcmp(type,"END")==0){
				printf("\n");
				break;
			}
			else if(strcmp(type,"SUM")==0){
				// cin>>x1>>y1>>x2>>y2;
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				// cout<<sum(x1,y1,x2,y2)<<"\n";
				printf("%d \n",sum(x1,y1,x2,y2));
			}
			else if(strcmp(type,"SET")==0){
				// cin>>x1>>y1>>num;
				scanf("%d %d %d",&x1,&y1,&num);
				set(x1,y1,num);
			}
		}

	}
}