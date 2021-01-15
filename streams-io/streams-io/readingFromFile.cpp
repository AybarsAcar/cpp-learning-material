//
//  readingFromFile.cpp
//  streams-io
//
//  Created by Aybars Acar on 13/1/21.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

void readFromFile(std::string fileName)
{
  std::ifstream inFile;
  std::string line;
//  int num;
//  double total;

  inFile.open(fileName);      // creates a stream
  
  if (!inFile.is_open())
  {
    std::cerr << "Problem Openning hte file" << std::endl;
    return;
  }
  
//  reads line up to the first white space
  /*inFile >> line >> num >> total;
  
  std::cout << line << std::endl;
  std::cout << num << std::endl;
  std::cout << total << std::endl;*/
  
//  read all the lines
 /* while (!inFile.eof())
  {
    inFile >> line >> num >> total;
    
    std::cout << line << num << total << std::endl;
  } */
  
  /*while (inFile >> line >> num >> total)
   {
     std::cout << line << num << total << std::endl;
   }*/
  
//  read 1 line at a time
//  while (std::getline(inFile, line))
//  {
//    std::cout << line << std::endl;
//  }
  
//  reading unformatted input -> 1 char at a time
//  we dont have to worry about end line, fancy characters etc
  char c;
  while (inFile.get(c))
  {
    std::cout << c;
  }
  
//  make sure to close the file before exiting
  inFile.close();
}
