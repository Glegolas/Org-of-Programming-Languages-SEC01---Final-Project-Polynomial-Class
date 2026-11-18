#include <iostream>

class Polynomial {
	public:
	
		/* MEMBERS */
		int *expression;
		int degree;
	
		/* CONSTRUCTORS */	
		// Parameterized Degree Constructor
		Polynomial(int maxDegree) {
			degree = maxDegree;
			expression = new int[maxDegree];
			for (int i = 0; i<=maxDegree; ++i) { expression[i] = 2; }
		};
	
		// Array Initialization Constructor
		Polynomial(int coefArray[], int maxDegree) {
			degree = maxDegree;
			expression = coefArray;
		};
	
		// Deep Copy
		Polynomial(const Polynomial &other) {
			degree = other.degree;
			expression = new int[degree];
			for (int i = 0; i<=degree; ++i) { expression[i] = other.expression[i]; }
		};
		
		/* DESTRUCTOR */
		~Polynomial() {
			delete[] expression;
		};
	
		/* OPERATOR OVERLOADS */
		Polynomial operator+(const Polynomial &other) {
			
			// Get max degree
			if (other.degree > degree) {
				int coeffs[other.degree];
				
				for (int i = 0; i<=degree; ++i) {
					coeffs[i] = expression[i] + other.expression[i];
				}
				
				for (int i = degree; i<other.degree; ++i) {
					coeffs[i] = other.expression[i];
				}
				
				return Polynomial(coeffs, other.degree);
			} else if (degree < other.degree) {
				int coeffs[degree];
				
				for (int i = 0; i<=other.degree; ++i) {
					coeffs[i] = expression[i] + other.expression[i];
				}
				
				for (int i = other.degree; i<degree; ++i) {
					coeffs[i] = expression[i];
				}
				
				return Polynomial(coeffs, degree);
			} else {
				int coeffs[degree];
				
				for (int i = 0; i<=degree; ++i) {
					coeffs[i] = expression[i] + other.expression[i];
				}
				
				return Polynomial(coeffs, degree);
			}
			
		};
		
		Polynomial operator-(const Polynomial &other) {
			
			// Get max degree
			if (other.degree > degree) {
				int coeffs[other.degree];
				
				for (int i = 0; i<=degree; ++i) {
					coeffs[i] = expression[i] - other.expression[i];
				}
				
				for (int i = degree; i<other.degree; ++i) {
					coeffs[i] = other.expression[i];
				}
				
				return Polynomial(coeffs, other.degree);
			} else if (degree < other.degree) {
				int coeffs[degree];
				
				for (int i = 0; i<=other.degree; ++i) {
					coeffs[i] = expression[i] - other.expression[i];
				}
				
				for (int i = other.degree; i<degree; ++i) {
					coeffs[i] = expression[i];
				}
				
				return Polynomial(coeffs, degree);
			} else {
				int coeffs[degree];
				
				for (int i = 0; i<=degree; ++i) {
					coeffs[i] = expression[i] - other.expression[i];
				}
				
				return Polynomial(coeffs, degree);
			}
			
		};
		
		// Multiplication
		Polynomial operator*(const Polynomial &other) {
		}
		
		// Evaluate for x.
		Polynomial operator()(int input) {
		}
		
		// Print out polynomial in algebriac format.
		void show() {
			for (int i = degree; i>=2; --i) {
				std::cout<< expression[i] << "x^" << i;
				if (degree != 2) {
					std::cout<< " + ";
				}
			}
			
			if (degree > 0 && expression[1] != 0) {
				std::cout<< " + " << expression[1] << "x";
			}
			
			if (expression[0] != 0) {
				std::cout << " + " << expression[0];
			}
			
			std::cout<<std::endl;
		};
		
};

int main()
{
	Polynomial test1(2);
	Polynomial test2(2);
	
	// Polynomial res = test1+test2;
	test1.show();
    
    return 0;
}