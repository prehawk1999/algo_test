#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::to_string;


class Solution {
public:
    int evalRPN(vector<string> & tokens) {
		string optA, optB;
        stack<string> bag;
		string temp; 
		for(vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); ++iter){ 
			if(*iter == string("+")){
				getOpt(optA, optB, bag);  
				bag.push( to_string(getVal(optA) + getVal(optB)) );
			}
			else if(*iter == string("-")){
				getOpt(optA, optB, bag); 
				bag.push( to_string(getVal(optA) - getVal(optB)) );
			}
			else if(*iter == string("*")){
				getOpt(optA, optB, bag); 
				bag.push( to_string(getVal(optA) * getVal(optB)) );
			}
			else if(*iter == string("/")){
				getOpt(optA, optB, bag); 
				bag.push( to_string(getVal(optB) / getVal(optA)) );
			}
			else{
				bag.push(*iter);
			} 
		} 
		return getVal(bag.top());
    }

	int getVal(string s){
		stringstream ss(s);
		int val;
		ss >> val;
		return val;
	}
	void getOpt(string & optA, string & optB, stack<string> & bag){
		optA = bag.top(); bag.pop();
		optB = bag.top(); bag.pop();
	}
};

void test_main(){
	Solution s = Solution();
	vector<string> token;
	token.push_back(string("2"));
	token.push_back(string("1"));
	token.push_back(string("+"));
	token.push_back(string("3"));
	token.push_back(string("*"));
	token.push_back(string("0"));
	token.push_back(string("/"));
	cout << s.evalRPN(token) << endl; 
}