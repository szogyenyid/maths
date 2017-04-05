#include "poly.hpp"

//todo: ha az együttható 1, akkor csak simán x^d legyen, ne 1x^d
//		negatív számokra is jól nézzen ki (5x^2 - 2x - 1)
std::ostream& operator<<(std::ostream& out, const poly p) {
	unsigned int d = p.deg;
	switch (d) {
		default:
			while(d > 1) {
				if (p.coeff[d] != 0) 
					out << p.coeff[d] << "x^" << d << " + ";
				d--;
			}
		case 1:
			if(p.coeff[d] != 0)
				out << p.coeff[d] << "x + ";
		case 0:
			out << p.coeff[d];
			break;			
	}
	return out;
}

poly& poly::operator+=(const poly& rhs) {
	if (rhs.deg > deg) {
		for (int i = 0; i <= deg; i++) {
			coeff[i] += rhs.coeff[i];
		}
		for (int i = deg+1; i <= rhs.deg; i++) {
			coeff.push_back(rhs.coeff[i]);
		}		
	} else
	{
		for (int i = 0; i <= rhs.deg; i++) {
			coeff[i] += rhs.coeff[i];
		}
	}	
	return *this;
}

const poly poly::operator+(const poly& rhs) const {
	poly result = *this;
	result += rhs;
	return result;
}

poly& poly::operator-=(const poly& rhs) {
	if (rhs.deg > deg) {
		for (int i = 0; i <= deg; i++) {
			coeff[i] -= rhs.coeff[i];
		}
		for (int i = deg+1; i <= rhs.deg; i++) {
			coeff.push_back(-rhs.coeff[i]);
		}		
	} else
	{
		for (int i = 0; i <= rhs.deg; i++) {
			coeff[i] -= rhs.coeff[i];
		}
	}	
	return *this;
}

const poly poly::operator-(const poly& rhs) const {
	poly result = *this;
	result -= rhs;
	return result;
}

int main() {
	
	std::vector<int> v(5);
	poly sajtban(v);
	poly copy = sajtban - sajtban;
	poly test;
	
	std::cout << copy << " " << test << '\n';

}