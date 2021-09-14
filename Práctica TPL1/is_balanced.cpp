#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;

bool is_balanced(string &expr){
	stack<char> S;
	for(size_t i=0;i<expr.size();i++) { 
		
		char c=expr[i];
		
		if(c=='('||c=='['||c=='{'){
			S.push(c);
		} else if(c==')'||c==']'||c=='}'){
			
			if(S.empty()) return false;
			
			char pc=S.top();
			
			switch(c){
			case ')':
				
				if(pc=='(') S.pop(); else return false;
				
			break;
			case ']':
				
				if(pc=='[') S.pop(); else return false;
				
			break;
			case '}':
				
				if(pc=='{') S.pop(); else return false;
				
			break;
			}
			
		};
		
	}
	
	return true;
}

int main(int argc, char *argv[]) {
	
	string test="(que[asd]copado)";
	if (is_balanced(test)) cout << "si"; else cout << "no";
	
	return 0;
}

