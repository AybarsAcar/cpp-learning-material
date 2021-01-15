//
//  main.cpp
//  stl-proj
//
//  Created by Aybars Acar on 13/1/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <array>

#include "Item.h"

#define MAX(a, b) ((a > b) ? a : b)

void vectorProjExe();
void dequeProjExe();
void listProjExe();
void setProjExe();
void mapProjExe();
void stacksAndQueuesExe();

template<typename T, size_t N>
void displayArray(const std::array<T, N> &arr);


struct DataPoint
{
  double x, y, z;
  
//  need to implement the following to pass to min max functions
  bool operator<(const DataPoint &rhs) const
  {
    return this->x < rhs.x;
  }
  bool operator>(const DataPoint &rhs) const
  {
    return this->x > rhs.x;
  }
  
  bool operator==(const DataPoint &rhs) const
  {
    return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
  }
};

//to print out the DataPoint
std::ostream &operator<<(std::ostream &out, const DataPoint &p)
{
  out << "x: " << p.x << ", y: " << p.y << ", z: " << p.z;
  return out;
}

/**
 * generic function
 */
template <typename T>
T max(T a, T b)
{
  return (a > b) ? a : b;
}

template <typename T>
T min(T a, T b)
{
  return (a < b) ? a : b;
}

int main(int argc, const char * argv[])
{
  std::vector<int> myVector {20, 39, 9, 29, 20, -1};
  std::sort(myVector.begin(), myVector.end());
  
  for (auto elem : myVector)
  {
    std::cout << elem << std::endl;
  }
  
  int sum {};
  sum = std::accumulate(myVector.begin(), myVector.end(), 0);
  
  std::cout << "Sum of my vector: " << sum << std::endl;
  
  std::cout << MAX(1, 29) << std::endl;
  std::cout << max(10, 20) << std::endl;
  std::cout << max<int>(10, 20) << std::endl;
  std::cout << max('a', 'A') << std::endl;
  std::cout << min("hello", "world") << std::endl;
  std::cout << min(DataPoint {1,2,3}, DataPoint {2,3,4}) << std::endl;
  
  Item<std::string> *me = new Item<std::string>("Aybars", "Champion");
  Item<int> item {"Age", 28};
  
  std::cout << me->getValue() << std::endl;
  std::cout << item.getValue() << std::endl;
  
  delete me;
  
  std::vector<Item<int>> itemVector {item};
  itemVector.push_back(Item<int> {"Age2", 23});
  
  for (auto elem : itemVector)
  {
    std::cout << elem.getName() << std::endl;
    std::cout << elem.getValue() << std::endl;
  }
  
//  initialising and looping over the vector // we can auto it as well
  std::vector<Item<int>>::iterator it = itemVector.begin();
  

  while (it != itemVector.end())
  {
    std::cout << "Iterator: " << *it << std::endl;
    it++;
  }

  std::vector<int> integerVector {1, 3, 45, 6, 2, 53, 2, 6, 223};
  auto loc = std::find(integerVector.begin(), integerVector.end(), 53);
  
  if (loc != integerVector.end())
  {
    std::cout << "Location: " << &loc << ", Value: " << *loc << std::endl;
  }
  else
  {
    std::cout << "Not found" << std::endl;
  }
  
  std::for_each(integerVector.begin(), integerVector.end(), [] (int x)
  {
    std::cout << x * x << std::endl;
  });
  
  auto count = std::count(integerVector.begin(), integerVector.end(), 2);
  std::cout << "2 appears: " << count << " times" << std::endl;
  
//  returns the number of even numbers
  auto evenCount = std::count_if(integerVector.begin(), integerVector.end(), [] (int x)
  {
    return x % 2 == 0;
  });

  std::cout << "Number of even elements: " << evenCount << std::endl;
  
  auto gte5 = std::count_if(integerVector.begin(), integerVector.end(), [] (int x)
  {
    return x >= 5;
  });
  std::cout << "Number of even elements greater than or equal to 5: " << gte5 << std::endl;

//  replaces 1 with 100
  std::replace(integerVector.begin(), integerVector.end(), 1, 100);
  for (auto elem : integerVector)
  {
    std::cout << elem << ", ";
  }
  std::cout << std::endl;
  
  std::string s1 {"Hello, World!"};
  std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  std::cout << s1 << std::endl;
  
  
  std::array<int, 10 > arr1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  int *underlyingArray = arr1.data();
  
  std::cout << "Memory Address: " << underlyingArray << std::endl;
  
  std::cout << "Size of the array: " << arr1.size() << std::endl;
  std::cout << "arr1.at(0): " << arr1.at(0) << " == " << "arr1[0]: " << arr1[0] << std::endl;
  
  displayArray(arr1);

  std::array<double, 10> arr2;
  for (int i{0}; i < arr1.size(); i++)
  {
    arr2[i] = std::sqrt(arr1[i]);
  }
  displayArray(arr2);
  
  std::cout << "Max elem: " << *(std::max_element(arr1.begin(), arr1.end())) << std::endl;
  
  arr1.fill(0);
  displayArray(arr1);
  
  int sumArr2 = std::accumulate(arr2.begin(), arr2.end(), 0);
  std::cout << "Sum of arr2: " << sumArr2 << std::endl;
  
  vectorProjExe();
  
  dequeProjExe();
  
  listProjExe();
  
  setProjExe();
  
  mapProjExe();
  
  stacksAndQueuesExe();
  
  return 0;
}


template<typename T, size_t N>
void displayArray(const std::array<T, N> &arr)
{
  std::cout << "[ ";
  for (auto elem : arr)
  {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}
