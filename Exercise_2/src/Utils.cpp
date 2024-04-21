#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

bool ImportFile(const string& fileName,
                size_t& n,
                unsigned int& S,
                double *& w, double *& r)
{
    // Open file
    ifstream fsr(fileName);

    if(fsr.fail()) {
        cerr << "File doesn't exist" << endl;
        return false;
    }

    char delimiter = ';';

    string line;
    string sub_str;

    // line 0
    getline(fsr, line);
    size_t pos = line.find(delimiter);
    if(pos > 1){
        cerr << "Invalid format" << endl;
        return false;
    }
    else{ // Estraction of S from the substring after ;
        sub_str = line.substr(pos + 1);
        S = stoi(sub_str);
    }

    // line 1
    getline(fsr, line);
    pos = line.find(delimiter);
    if(pos > 1){
        cerr << "Invalid format" << endl;
        return false;
    }
    else{ // Estraction of n from the substring after ;
        sub_str = line.substr(pos + 1);
        n = stoi(sub_str);
    }

    // skip line 2
    getline(fsr, line);

    //line 3
    w = new double[n];
    r = new double[n];
    for(int i = 0; i < n; ++i) {
        getline(fsr, line);
        stringstream ss(line);
        string part;
        int count = 0; // counter for each part of the line separated by ;

        // Read every part of the line separated by ';'
        while (getline(ss, part, delimiter)) {
            // Convertion in double
            double number;
            stringstream(part) >> number;
            // Save the number in the correct vector
            if (count == 0) {
                w[i] = number; // first number -> w
            }
            else if (count == 1) {
                r[i] = number; // second number -> r
            }
            count++;
        }
    }

    fsr.close();

    return true;
}

double dotProduct(const double * const& vec1,
                  const double * const& vec2,
                  const size_t& n)
{
    double ris = 0;
    for(int i = 0; i < n; i++)
    {
        ris +=  vec1[i] * (vec2[i]);
    }
    return ris;
}

bool PrintResult(const size_t& n,
                 const unsigned int& S,
                 const double * const& w,
                 const double * const& r,
                 const double & rate,
                 const double & V) // print read data and result on the screen
{
    cout << "S = " << fixed << setprecision(2) << double(S) << ", ";
    // reset default print of double
    cout << defaultfloat;

    cout << "n = " << n << endl;

    cout << "w = [ ";
    for (int i = 0; i < n; ++i) {
        cout << w[i] << " ";
    }
    cout << "]" << endl;

    cout << "r = [ ";
    for (int i = 0; i < n; ++i) {
        cout << r[i] << " ";
    }
    cout << "]" << endl;

    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate << endl;

    cout << "V: " << fixed << setprecision(2) << V << endl;

    return true;
}

bool ExportResult(const string& FileName,
                  const size_t& n,
                  const unsigned int& S,
                  const double * const& w,
                  const double * const& r,
                  const double & rate,
                  const double & V)

{
    ofstream outFile(FileName);

    if(outFile.fail())
    {
        cerr << "File open failed" << endl;
        return false;
    }

    outFile << "S = " << fixed << setprecision(2) << double(S) << ", ";
    // reset default print of double
    outFile << defaultfloat;

    outFile << "n = " << n << endl;

    outFile << "w = [ ";
    for (int i = 0; i < n; ++i) {
        outFile << w[i] << " ";
    }
    outFile << "]" << endl;

    outFile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outFile << r[i] << " ";
    }
    outFile << "]" << endl;

    outFile << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate << endl;

    outFile << "V: " << fixed << setprecision(2) << V << endl;

    outFile.close();

    return true;
}




