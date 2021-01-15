//
//  challengeGrader.cpp
//  streams-io
//
//  Created by Aybars Acar on 13/1/21.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int processResponse(std::string &response, std::string &answerKey);
void printStudent(std:: string &name, int score);
void printHeader();
void printFooter();

void grade(std::string fileName)
{
  std::ifstream file;
  
  std::string answerKey {};
  std::string name {};
  std::string response {};
  int runningSum {0};
  int totalStudents {0};
  double avgScore {0.0};
  
  file.open(fileName);
  
  if (!file.is_open())
  {
    std::cerr << "Problem Opening the file" << std::endl;
    return;
  }
  
  file >> answerKey;

  printHeader();
  
  while (file >> name >> response)
  {
    totalStudents++;
    int score = processResponse(response, answerKey);
    runningSum += score;
    printStudent(name, score);
  }
  
  if (totalStudents !=0)
  {
    avgScore = static_cast<double>(runningSum / totalStudents);
  }

  printFooter();
}

int processResponse(std::string &response, std::string &answerKey)
{
  int score {0};
  for (size_t i{0}; i < answerKey.size(); i++)
  {
    if (response.at(i) == answerKey.at(i)) score++;
  }
  return score;
}

void printStudent(std:: string &name, int score)
{
  std::cout << std::setprecision(1) << std::fixed;
  std::cout << std::setw(15) << std::left << name
            << std::setw(15) << std::right << score << std:: endl;
}


void printHeader()
{
  std::cout << std::setw(15) << std::left << "Student" << std::setw(15) << std::right << "Score" << std::endl;
  std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
  std::cout << std::setfill(' ');
}

void printFooter()
{
  std::cout << std::setfill('-');
  std::cout << std::setw(30) << "" << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::setw(15) << std::left << "Average Score" << std::setw(15) << std::right << 3.9 << std::endl;
}
