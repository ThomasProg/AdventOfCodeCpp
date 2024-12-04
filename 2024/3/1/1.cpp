#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

int getNbDigits(const std::string& line, size_t offset)
{
    int nbDigits = 0;
    for (size_t iDigit = offset; iDigit < offset + 3; iDigit++)
    {
        if (line[iDigit] >= '0' && line[iDigit] <= '9')
        {
            nbDigits++;
        }
        else
        {
            break;
        }
    }
    return nbDigits;
}

int main()
{
    std::ifstream filein(WORKSPACE_PATH "input.txt");
    
    int total = 0;
    
    std::string line;
    while (std::getline(filein, line))
    {
        for (size_t i = 0; i < line.size() - 8; i++)
        {
            int j = i;

            if (line[j] != 'm' 
            || line[j+1] != 'u'
            || line[j+2] != 'l'
            || line[j+3] != '(')
            {
                i = j;
                continue;
            }

            j += 4;

            int aNbDigits = getNbDigits(line, j);
            if (aNbDigits == 0)
            {
                i = j;
                continue;
            }
            j += aNbDigits;

            if (line[j] != ',')
            {
                i = j;
                continue;
            }
            j++;

            int bNbDigits = getNbDigits(line, j);
            if (bNbDigits == 0)
            {
                i = j;
                continue;
            }
            j += bNbDigits;

            if (line[j] != ')')
            {
                i = j;
                continue;
            }
            j++;

            std::string aStr = line.substr(i+4, aNbDigits);
            std::string bStr = line.substr(i+4+aNbDigits+1, bNbDigits);

            int a = std::stoi(aStr);
            int b = std::stoi(bStr);

            i = j-1;
            total += a * b;   
        }
    }
    
    std::cout << total << std::endl;
}