#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int loadMatrix(ifstream& inFile, vector<vector<int>>& m1, int& d, int& n);
//PRE:  pass input file opened and verified in main, a 2-D matrix (may not be cleared), 
//      the dimension of the new matrix, and current matrix number 
//POST: if the matrix is good (contains only 0s and 1s) - m1 is loaded and d & n are reset, returns a 1
//      if not good, it returns -1

void processMatrix(vector<vector<int>>& m1, int& d, int n);
//PRE:  pass a valid 2-D matrix, the dimension of the matrix, and current matrix number 
//POST: will print if the matrix is reflexive, symmetric, transitive


void printVector(vector<vector<int>> m1, int d);
//PRE:  pass a valid 2-D matrix & the dimension of the matrix
//POST: prints the matrix
