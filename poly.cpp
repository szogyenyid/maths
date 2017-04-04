#include "poly.hpp"


std::ostream& operator<<(std::ostream& out, poly p) {
	int d = p.deg;
	for (std::vector<int>::iterator it = p.coeff.begin() ; it != p.coeff.end(); ++it){
		if (d > 0)
			out << *it << "x^" << d-- << " + ";
		else
			out << *it;
	}
	return out;
}

int main() {
	
	std::vector<int> v;
	for (int i = 1; i < 6; i++) {
		v.push_back(i);
	}
	
	poly sajtban(v.size()-1, v);
	
	std::cout << sajtban << '\n';
	std::cout << "Nyomj egy gombot a kilepeshez!\n"; 
	std::cin.get();

}