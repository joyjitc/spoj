#include <iostream>
#include <sstream>
#include <vector>
#include <string>
// #include <cstdint>
#include <climits>

using namespace std;

int strToNum(string str)
{
	int num = 0;
	int size = str.size();
	// cout<<"hree";
	// cout<<str;
	// cout<<size;
	for(int i = 0; i<size; i++)
	{
		if(!isdigit(str[i]))
			return INT_MAX;
	}
	int mul = 1;

	for(int i = size - 1; i>=0; i--)
	{
		num += ((int)str[i] - 48) * mul;
		mul *= 10;
	}
	return num;
	
}

// long long strToNum(string str)
// {
// 	long long num;

// 	try{
// 		num = stoll(str);
// 	}catch(...){
// 		return (long long)INT_MAX;
// 	}
// 	return num;
	
// }

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	string input;
	int a,b,s;

	// cin>>input;
	// cout<<strToNum(input);
	while(t>0)
	{
		// cout<<"ass"<<endl;
		getline(cin,input);
		// cout<<"input is"<<input<<"+"<<endl;
		if(input.empty())
			continue;
		t--;
		// cout<<input.size();;
		istringstream iss(input);
		vector<string> tokens;
		string elem;

		while(getline(iss,elem,' '))
		{
			tokens.push_back(elem);
		}
        // for(int i = 0; i<tokens.size(); i++)
        // {
        // 	string temp = tokens[i].c;
        // 	cout<<strToNum(temp);
        // }
        
        a = strToNum(tokens[0]);
        b = strToNum(tokens[2]);
        s = strToNum(tokens[4]);

        if(a == INT_MAX)
        	a = s - b;
        else if(b==INT_MAX)
        	b = s - a;
        else
        	s = a + b;

        cout<<a<<" + "<<b<<" = "<<s<<endl;


		// cout<<input;


	}
	return 0;
}