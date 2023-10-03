#include <stdio.h>

int main()
{
    int A[12][5][10];                     // Define the 3D array
    int baseAddress = 20000;              // Base address of the array
    int i = 6;                            // Row index
    int j = 3;                            // Column index in the second dimension
    int k = 5;                            // Column index in the third dimension
    int jmax = 5;                         // Size of the second dimension
    int kmax = 10;                        // Size of the third dimension
    int elementSize = sizeof(A[0][0][0]); // Size of each element in bytes (assuming it's an integer)

    // Calculate the address using the formula
    int address = baseAddress + ((i * (jmax * kmax) + j * kmax + k) * elementSize);

    // Print the calculated address
    printf("Address of A[%d][%d][%d] = %d\n", i, j, k, address);

    return 0;
}
