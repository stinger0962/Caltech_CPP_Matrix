#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

	// Create a new matrix with two rows and three columns
	Matrix a(2, 3);

	// Print out some information about the size of this matrix:
	cout << "Matrix a is " << a.getRows() << " rows tall." << endl;
	cout << "Matrix a is " << a.getCols() << " columns wide." << endl;

	// Print out the contents of this matrix (should be all zeroes!):
	for (int r = 0; r < a.getRows(); r++) {
		for (int c = 0; c < a.getCols(); c++) {
			cout << "Element (" << r << ", " << c << ") = " << a.getElem(r, c) << endl;
		}
	}

	// Fill in a few values
	a.setElem(1, 2, -5280);  // bottom right element is now -5280
	a.setElem(0, 1, 123);    // top center element is now 123

	// Create an identical copy of this matrix
	Matrix b = a;

	// Change the original matrix some more
	a.setElem(1, 2, 555);  // bottom right element is now 555

	// Examine some elements of each matrix
	cout << "(1,2) of a = " << a.getElem(1, 2) << " [should be 555]" << endl;
	cout << "(1,2) of b = " << b.getElem(1, 2) << " [should be -5280]" << endl;

	// So if a and b are different, let's copy a into a new matrix and add b to it:
	Matrix c = a;
	c.add(b);

	// Now let's copy c into another new matrix and subtract a from it:
	Matrix d = c;
	d.subtract(a);

	// Hmm...  that means d should be b, no?
	if (d.equal(b)) {
		cout << "Yay!  d = b!" << endl;
	}
	else {
		cout << "Uh-oh!  Something went wrong; d isn't b!" << endl;
	}

	// Let's create a tiny 0 by 0 matrix using the default constructor:
	Matrix e;
	cout << "0x0 matrix e is " << e.getRows() << " by " << e.getCols() << endl;

	// Of course, e and d are different, since they have different sizes!
	if (!e.equal(d)) {
		cout << "e and d are indeed different!" << endl;
	}
	else {
		cout << "Oh well, back to the drawing board...." << endl;
	}

	// Okay, enough of this; destroy all those matrices and end the program!
	return 0;
}