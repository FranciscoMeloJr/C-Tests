//https://en.wikipedia.org/wiki/C%2B%2B_Technical_Report_1 
//
#include <iostream>
#include <tr1/functional>

void f( int &r )  { ++r; }

template< class Funct, class Arg >
void g( Funct f, Arg t )
{
  f(t);
}

int main()
{
  int i = 0;

  g( f, i );                   // 'g< void(int &r), int >' is instantiated
  std::cout << i << "\n";      // Output: 0

  g( f, std::tr1::ref(i) );    // 'g< void(int &r), reference_wrapper<int> >' is instanced
  std::cout << i << "\n";      // Output: 1
}
