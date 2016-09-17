#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <new>
using namespace std;

const int FILE_NOT_FOUND    =   1;
const int UNEXP_EOF         =   2;
const int WRONG_DATA        =   3;
const double eps            =   0.0001;

int readFromFile(const char * filename, double *a, int n);
void errorHandler(int error);
void badAllocHandler(bad_alloc &ba);
int _markToDel(int *toDel, int i);
void _shiftToDel(int *toDel);
int throwAway(double *a, int n);
void printArray(double *a, const int n);
void generateArray(double *a, const int n);
