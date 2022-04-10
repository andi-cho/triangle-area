#include <iostream>
#include <cmath>
using namespace std;

void getSides(double*, double*, double*); 
void triangle(double, double, double, double*, double*); 

int main() {
	double s1, s2, s3, p, a;
	while (true) {
		getSides(&s1, &s2, &s3); 
		if (s1 <= 0 || s2 <= 0 || s3 <= 0) { return -1; }
		triangle(s1, s2, s3, &p, &a);	
		
		// area must be positive and a number
		if (isnan(a) || a <= 0) 
		{
			cout << s1 << "," << s2 << "," << s3 <<": not a triangle" << endl;
			continue; 
		}

		// output perimeter + area for valid triangle
	cout << s1 << "," << s2 << "," << s3 << ": perimeter=" << p << " area=" << a << endl;
	}
	return 0;
}

// get 3 sides from user input
void getSides(double* s1, double* s2, double* s3) 
{
	cout << "Enter first number: ";
	cin >> *s1;
	if (*s1 <= 0) { return; }

	cout << "Enter second number: ";
	cin >> *s2;
	if (*s2 <= 0) { return; }

	cout << "Enter third number: ";
	cin >> *s3;
	if (*s3 <= 0) { return; }
}

// compute area + perimeter
void triangle(double s1, double s2, double s3, double* p, double *a)
{
	// perimeter  
	*p = s1 + s2 + s3;

	// semi-perimeter
	double s = (s1 + s2 + s3) / 2;

	// area 
	*a = sqrt( s * (s-s1) * (s-s2) * (s-s3) );
}
