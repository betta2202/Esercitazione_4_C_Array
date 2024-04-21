#pragma once
#include "iostream"
#include "string"

using namespace std;

// fileName, n, S, w, r
double dotProduct(const double * const& vec1,
                  const double * const& vec2,
                  const size_t& n);

bool ImportFile(const string& fileName,
                size_t& n,
                unsigned int& S,
                double *& w, double *& r);

bool PrintResult(const size_t& n,
                 const unsigned int& S,
                 const double * const& w,
                 const double * const& r,
                 const double & rate,
                 const double & V);

bool ExportResult(const string& FileName,
                  const size_t& n,
                  const unsigned int& S,
                  const double * const& w,
                  const double * const& r,
                  const double & rate,
                  const double & V);

