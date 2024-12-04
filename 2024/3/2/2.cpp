#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string_view>

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

bool tryProcessMult(const std::string& line, size_t& i, int& a, int& b)
{
    int j = i;

    if (line[j] != 'm' 
    || line[j+1] != 'u'
    || line[j+2] != 'l'
    || line[j+3] != '(')
    {
        i = j;
        return false;
    }

    j += 4;

    int aNbDigits = getNbDigits(line, j);
    if (aNbDigits == 0)
    {
        i = j;
        return false;
    }
    j += aNbDigits;

    if (line[j] != ',')
    {
        i = j;
        return false;
    }
    j++;

    int bNbDigits = getNbDigits(line, j);
    if (bNbDigits == 0)
    {
        i = j;
        return false;
    }
    j += bNbDigits;

    if (line[j] != ')')
    {
        i = j;
        return false;
    }
    j++;

    std::string aStr = line.substr(i+4, aNbDigits);
    std::string bStr = line.substr(i+4+aNbDigits+1, bNbDigits);

    a = std::stoi(aStr);
    b = std::stoi(bStr);

    i = j-1;
    return true;
}

bool tryProcessDont(const std::string& line, size_t& i)
{
    constexpr char dontStr[] = "don't()";
    constexpr size_t size = sizeof(dontStr) / sizeof(dontStr[0]) - 1;

    for (int j = 0; j < size; j++)
    {
        if (dontStr[j] != line[i+j])
        {
            return false;
        }
    }

    return true;

    // std::string_view dontStrView(dontStr);
    // std::string_view lineView(line.c_str(), size);
    // i += size-1;
    // return lineView == dontStrView;
}

bool tryProcessDo(const std::string& line, size_t& i)
{
    constexpr char doStr[] = "do()";
    constexpr size_t size = sizeof(doStr) / sizeof(doStr[0]) - 1;

    for (int j = 0; j < size; j++)
    {
        if (doStr[j] != line[i+j])
        {
            return false;
        }
    }

    return true;


    // constexpr char doStr[] = "do()";
    // constexpr size_t size = sizeof(doStr) / sizeof(doStr[0]) - 1;
    // std::string_view doStrView(doStr);
    // std::string_view lineView(line.c_str(), size);
    // i += size-1;
    // return lineView == doStrView;
}

int main()
{
    std::ifstream filein(WORKSPACE_PATH "input.txt");
    
    int total = 0;
    
    bool isEnabled = true;

    std::string line;
    while (std::getline(filein, line))
    {
        for (size_t i = 0; i < line.size() - 8; i++)
        {
            if (isEnabled)
            {
                int a, b;
                size_t iTemp = i;
                if (tryProcessMult(line, iTemp, a, b))
                {
                    total += a * b;
                    i = iTemp;
                    continue;
                }
            }

            size_t iTempDont = i;
            size_t iTempDo = i;
            if (tryProcessDont(line, iTempDont))
            {
                i = iTempDont;
                isEnabled = false;
                continue;
            }
            else if (tryProcessDo(line, iTempDo))
            {
                i = iTempDo;
                isEnabled = true;
                continue;
            }
        }
    }
    
    std::cout << total << std::endl;
}