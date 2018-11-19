#include<ios>
#include<boost/multiprecision/cpp_int.hpp>
int main(){
	boost::multiprecision::cpp_int N,D,a;
	while(1){
		std::cin>>N>>D;
		if(N==0&&D==0)
			break;
		a=1;
		for(int i=0;i<D;i++)
			a*=N;
		std::cout<<a<<"\n";
	}
}


