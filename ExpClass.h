#pragma once
#include <iostream>
#include <string>

const bool TESTING_ON = true;
//rolan elment.

class Expression {
private:
	std::string expression; //the expression we got
	bool isNum; //is expression is a number, it's true
	char value; //the value of the current node
	Expression* left; //the expression on the left (if isNum, it's NULL)
	Expression* right; //the expression on the right (if isNum, it's NULL)
	bool isLeaf; //if value is a searched variable or constant, it's true
//---------------------------------------------------------------------------------------------------
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
				if (TESTING_ON) {
					std::cout << "Left expression of " << expression << " is " << leftExp << std::endl;
					std::cout << "Right expression of " << expression << " is " << rightExp << std::endl;
				}
				return;
			}
		}
	}

	//the whole parsing | WIP
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
/*  GITHUB Tutorial
	feltoltes:
		0, minden local branchot torolsz
		1, editelsz a kodban
		2, nyitsz az editnek egy uj bracnhet
		3, stageled amit fel akarsz tolteni
		4, commitolod amit editeltel
		5, az elobb letrehozott branchedet pusholod
		6, kersz ra egy pull requestet
		7, a pull request elfogadasa (merge)
		8, pullolsz
		9, torlod a branchet, ha kesz az editeles. ha nincs kesz, akkor goto 1.

	letoltes:
		1, pullolod mastert
		DONE BAZMEG, EZ ILYEN IZI
*/