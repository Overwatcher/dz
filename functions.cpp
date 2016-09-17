#include "header.h"
using namespace std;
int readFromFile(const char * filename, double *a, int n) {
    fstream fs;
    fs.open(filename, fstream::in);
    if (!fs.good()) {
        return FILE_NOT_FOUND;
    }
    int i = 0;
    while (i < n && !fs.eof()) {
        fs >> a[i];
        if (fs.fail()) {
            fs.close();
            return WRONG_DATA;
        }
        i++;
    }
    fs.close();
    if (i < n) {
        return UNEXP_EOF;
    }
    return 0;
}

void errorHandler(int error) {
    switch (error) {
        case FILE_NOT_FOUND:
                cout << "Log[ERR]: File not found\n";
                return ;
        case WRONG_DATA:
                cout << "Log[ERR]: Wrong data format\n";
                return ;
        case UNEXP_EOF:
                cout << "Log[ERR]: Not enough data\n";
                return;
    }
}
void badAllocHandler(bad_alloc &ba) {
    cout << "Log[ERR]: Allocating error\n";
    exit(EXIT_FAILURE);
}
int _markToDel(int *toDel, int i) {
    int j;
    for (j = 0; j < 2; j++) {
        if (toDel[j] == -1) {
            toDel[j] = i;
            return j;
        }
    }
    return j;
}

void _shiftToDel(int *toDel) {
    toDel[0] = toDel[1];
    toDel[1] = -1;
}


int throwAway(double *a, int n) {
    int curIndex = 2;
    int i = 0;
    int j = 1;
    int curSize = n;
    int toDel[] = {-1, -1};
        while (curIndex < n - 2) {
            if (toDel[0] < i && toDel[0] != -1) {
            a[toDel[0]] = a[i];
            _shiftToDel(toDel);
            curSize--;
        }
        double p = a[i] * a[j] * a[curIndex + 1] * a[curIndex + 2];
        if (p >= 0 && sqrt(sqrt(p)) > a[curIndex]) {
            _markToDel(toDel, curIndex);
        }
        if (i != j - 1) cout << "Log[DBG]: i + 1 != j\n";
        i = j;
        j = curIndex;
        curIndex++;
    }
    while (curIndex < n) {
        if (toDel[0] < i && toDel[0] != -1) {
            a[toDel[0]] = a[i];
            _shiftToDel(toDel);
            curSize--;
        }
        i = j;
        j = curIndex;
        curIndex++;
    }
    return curSize;
}


void printArray(double *a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

void generateArray(double *a, const int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}
