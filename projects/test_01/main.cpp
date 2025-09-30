#include <iostream>
#include <locale>
#include <numbers>


int main()
{
	setlocale(LC_ALL, "Russian");
	const double PI = acos(-1);
	float x = 1.1111111111111f;
	double x1 = 1.111111111111111f;
	float pii = std::numbers::pi;
	std::cout<<pii<<" "<<PI<<std::endl;
	std::cout<<x<<" "<<x1<<std::endl;
	return 0;
	
}