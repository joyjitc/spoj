#include <iostream>
#include <tr1/unordered_map>

using namespace std;
tr1::unordered_map<int,int> memo;

using namespace std;

int size;
string input;


int ctoi(char ch)
{
	return ((int)ch - 48);
}

int cal(int num)
{
	if(memo.find(num)!= memo.end())
		return memo[num];
	if(num<4)
		return num;
	else
	{
		int X = cal(num - 1) + cal(num-2);
		memo[num]  = X;
		return X;
	}
}
	
int acode(int pos)
{
	if(input[pos]=='0')
		return 0;
	if(pos == size - 1 || pos == size)
		return 1;
	if(ctoi(input[pos])>2){
		// cout<<" "<<pos<<" "<<endl;
		return acode(++pos);
	}	
	int i = pos;
	int num = 0;
	while( i<size && (input[i] == '1' || input[i]=='2'))

	{
		num++;
		i++;
	}
	// cout<<num<<endl;
	if(i==size)
		return cal(num);
	if(input[i]=='0')
	{
		num--;
		// cout<<num<<endl;
		return cal(num)*acode(++i);

	}
	if(input[i-1]=='1')
	{
		num++;
		return cal(num)*acode(++i);
	}
	else
	{
		if(ctoi(input[i])>6)
		{
			return cal(num)*acode(i);
		}
		else
		{
			num++;
			return cal(num)*acode(++i);
		}
	}
}
int main()
{	
	memo.insert(pair<int,int>(0,1));
	while(cin>>input)
	{
		if(input == "0")
			break;
		size = input.size();
		// cout<<"Size = "<<size<<endl;
		cout<<acode(0)<<endl;
	}
	return 0;
}