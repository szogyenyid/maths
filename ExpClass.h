#pragma once
#include <iostream>
#include <string>

const bool TESTING_ON = true;

class Expression {
private:
	std::string expression; //the expression we got
	bool isNum; //is expression is a number, it's true
	char value; //the value of the current node
	Expression* left; //the expression on the left (if isNum, it's NULL)
	Expression* right; //the expression on the right (if isNum, it's NULL)
	bool isLeaf; //if value is a searched variable or constant, it's true
//------------------------------------
	//sets the isNum member
	void isntNum() {
		bool isntNum = false;;
		char nums[10] = {'0', '1','2','3','4','5','6','7','8','9'};
		for (int i = 0; i < expression.length(); i++) {
			if (isntNum) break;
			for (int j = 0; j < 10; j++) {
				if (expression[i] == nums[j]) {
					isntNum = false;
					break;
				}
				else isntNum = true;
			}
		}
		if (isntNum) isNum = false;
		else isNum = true;
		if (TESTING_ON) std::cout << "instNum in expression " << expression <<" \"returned\" with " << isNum << std::endl;
	}
	//splits the expression at the first = sign
	void getEqu() {
		std::string leftExp;
		std::string rightExp;
		for (unsigned short int i = 0; i < expression.length(); i++) {
			if (expression[i] == '=') {
				value = '=';
				leftExp = expression.substr(0, i);
				rightExp = expression.substr(i + 1, expression.length() - i - 1);
				left = new Expression(leftExp);
				right = new Expression(rightExp);
				//std::cout << leftExp << " = " << rightExp << std::endl;
				return;
			}
		}
	}

	void parse() {
		getEqu();
	}

public:
	Expression(std::string s){
		expression = s;
		isNum = true;
		isntNum();
		if (isNum) {
			left = nullptr;
			right = nullptr;
		}
		else {
			parse();
		}
	};
};