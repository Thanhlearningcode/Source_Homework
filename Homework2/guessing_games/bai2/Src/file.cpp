#include "file.h"
#include <iostream>
#include <stdexcept>

using namespace std;

bool parseFilename(const string& filename, int& number, string& ext)
  {
    size_t dotPos = filename.find('.');
    if (dotPos == string::npos)
     {
        return false;
     }
    
    try
     {
        number = stoi(filename.substr(0, dotPos)); //< Lay so
     } 
    catch (const std::exception& e)
     { 
        return false;
     }
    
    ext = filename.substr(dotPos + 1); //< expansion
    
    return (ext == "txt" || ext == "png");
  }

