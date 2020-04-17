#include <iostream>
#include <string>
#include <fstream>
#include "container.h"
using namespace std;

int main(int argc, char* argv[])
{
    string outputPath;
    string inputPath;
    if (argc != 3)
    {
        cout << "The output or input files are not entered!\n";
        return true;
    }

    inputPath = argv[1];
    outputPath = argv[2];
    bool success = readFile(inputPath);
    if (!success)
        return false;
    success = writeToFile(outputPath);
    if (!success)
        return false;

    return 0;
}
