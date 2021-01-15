//
//  stacksAndQueues.cpp
//  stl-proj
//
//  Created by Aybars Acar on 14/1/21.
//

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <stack>
#include <queue>

template<typename T>
void displayStack(std::stack<T> s)
{
  std::cout << "[ ";
  
  while (!s.empty())
  {
    T elem = s.top();
    s.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

template<typename T>
void displayQueue(std::queue<T> q)
{
  std::cout << "[ ";
  
  while (!q.empty())
  {
    T elem = q.front();
    q.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

template<typename T>
void displayPQ(std::priority_queue<T> pq)
{
  std::cout << "[ ";
  
  while (!pq.empty())
  {
    T elem = pq.top();
    pq.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void stacksAndQueuesExe()
{
  std::stack<int> s1; // uses deque as the backing structure

  std::stack<int, std::list<int>> s2; // or we can specify what data structure we want to back it with
  
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  
  s1.top() = 100;
  
  displayStack(s1);
  
  while (!s1.empty())
  {
    s1.pop();
    displayStack(s1);
  }
  
  std::queue<int> q1;
  
  q1.push(1);
  q1.push(2);
  q1.push(3);
  q1.push(4);
  q1.push(5);
  
  q1.front() = 200;
  q1.back() = 500;
  
  displayQueue(q1);
  
  while (!q1.empty())
  {
    q1.pop();
    displayQueue(q1);
  }
  
  std::priority_queue<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(10);
  pq.push(-2);
  pq.push(100);
  
  displayPQ(pq);
}
