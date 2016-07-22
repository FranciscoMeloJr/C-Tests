// This is a testing program
#include <iostream>
 
using namespace std;

//calculate:
int* calculateArrayP(int i,int size)
{
  //cout << "calculate " << i;
  int* ans = new int[4];
  
  ans[0] = i;
  for(int i=1;i <size;i++){
    ans[i]= ans[i-1]*i;
  }
  /* Similar code for size = 4:
  ans[0] = i;
  ans[1] = i*i;
  ans[2] = i*i*i;
  ans[3] = i*i*i*i;*/
  //cout << "a[0] " << ans[0];
   
  return ans;

}
//main:
int main()
{
  cout << "test" <<endl;
  double *p;
  double number = 12;
  p = &number;
  cout << (*p);
  
  cout << "test 2" <<endl;
  
  int* x = calculateArrayP(2,4);
  int* y = calculateArrayP(3,4);
 
  cout << *x << endl;
  x++;
  cout << *x << endl;
 
  int** b = new int*[2]; //the quantity of arrays I want to use
 
  b[0] = x; //first array
  b[1] = y; //second array

  cout << b[0][0] << endl; //this returns 4, because we walked with the pointer
  cout << b[0][1] << endl; //therefore, this return 8
  
  cout << b[1][0] << endl; //this returns 3
  cout << b[1][1] << endl; //therefore, this return 9

  
  cout << "test 3" <<endl;
  int size, cols;

  cout << "enter the quantity of arrays" << endl;
  cin >> size;
  
  cout << "enter the size of each array:"<< endl;
  cin >> cols;

  //int size = 10;
  //int col = 4;
  int** pToArray = new int* [size];
  for(int i = 0; i< size; i++) {
     int* temp = calculateArrayP(i,cols);
     pToArray[i] = temp;
  }

  for(int i=0;i< size;i++){
    for(int j=0; j< cols;j++){
       cout << pToArray[i][j] <<"\t";
     } 
       cout <<endl;
  }

  return 0;
}
