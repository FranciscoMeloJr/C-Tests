#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
 
//Using as reference:
//http://www.cplusplus.com/reference/cstdlib/rand/

using namespace std;

int main()
{
    int size = 10;
    vector<int> v (size);
   
    srand(time(NULL));
   
    for(int i = 0; i < size ; i++)
    {
      v[i] = rand() % 10 +1;
      cout <<v[i] << endl;
    }
   
   return 0;
  
}
