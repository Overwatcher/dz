#include "header.h"
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
        if (argc < 2) {
            cout << "Usage: program_name size [filename]";
            return 1;
        }
        int n = atoi(argv[1]);
        if (!n) return 1;
        double *a;
        try {
            a = new double[n];
        } catch (bad_alloc &ba) {
            badAllocHandler(ba);    //Program termination
        }
        if (argc >= 3) {
            int error = readFromFile(argv[2], a, n);
            if (error) {
                    errorHandler(error);
                    return 1;
            }
        } else {
            generateArray(a, n);
        }
        int newSize = throwAway(a, n);
        printArray(a, newSize);
        delete a;
        return 0;
}  


