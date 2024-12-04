// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <vector>
// #include <algorithm>
// #include <cassert>

// // Not working when the 2nd number is the reason of a change in increase / decrease error
// // 74 76 72 71 68 66

// bool isReportSafe(const std::string& line, int nbErrors = 0)
// {
//     std::string nStr; 
//     std::istringstream lineStream(line);

//     std::getline(lineStream, nStr, ' ');
//     int n = std::stoi(nStr);
//     int last = n; 

//     int sign = 0;

//     while(std::getline(lineStream, nStr, ' ')) 
//     {
//         int n = std::stoi(nStr);
        
//         int diff = n - last;
//         int absDiff = std::abs(diff);

//         if (absDiff < 1 || absDiff > 3)
//         {
//             nbErrors++;
//             if (nbErrors == 1)
//             {
//                 continue;
//             }
//             else
//             {
//                 return false;
//             }
//         }
        
//         int newSign = diff / absDiff;
//         if (newSign != sign && sign != 0)
//         {
//             nbErrors++;
//             if (nbErrors == 1)
//             {
//                 continue;
//             }
//             else
//             {
//                 return false;
//             }
//         }

//         sign = newSign;
//         last = n;
//     }

//     return true;
// }

// int main()
// {
//     std::ifstream filein(WORKSPACE_PATH "input.txt");

//     int nbValidReports = 0;
//     for (std::string line; std::getline(filein, line); ) 
//     {
//         bool isCorrect = false;
//         if (isReportSafe(line))
//         {
//             isCorrect = true;
//             nbValidReports++;
//         }
//         else
//         {
//             size_t index = line.find(' ');
//             if (isReportSafe(line.substr(index+1), 1))
//             {
//                 isCorrect = true;
//                 nbValidReports++;
//             }
//         }

//         if (isCorrect)
//         {
//             std::cout << line << " / safe " << std::endl; 
//         }
//         else 
//         {
//             std::cout << line << " / unsafe " << std::endl; 
//         }
//     }

//     // std::cout << nbValidReports << std::endl;

// }