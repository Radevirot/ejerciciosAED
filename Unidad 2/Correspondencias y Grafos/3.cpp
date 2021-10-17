#include <iostream>
#include <map>
#include <list>
#include "./listcomp.cpp"
using namespace std;

bool areinverse(map<int,int> &M1, map<int,int> &M2){
	
	if (M1.size()!=M2.size()){
		return false;
	}
	
	auto itM1=M1.begin(), itM2=M2.begin();
	
	while(itM1!=M1.end()){
		itM2 = M2.find(itM1->second);
		if (itM2==M2.end()) return false;
		if (itM2->second != itM1->first) return false;
		++itM1;
	}
	
	return true;
}



int main() {
	
	map<int,int> M1={{1,2},{80,3},{45,4},{24,5}};
	map<int,int> M2={{2,1},{3,80},{4,45},{5,24}};
	
	cout << areinverse(M1,M2);
	
	return 0;
}







