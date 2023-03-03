#include <iostream>
#include <cmath>
using namespace std;

float raiz(float x , float xo , float e)
{
	if (e >= (abs ( xo * xo - x)))
		return xo;
	else
		return raiz(x, (((xo * xo) + x) / (2 * xo)), e);
}

int main()
{
	float x, xo , e;
	float r ; //resultado
	cin >> x >> xo >> e;

	r = raiz (x, xo, e);

	cout << r << endl;
	return 0;
}
