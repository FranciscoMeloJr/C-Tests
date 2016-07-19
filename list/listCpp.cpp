#include <list>
#include <iostream>
//Based on the examples of
//http://www.cppsamples.com/common-tasks/return-multiple-values.html

using namaspace std;

int main()
{

  std::list<int> int_list;
  int_list.push_back(1);
  int_list.push_back(1);
  int_list.push_back(8);
  int_list.push_back(9);
  int_list.push_back(7);
  int_list.push_back(8);
  int_list.push_back(2);
  int_list.push_back(3);
  int_list.push_back(3);
  int_list.sort();
  int_list.unique();

  for(std::list<int>::iterator list_iter = int_list.begin(); 
     list_iter != int_list.end(); list_iter++)
  {
    std::cout<<*list_iter<<endl;
  }
  return 0;
}
