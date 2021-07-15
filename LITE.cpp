#include <iostream>
#include <vector>

using namespace std;

vector<int> segTree;
vector<bool> lazy;
int n,m;

void build(int node, int start, int end){
	if(start != end){
		int mid = (start + end)/2;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		segTree[node] = segTree[node*2] + segTree[node*2+1]; 
	}
}

void update(int node, int start, int end, int l, int r){

	// cout<<" UPDATE:: node:"<<node<<" start:"<<start<<" end:"<<end<<" l:"<<l<<" r:"<<r<<"\n";

	if(lazy[node]==1){
		// cout<<"  Lazy Node\n";
		segTree[node] = (end - start + 1) - segTree[node];
		if(start!=end){
			lazy[node*2] = (lazy[node*2]+1)%2;
			lazy[node*2+1] = (lazy[node*2+1]+1)%2;
		}
		lazy[node] = 0;
		// for(int px=0;px<4*n+1;px++){
		// 	cout<<px<<" on: "<<segTree[px]<<" lazy: "<<lazy[px]<<"\n";
		// }
	}

	if(start>end or end<l or start>r){
		// cout<<"  Out of Range\n";
		return;
	}
	
	if(start>=l and end<=r){
		// cout<<"  In Range\n";
		segTree[node] = (end - start + 1) - segTree[node];
		if(start!=end){
			lazy[node*2] = (lazy[node*2]+1)%2;
			lazy[node*2+1] = (lazy[node*2+1]+1)%2;
		}
		// for(int px=0;px<4*n+1;px++){
		// 	cout<<px<<" on: "<<segTree[px]<<" lazy: "<<lazy[px]<<"\n";
		// }
		return;
	}

	// cout<<"  Semi Range\n";
	int mid = (start + end)/2;
	update(node*2, start, mid, l, r);
	update(node*2+1, mid+1, end, l, r);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
	// cout<<" UPDATE:: node:"<<node<<" start:"<<start<<" end:"<<end<<" l:"<<l<<" r:"<<r<<"\n";
	// cout<<"  Semi Range Result\n";
	// for(int px=0;px<4*n+1;px++){
	// 		cout<<px<<" on: "<<segTree[px]<<" lazy: "<<lazy[px]<<"\n";
	// 	}
}

int query(int node, int start, int end, int l, int r){

	// cout<<" QUERY:: node:"<<node<<" start:"<<start<<" end:"<<end<<" l:"<<l<<" r:"<<r<<"\n";

	if(start>end or end<l or start>r){
		// cout<<"  Out of Range\n";
		return 0;
	}

	if(lazy[node]==1){
		// cout<<"  Lazy Node\n";
		segTree[node] = (end - start + 1) - segTree[node];
		if(start!=end){
			lazy[node*2] = (lazy[node*2]+1)%2;
			lazy[node*2+1] = (lazy[node*2+1]+1)%2;
		}
		lazy[node] = 0;
		// for(int px=0;px<4*n+1;px++){
		// 	cout<<px<<" on: "<<segTree[px]<<" lazy: "<<lazy[px]<<"\n";
		// }
	}
	
	if(l<=start and end<=r){
		// cout<<"  In Range\n";
		return segTree[node];
	}

	// cout<<"  Semi Range\n";
	int mid = (start + end)/2;
	return query(node*2, start, mid, l, r) + query(node*2+1, mid+1, end, l, r);
}

int main(){
	ios::sync_with_stdio(0);

	cin>>n>>m;

	segTree.resize(4*n+1,0);
	lazy.resize(4*n+1,0);

	build(1,0,n-1);

	// for(int px=0;px<4*n+1;px++){
	// 	cout<<px<<" on: "<<segTree[px]<<" lazy: "<<lazy[px]<<"\n";
	// }

	int type,begin,end;
	for(int i=0;i<m;i++){
		cin>>type>>begin>>end;
		if(type==0){
			update(1,0,n-1,begin-1,end-1);
		}
		else if(type==1){
			cout<<query(1,0,n-1,begin-1,end-1)<<"\n";
		}
		// cout<<"IN THE END\n";
		// for(int px=0;px<4*n+1;px++){
		// 	cout<<px<<" on: "<<segTree[px]<<" lazy: "<<lazy[px]<<"\n";
		// }
	}
}