//Solution using two matrix multiplication:

#include <iostream>
using namespace std;

void convolution(int N[][WIDTH2], int M[][MASK_WIDTH2], int P[][WIDTH2]);
void read_m(M[1024][1024]);

#define H 1024;
#define W 1024;
#define W2 1024;

int main()
{   
    int A[H][W];
    int B[W][W2];
    int C[H][W2];
   
    read_m(A);
    read_m(B);
    
    mult(A,B,C);
    
    return 0;
}

//Function to read matrix:
void read{
	ifstream f("matrix.txt");
	f >> m >> n;
	
	if ((m != 4) || (n != 3))
	  {
	  cout << "Matrix not 4 by 3!n";
	  return 1;
	  }
	
	for (int i = 0; i < m; i++)
	for (int j = 0; j < m; j++)
	  f >> A[i][j];
}

void mult(A[H][W],B[W][W2],C[H][W2]){
  // C = Ai,j,*Bj,k
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
            	//Possible optimization is the  
                mult[i][j] += a[i][k] * b[k][j];
            }
}

//Function based from [1].
//[1] https://stackoverflow.com/questions/41452226/c-2d-convolution

void convolution(int N[][WIDTH2], int M[][MASK_WIDTH2], int P[][WIDTH2]) {
//N[WIDTH1][WIDTH2] is the input matrix
//M[MASK_WIDTH1][MASK_WIDTH2] is the kernel matrix
//P[][] the output matrix.

// find center position of kernel (half of kernel size)
int kCenterX = MASK_WIDTH2 / 2;
int kCenterY = MASK_WIDTH1 / 2;

for (int i = 0; i < WIDTH1; ++i)              // rows
{
    for (int j = 0; j < WIDTH2; ++j)          // columns
    {
        for (int m = 0; m < MASK_WIDTH1; ++m)     // kernel rows
        {
            int mm = MASK_WIDTH1 - 1 - m;      // row index

            for (int n = 0; n < MASK_WIDTH2; ++n) // kernel columns
            {
                int nn = MASK_WIDTH2 - 1 - n;  // column index

                // index of input signal, used for checking boundary
                int ii = i + (m - kCenterY);
                int jj = j + (n - kCenterX);

                // ignore input samples which are out of bound
                if (ii >= 0 && ii < WIDTH1 && jj >= 0 && jj < WIDTH2)
                   P[i][j] += N[ii][jj] * M[m][n];
            }
        }
    }
}

//Possible Optimization ways:
//https://attractivechaos.wordpress.com/2016/08/28/optimizing-matrix-multiplication/
//#include <Eigen/Dense> --> uses openmp has one of the best performance
