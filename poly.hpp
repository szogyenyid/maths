#ifndef POLY_HPP
#define POLY_HPP

#include <iostream>
#include <vector>

class poly {
public:
	poly(const int d, const std::vector<int> v) : deg(d), coeff(v) {}; 
	friend std::ostream& operator<<(std::ostream& out, poly p);

private:
	int deg;
	std::vector<int> coeff;
};

#endif