#include <iostream>
// -999~999;
int main()
{//adx + bdy = cd
//adx + aey = af
	// aex + bey = ce
	//bdx + bey = fb
	double a, b, c, d, e, f;
	std::cin >> a >> b >> c >> d >> e >> f;
	int x, y;
	y = (c * d - a * f) / (b * d - a * e);
	x = (c * e - b * f) / (a * e - b * d);
	std::cout << x << ' ' << y;
}	