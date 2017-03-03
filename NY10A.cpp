#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;

	int index;
	string input;

	while(t--){
		int res[9] = {0};

		cin>>index;
		cin>>input;

		for(int i =0;i<=37;i++){
			if(input[i]=='T'){
				if(input[i+1]=='T'){
					if(input[i+2]=='T')
						res[1]++;
					else
						res[2]++;
				}
				else{
					if(input[i+2]=='T')
						res[3]++;
					else
						res[4]++;

				}
			}
			else{
				if(input[i+1]=='T'){
					if(input[i+2]=='T')
						res[5]++;
					else
						res[6]++;
				}
				else{
					if(input[i+2]=='T')
						res[7]++;
					else
						res[8]++;

				}

			}
		}

	printf("%d %d %d %d %d %d %d %d %d\n",index,res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8]);
	}
	return 0;
}