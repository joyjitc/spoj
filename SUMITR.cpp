#include<ios>
#define l(x,y) for(x=1;x<=y;x++)
int a[101][101],i,j,n,t;main(){scanf("%d",&t);while(t--){scanf("%d",&n);l(i,n)l(j,i){scanf("%d",&a[i][j]);a[i][j]=std::max(a[i-1][j],a[i-1][j-1])+a[i][j];}i=0;l(j,n)i=std::max(i,a[n][j]);printf("%d\n",i);}}
