//
//  copyFile.cpp
//  streams-io
//
//  Created by Aybars Acar on 13/1/21.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

/**
 * copies one file into another
 */
void copyFile(std::string inFileName, std::string outFileName)
{
  std::fstream inFile;
  std::ofstream outFile;
  
  inFile.open(inFileName);
  outFile.open(outFileName);
  
  if (!inFile.is_open() || !outFile.is_open())
  {
    std::cerr << "Problem Opening the files" << std::endl;
    return;
  }
  
  char c;
  while (inFile.get(c))
  {
    outFile.put(c);
  }
  
  inFile.close();
  outFile.close();
}

void writeToFile()
{
  std::ofstream outFile {"output.txt", std::ios::app};
  
  if (!outFile)
  {
    std::cerr << "Error Creatong the file" << std::endl;
    return;
  }
  
  std::string line;
  std::cout << "Enter something to write to file: ";
  std::getline(std::cin, line);
  
  outFile << line << std::endl;
  
  outFile.close();
}
