#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <sstream>
using namespace std; 


void stringTokenize(string& s, vector<string>& tokens, char delim) {
	stringstream ss(s); 
	string token; 
	while (getline(ss, token, delim)) {
		tokens.push_back(token); 
	}
}

int compute(string& exp, map<string, int>& precedence, std::map<string, string>& associativity) {
	stack<string> op_stack;
	vector<string> tokens; 
	vector<string> op_queue; 
	
	stringTokenize(exp, tokens, ' '); 
	
	for (auto token : tokens) {
		// cout << "Processing token : " << token << endl; 
		
		if (token == "(") {
			op_stack.push(token); 
		}
		else if (precedence.find(token) != precedence.end()) {
			// this is an operator.  Check if operator at the top of the stack is of higher precedence
		
			if (associativity[token] == "left") {
				// cout << "Associativity is left" << endl;
				while (!op_stack.empty() && op_stack.top() != "(" && op_stack.top() != ")" && precedence[op_stack.top()] >= precedence[token]) {
					op_queue.push_back(op_stack.top());
					op_stack.pop();  
				}
			}
			else { // associativity is right. 
				// cout << "Associativity is right" << endl; 
				while (!op_stack.empty() && op_stack.top() != "(" && op_stack.top() != ")" && precedence[op_stack.top()] > precedence[token]) {
					op_queue.push_back(op_stack.top());
					op_stack.pop();  
				}
			}
			op_stack.push(token); 
		}
		else if (token == ")") {
			while(!op_stack.empty() && op_stack.top() != "(") {
				op_queue.push_back(op_stack.top()); 
				op_stack.pop(); 
			}
			op_stack.pop(); // Discard the opening parenthesis. 
		}
		else {
			//ASsume its a number
			op_queue.push_back(token);
		}
	} 

	while (!op_stack.empty()) {
 		op_queue.push_back(op_stack.top()); 
		op_stack.pop(); 
	}

	cout << "The RPN of the expression is : " ;

	for (auto o : op_queue) {
		cout << o << " "; 
	} 
	cout << endl; 
	
	cout << "Need to compute the RPN now" << endl; 

	stack<double> op; 
	double result; 
	for (auto c : op_queue) {

		if (precedence.find(c) != precedence.end()) {
			// operator : 
			double x = op.top();
			op.pop();
			double y = op.top(); 
			op.pop(); 

			if (c == "+") {
				result = x+y; 
			}
			else if (c == "-") {
				result = x-y; 
			}
			else if (c == "*") {
				result = x*y; 
			}
			else if (c == "/") {
				result = x/y; 
			}
			else if (c == "^") {
				result = pow(x,y); 
			}
			op.push(result); 
		}
		else {
			//Assuming its a number
			stringstream ss(c); 
			double num; 

			ss >> num; 
			op.push(num); 
		}
	}

	return op.top(); 
}


int main() {
	map<string, int> precedence; 

	precedence["^"] = 4;
	precedence["*"] = 3;
	precedence["/"] = 3;
	precedence["+"] = 2;
	precedence["-"] = 2;

	map<string, string> associativity; 
	associativity["^"] = "right"; 
	associativity["*"] = "left"; 
	associativity["/"] = "left"; 
	associativity["+"] = "left"; 
	associativity["-"] = "left"; 


	string exp = "3 + 4 * 2 / ( 1 - 5 )"; //" ^ 2 ^ 3";

	double result = compute(exp, precedence, associativity); 

	cout << "The result of exp : "  << exp << " is : " << result << endl;

	return 0;  
}