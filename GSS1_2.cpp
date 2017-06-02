#include <iostream>
#include <limits>
using namespace std;

class S{
public:
	int best;
	int maxLeft;
	int maxRight;
	int total;
};

int n;
S data[200000];

S combine(S L, S R){
	if(L.best == numeric_limits<int>::min()) return R;
	if(R.best == numeric_limits<int>::min()) return L;
	S X;
	X.total=L.total+R.total;
	X.best=max(max(L.best,R.best),L.maxRight+R.maxLeft);
	X.maxLeft=max(L.total+R.maxLeft,L.maxLeft);
	X.maxRight=max(R.total+L.maxRight,R.maxRight);
	return X;
}

void build(){
	for(int i=n-1;i>0;--i) data[i]=combine(data[i<<1],data[i<<1|1]);
}

S query(int l,int r){
	S resl,resr;
	resl.best=resr.best=resl.maxLeft=resr.maxLeft=resl.maxRight=resr.maxRight=numeric_limits<int>::min();
	resl.total=resr.total=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) resl=combine(resl,data[l++]);
		if(r&1)	resr=combine(data[--r],resr);
	}
	return combine(resl,resr);
}

int main(){
	scanf("%d",&n);
	int inp;
	for(int i=0;i<n;i++){
		scanf("%d",&inp);
		data[i+n].best = inp;
		data[i+n].total = inp;
		data[i+n].maxRight = inp;
		data[i+n].maxLeft = inp;
	}
	build();
	int m;
	cin>>m;
	int x,y;
	while(m--){
	 	scanf("%d %d",&x,&y);
	 	S ans = query(--x,y); 
 		cout<<ans.best<<"\n";
 	}
}