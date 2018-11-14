//Solution using two matrix multiplication:

#include <iostream>
using namespace std;

void convolution(int N[][WIDTH2], int M[][MASK_WIDTH2], int P[][WIDTH2]);

int main()
{
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    while (c1!=r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }

    // Storing elements of first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }

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

