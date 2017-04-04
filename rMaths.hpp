#pragma once

template <typename T>
class Expr {
public:
	Expr(T x, T y) : x(x), y(y) {}
private:
	T x,y;
};