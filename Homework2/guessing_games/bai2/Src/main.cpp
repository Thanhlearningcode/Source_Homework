#include <iostream>
#include <string>
#include "file.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) 
   	 {
        cerr << "Error: The program requires exactly 2 arguments." << endl;
        return EXIT_FAILURE;
   	 }

    int num1, num2;
    string ext1, ext2;

    if (!parseFilename(string(argv[1]), num1, ext1) || 
        !parseFilename(string(argv[2]), num2, ext2)) {
        cerr << "Error: Invalid filename format. Must be <INT>.<EXT> with .txt or .png" << endl;
        return EXIT_FAILURE;
    }

    if (ext1 == "txt" && ext2 == "txt")
   	{
        cout << (num1 + num2) / 2 << endl; //< Trung bình cộng
    	} 
    else if (ext1 == "png" && ext2 == "png")
        {
        cout << num1 + num2 << endl; //< Tong
        } 
    else if (ext1 == "txt" && ext2 == "png")
        {
             if (num2 == 0)
	      {
            cerr << "Error: Division by zero!" << endl;
            return EXIT_FAILURE;
       	      }
        cout << (num1 % num2) << endl; 
        } 
    else
        {
        cerr << "Error: Unsupported file extensions." << endl;
        return EXIT_FAILURE;
        }
    return EXIT_SUCCESS;
}

