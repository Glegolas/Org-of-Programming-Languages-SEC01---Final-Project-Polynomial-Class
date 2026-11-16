#include <iostream>

class Polynomial {
	public:
	
		// MEMBERS
		int *expression;
		int degree;
	
		// CONSTRUCTORS
		Polynomial(int maxDegree) {
			degree = maxDegree;
			expression = new int[maxDegree];
			for (int i = 0; i<maxDegree; ++i) { expression[i] = 2; }
		};
	
		Polynomial(int coefArray[], int maxDegree) {
			degree = maxDegree;
			expression = coefArray;
		};
	
		Polynomial(const Polynomial &other) {
			degree = other.degree;
			expression = new int[degree];
			for (int i = 0; i<degree; ++i) { expression[i] = other.expression[i]; }
		};
		
		// DESTRUCTOR
		~Polynomial() {
			delete expression;
		};
	
		// OPERATOR OVERLOADS
		Polynomial *operator+(const Polynomial &other) {

			
			// Get resulting max degree by picking the largest
			// amongst the two.
			if (other.degree > degree) {
				
				// Create coeff-array buffer with resulting max degree.
				int resCoeffs[other.degree];
				
				for (int i = 0; i<degree; ++i) {
					resCoeffs[i] = expression[i]+other.expression[i];
				}
				
				for (int i = degree; i<other.degree; ++i) {
					resCoeffs[i] = other.expression[i];
				}
				
				return new Polynomial(resCoeffs, other.degree);	
				
			} else if (other.degree < degree) { 
				
				// Create coeff-array buffer with resulting max degree.
				int resCoeffs[degree];
				
				for (int i = 0; i<other.degree; ++i) {
					resCoeffs[i] = expression[i]+other.expression[i];
				}
				
				for (int i = other.degree; i<degree; ++i) {
					resCoeffs[i] = other.expression[i];
				}
				
				return new Polynomial(resCoeffs, degree);
				
			} else {
				
				// Create coeff-array buffer with resulting max degree.
				int resCoeffs[degree];
				
				for (int i = 0; i<degree; ++i) {
					resCoeffs[i] = expression[i]+other.expression[i];
				}
				
				return new Polynomial(resCoeffs, degree);
				
			}
			
		};
		
		Polynomial *operator-(const Polynomial &other) {
			
			// Get resulting max degree by picking the largest
			// amongst the two.
			if (other.degree > degree) {
				
				// Create coeff-array buffer with resulting max degree.
				int resCoeffs[other.degree];
				
				for (int i = 0; i<degree; ++i) {
					resCoeffs[i] = expression[i]-other.expression[i];
				}
				
				for (int i = degree; i<other.degree; ++i) {
					resCoeffs[i] = other.expression[i];
				}
				
				return new Polynomial(resCoeffs, other.degree);	
				
			} else if (other.degree < degree) { 
				
				// Create coeff-array buffer with resulting max degree.
				int resCoeffs[degree];
				
				for (int i = 0; i<other.degree; ++i) {
					resCoeffs[i] = expression[i]-other.expression[i];
				}
				
				for (int i = other.degree; i<degree; ++i) {
					resCoeffs[i] = -other.expression[i];
				}
				
				return new Polynomial(resCoeffs, degree);
				
			} else {
				
				// Create coeff-array buffer with resulting max degree.
				int resCoeffs[degree];
				
				for (int i = 0; i<degree; ++i) {
					resCoeffs[i] = expression[i]-other.expression[i];
				}
				
				return new Polynomial(resCoeffs, degree);
				
			}
			
		};
		
		//Polynomial *operator(const Polynomial &other) {
			//int resMaxDegree = other.degree+degree;
			//int resCoeffs[resMaxDegree];
			
			// Get resulting max degree by picking the largest
			// amongst the two.
		//};
		
};

int main()
{
	Polynomial test1(2);
	Polynomial test2(5);
	Polynomial res = test1+test2;
	
    std::cout<<"Hello World";
    return 0;
}