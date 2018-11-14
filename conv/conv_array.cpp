//Solution using two matrix multiplication:

#include <iostream>
using namespace std;

void convolution(int N[][WIDTH2], int M[][MASK_WIDTH2], int P[][WIDTH2]);

int main()
{
    int H = 1024;
    int W = 1024;

    int A[H][W];
    int B[H][W];
    int C[H][W];
   
    read_a(A);
    read_b(B);
    
    convolutional(A,B,C);
    
    return 0;
}

void convolution(int N[][WIDTH2], int M[][MASK_WIDTH2], int P[][WIDTH2]) {
//N[WIDTH1][WIDTH2] is the input matrix, M[MASK_WIDTH1][MASK_WIDTH2] is the kernel matrix, P[][] the output matrix.

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

