#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

int main()
{
    string fileName = "data.csv";
    size_t n = 0;
    unsigned int S = 0;
    double *w = nullptr;
    double *r = nullptr;

    if(!ImportFile(fileName, n, S, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout << "Import successful" << endl;

    double rate = dotProduct(w, r, n);
    double V = S*(1+rate);

    fileName = "result.txt";
    if(!ExportResult(fileName, n, S, w, r, rate, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;


    delete [] w;
    delete [] r;


    return 0;
}

