#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

//int loadMatrix(ifstream& inFile, vector<vector<int>>& m1, int& d, int& n);
//PRE:  pass input file opened and verified in main, a 2-D matrix (may not be cleared), 
//      the dimension of the new matrix, and current matrix number 
//POST: if the matrix is good (contains only 0s and 1s) - m1 is loaded and d & n are reset, returns a 1
//      if not good, it returns -1

bool isDigit(string str)
//PRE: Accepts a string
//POST: returns '1' if all numeric, 0 otherwise
{
      for (int i = 0; i < str.length(); i += 2) {
        if (isdigit(str[i]) == false) {
          return false;
        }

      

    }
  return true;
}



void processMatrix(ifstream& inFile, vector<string>& Matrix, int& d) 
//pre:File,Matrix,d
//post:Matrixs is loaded in vector
{
  int n = 0;
  while (!inFile.eof()) {
    string line;
    getline(inFile, line);
    Matrix.push_back(line);
    n += 1;
  }

}
    
void readMatrix(vector<string>& Matrix,vector<vector<int>>& m1, int& d , int m) {
  //pre:total matrix list, current matrix, dimension
  //post:current matrix is loaded in m1
  //iniitalize matrix
    int n = 0,i = 0, j = 0;
    string line;
    bool valid;
    
    line = Matrix[m];
    
    istringstream iss(line);
    //take first value from line
    iss >> d;
    //check if the rest of the line is digits
    valid = isDigit(line);
    if (valid == false) {
      //check if all the numbers are digits
      throw runtime_error("Invalid Matrix: not all digits");
    }
    //store all numbers in a vector, sort order by row
    while(iss >> n) {
      //check if there are numbers out of the range
      if (n != 0 && n != 1) {
        throw invalid_argument("Invalid matrix: not all 1 or 0");
      }
      else {
        vector<int> tempVec(d);
        m1.push_back(tempVec);
        //store the number in the matrix
        m1[i][j] = n;
        j++;
        if (j == d) {
          j = 0;
          i++;
        }
      }

    }
  }


void printVector(vector<vector<int>>& m1, int& d) {
  //pre:matrix, dimension
  //Post:matrix is printed
  //initilize the set new line
  int displayednum = 0;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      //print the number
      cout << setw(15) << m1[i][j] << " ";
      displayednum++;
      if (displayednum == d) {
        cout << endl;
        displayednum = 0;
      }
    }
  }
  cout << endl;
}


int loadMatrix(ifstream& inFile, vector<vector<int>>& m1, int& d, int& n) { //did not use
  //Pre:file, matrix, dimension, matrix number
  //Post:matrix of dimension d is loaded in m1
  int temp;
  //check if the file is open
  if (!inFile.is_open()) {
    return -1;
  }
  // take the deminsion from the first number
  inFile >> d;
  if (d < 1) {
    return -1;
  }
  //resize the rows in the matrix
  m1.resize(d);
  for (int i = 0; i < d; i++) {
    //resize the columns in the matrix
    m1[i].resize(d);
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      inFile >> temp;
      if (temp != 0 && temp != 1) {
        return -1;
      }
      m1[i][j] = temp;
    }
  }
  return 1;
}


//SUPPORTING FUNCTIONS FOR MATRIX PROCESSING 

//stored the matrix into vectors
void initMatrix(vector<vector<int>>& m1, int d) {
  //pre:matrix, dimension
  //post:makes m1 matrix vector with deminsion d
  int i = 0,j = 0,count = 0;
  //iterate through the size of the whole matrix
  while(count < d * d) {
    
    vector<int> tempVec(d);
    m1.push_back(tempVec);
    m1[i][j] = 0;
    j++;
    if (j == d) {
      j = 0;
      i++;
    }
    count ++;
  }
}

vector<vector<int>> multMatrix(vector<vector<int>> m1, vector<vector<int>> m2, int d)
//PRE: Accepts 2 2-D square vectors & their dimension
//POST: returns the matrix of these vectors multiplied
{
    vector<vector<int>> newT;
    initMatrix(newT, d);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            //initialize the new matrix spot
            newT[i][j] = 0;
            for (int k = 0; k < d; k++) {
                //set the matrix spot to the multiplied values
                newT[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return newT;
}

vector<vector<int>> addMatrix(vector<vector<int>> m1, vector<vector<int>> m2, int d)
//PRE: Accepts 2 2-D square vectors & their dimension
//POST: returns the matrix of these vectors multiplied
{
    vector<vector<int>> newT;
    initMatrix(newT, d);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            //initialize the new matrix spot, sum of the values
            newT[i][j] = m1[i][j] + m2[i][j];
            
        }
    }
    //return the new matrix
    return newT;
}



bool reflexive(vector<vector<int>>& m1, int d) 
//PRE: Accepts a 2-D Vector & valid integer dimension
//POST: returns '1' if all entries on the diagonal are '1', 0 otherwise
{
    //check the diagonal for each sizes of d
    if (d == 2) {
      if (m1[0][0] == 1 && m1[1][1] == 1) {
        return true;
      }
    }
    else if (d == 3) {
      if (m1[0][0] == 1 && m1[1][1] == 1 && m1[2][2] == 1) {
        return true;
      }
    }
    else if (d == 4) {
      if (m1[0][0] == 1 && m1[1][1] == 1 && m1[2][2] == 1 && m1[3][3] == 1) {
        return true;
      }
    }
    else if (d == 5) {
      if (m1[0][0] == 1 && m1[1][1] == 1 && m1[2][2] == 1 && m1[3][3] == 1 && m1[4][4] == 1) {
        return true;
    }
    else {
      //if none match return false
      return false;
    }
  }
  return false;
}

bool symmetric(vector<vector<int>>& m1, int d)
//PRE: Accepts a 2-D Vector & valid integer dimension
//POST: returns '0' if it finds values do not match on opposite sides of the diagonal match, 1 otherwise
{  
    //check the diagonal for each sizes of d
    if (d == 2) {
      if (m1[0][1] == m1[1][0]) {
        return true;
      }
    }
    else if (d == 3) {
      if (m1[0][1] == m1[1][0] && m1[0][2] == m1[2][0] && m1[1][2] == m1[2][1]) {
        return true;
      }
    }
    else if (d == 4) {
      if (m1[0][1] == m1[1][0] && m1[0][2] == m1[2][0] && m1[0][3] == m1[3][0] && m1[1][2] == m1[2][1] && m1[1][3] == m1[3][1] && m1[2][3] == m1[3][2]) {
        return true;
      }
    }
    else if (d == 5) {
      if (m1[0][1] == m1[1][0] && m1[0][2] == m1[2][0] && m1[0][3] == m1[3][0] && m1[1][2] == m1[2][1] && m1[1][3] == m1[3][1] && m1[2][3] == m1[3][2] && m1[0][4] == m1[4][0] && m1[4][3] == m1[3][4] && m1[4][2] == m1[2][4] && m1[4][1] == m1[1][4]) {
        return true;
      }
    }
    else {
      return false;
    }
    return false;
}



bool transitive(vector<vector<int>> m1, vector<vector<int>> p, int d)
//PRE:  Accepts a 2-D vector (m1), a second 2-D vector that is m1*m1, and the dimensions of these vectors (they are equal)
//POST: returns '1' if the vector is transitive, 0 if not
//      A matrix is NOT transitive if there is value in the squared matrix that is non-zero, but is 0 in original
//          (m1[i][j] == 0 && p[i][j] != 0)
//  
{
  int count = 0,i = 0,j = 0;
  while (count < d * d) {
    //check if the value in the squared matrix is non-zero and the value in the original matrix is zero
    if (m1[i][j] == 0 && p[i][j] != 0) {
      return false;
    }
    count ++;
    //iterate thru the matrix
    j++;
    if (j == d) {
      j = 0;
      i++;
    }
  }
  return true;
}

void transativePath(vector<vector<int>> m1, vector<vector<int>> p, int d) {
  //PRE: Accepts a 2-D vector (m1), the transative closure 2-D vector of m1
  //Post:prints if ther is a path
  int  x, y;
  // get specific index of the spot they are checking
  cout << "Enter values between 0 and " << d - 1 << " :" << endl;
  cout << "Enter row: ";
  cin >> x;
  //make sure the value is in the range
  while (x < 0 || x > d - 1) {
    cout << "Invalid value, try again: ";
    cin >> x;
  }
  cout << endl;
  cout << "Enter column: ";
  cin >> y;
  //make sure the value is in the given range
  while (y < 0 || y > d - 1) {
    cout << "Invalid value, try again: ";
    cin >> y;
  }
  cout << endl;
  //check if the corresponding index of the transative closure != 0
  if ((p[x][y] != 0)) {
    cout << "there is a path from row:" << x << " column:" << y << endl;
  }
  else {
    cout << "there is no path from row:" << x << " column:" << y << endl;
  }
}



//FUNCTION DEFINITIONS





void processMatrix(vector<vector<int>>& matrix, int& dim, int n) {}
//PRE:  pass a valid 2-D matrix, the dimension of the matrix, and current matrix number 
//POST: will print if the matrix is reflexive, symmetric, transitive using functions above
