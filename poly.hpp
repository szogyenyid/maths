#ifndef POLY_HPP
#define POLY_HPP

#include <iostream>
#include <vector>

class poly {
public:
	poly() : deg(0), coeff{0} {};
	poly(const std::vector<int> v) : coeff(v), deg(v.size()-1) {};
	friend std::ostream& operator<<(std::ostream& out, const poly p);
	poly& operator+=(const poly &rhs);
	poly& operator-=(const poly& rhs);
	const poly operator+(const poly& rhs) const;
	const poly operator-(const poly& rhs) const;
private:
	unsigned int deg;
	std::vector<int> coeff;
};

#endif