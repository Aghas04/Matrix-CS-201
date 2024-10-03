#include "Matrix.h"
using namespace std;

/*
Name:Alex Ghasemi
Date:2/23/24
program name: Matrix converter


Pseudocode:
read matrixes from data.txt
add matrixes to vector
allow user to pick which matrix to use
put user matrix into vector
give errors if the matrix is not valid
print matrix
test if reflexive,symmetric and transitive
calculate the matrix power
calculate transative cloisure
print differnt matrix powers
print transative closure
allow user to find if there is a path 

*/



int main() {
  vector<vector<int>> m1;
  vector<vector<int>> m2,transativeClosure;
  vector<string> matrix;
  int mat;
  int d;
  bool isReflective, isSymmetric, isTransitive;
  ifstream inFile;
  inFile.open("data.txt");
  processMatrix(inFile, matrix, d);
  inFile.close();
  cout << "PROCESSING MATRIX: ";
  cin >> mat;
  while (mat <= 0 || mat > 8) {
    cout << "Invalid matrix number. Please try again." << endl;
    cout << "PROCESSING MATRIX: ";
    cin >> mat;
  }
  readMatrix(matrix, m1, d, mat - 1);
  // readMatrix(inFile,m1,d);
  printVector(m1, d);
  isReflective = reflexive(m1, d);
  isSymmetric = symmetric(m1, d);
  m2 = multMatrix(m1, m1, d);
  isTransitive = transitive(m1,m2, d);
  if (isReflective) {
    cout << "The matrix is reflexive" << endl;
  } else {
    cout << "The matrix is not reflexive" << endl;
  }
  if (isSymmetric) {
    cout << "The matrix is Symmetric" << endl;
  } else {
    cout << "The matrix is not Symmetric" << endl;
  }
  if (isTransitive) {
    cout << "The matrix is transitive" << endl;
  } else {
    cout << "The matrix is not transitive" << endl;
  }
  cout << endl;
  m2 = multMatrix(m1, m1, d);
  transativeClosure = addMatrix(m1,m2,d);
  for (int i = 1; i < d + 1; i++) {
    
    if ((i != 1) && (i != 2)) {
      m2 = multMatrix(m2, m1, d);
      transativeClosure = addMatrix(transativeClosure,m2,d);
    }
    if (i != 1) {
      cout << "Matrix to power of " << i << " : " << endl;
      printVector(m2, d);
    }
  }
  cout << "transative closure: " << endl;
  printVector(transativeClosure, d);
  char check;
  cout << "Would you like to check routes(y/n): ";
  cin >> check;
  while (true) {
    if (check == 'y') {
      transativePath(m1, transativeClosure, d);

    }
    if (check == 'n') {
      break;
    }
    cout << "Would you like to try again (y/n): ";
    cin >> check;
    cout << endl;
  }
  
  
  
}