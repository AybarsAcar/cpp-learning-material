//
//  main.cpp
//  streams-io
//
//  Created by Aybars Acar on 13/1/21.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

void grade(std::string fileName);
void copyFile(std::string inFileName, std::string outFileName);
void writeToFile();

int main(int argc, const char * argv[])
{
//  grade("grader.txt");
//  copyFile("file.txt", "copiedFile.txt");
//  writeToFile()
  
  int num{};
  double total{};
  std::string name{};
  
  std::string info {"Moe 100 1234.5"};
  std::istringstream iss {info};
  
  iss >> name >> num >> total;
  std::cout << std::setw(10) << std::left << name
            << std::setw(5) << num
            << std::setw(10) << total << std::endl;
  
  
//  writing similar to StringBuilder
  std::ostringstream oss {};
  std::cout << std::setw(10) << std::left << name
            << std::setw(5) << num
            << std::setw(10) << total << std::endl;
  
  std::cout << oss.str() << std::endl;
  
//  Data Validation
  int value {};
  std::string entry {};
  bool done {false};
  
  do {
    std::cout << "Enter an integer: ";
    std::cin >> entry;
    std::istringstream validator{entry};
    
//    fails if the value is not an integer because cant extract
    if (validator >> value)
    {
      done = true;
    }
    else
    {
      std::cout << "Sorry, thats not an integer" << std::endl;
    }
    
//    discard the input buffer
//    i.e if the user enters "12 Hello blah blah blah" it discards the rest after 12
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  } while (!done);
  
  
  return 0;
}
