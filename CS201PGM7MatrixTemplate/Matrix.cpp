#include "Matrix.h"
using namespace std;

//SUPPORTING FUNCTIONS FOR MATRIX PROCESSING 


void initMatrix(vector<vector<int>>& m1, int d) 
//PRE: Accepts a 2D Vector & valid integer for dimension
//POST: Initializes m1 to 0s;
{
    std::cout << "CODE THIS\n";
}

bool isDigit(string str)
//PRE: Accepts a string
//POST: returns '1' if all numeric, 0 otherwise
{
    std::cout << "CODE THIS\n";
    return true;
}

vector<vector<int>> multMatrix(vector<vector<int>> m1, vector<vector<int>> m2, int d)
//PRE: Accepts 2 2-D square vectors & their dimension
//POST: returns the matrix of these vectors multiplied
{
    vector<vector<int>> newT;
    initMatrix(newT, d);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            newT[i][j] = 0;
            for (int k = 0; k < d; k++) {
                newT[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return newT;
}

bool reflexive(vector<vector<int>>& m1, int d) 
//PRE: Accepts a 2-D Vector & valid integer dimension
//POST: returns '1' if all entries on the diagonal are '1', 0 otherwise
{
    std::cout << "CODE THIS\n";
    return 0;
}

bool symmetric(vector<vector<int>>& m1, int d)
//PRE: Accepts a 2-D Vector & valid integer dimension
//POST: returns '0' if it finds values do not match on opposite sides of the diagonal match, 1 otherwise
{
    std::cout << "CODE THIS\n";
    return 0;
}

 
bool transitive(vector<vector<int>> m1, vector<vector<int>> p, int d)
//PRE:  Accepts a 2-D vector (m1), a second 2-D vector that is m1*m1, and the dimensions of these vectors (they are equal)
//POST: returns '1' if the vector is transitive, 0 if not
//      A matrix is NOT transitive if there is value in the squared matrix that is non-zero, but is 0 in original
//          (m1[i][j] == 0 && p[i][j] != 0)
//  
{
    std::cout << "CODE THIS\n";
    return 0;
}

//FUNCTION DEFINITIONS

int loadMatrix(ifstream& inFile, vector<vector<int>>& m1, int& d, int& n)
//PRE:  pass input file opened and verified in main, a 2-D matrix (may not be cleared), 
//      the dimension of the new matrix, and current matrix number 
//POST: if the matrix is good (contains only 0s and 1s) - m1 is loaded and d & n are reset, returns a 1
//      if not good, it returns -1
{
    std::cout << "CODE THIS\n";
    return -1;
}

void printVector(vector<vector<int>> m1, int d) {
    std::cout << "CODE THIS\n";
    return;
}

void processMatrix(vector<vector<int>>& matrix, int& dim, int n)
//PRE:  pass a valid 2-D matrix, the dimension of the matrix, and current matrix number 
//POST: will print if the matrix is reflexive, symmetric, transitive using functions above
{

}