/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
	/** AND HERE WE TRY FOR TRICKY MATH WITH THE GOAL OF CALCULATING A SYMMETRIC BLOCK SIZE**/
	rowTest = M - (M % 2); //gives even num rows if not already
	colTest = N - (N % 2); //gives even num columns if not already
	test = rowTest / colTest; //checks if they are now equal
	if(test == 1){
		//the block is a square
		//blockSize = colTest; //rows and columns are now same number
	}
	else(test != 1){
		//the block has to be a rectangle with dimensions rowTest and colTest
		//TODO: IMPLEMENT THESE DIMENSIONS SEPARATELY!!!
	}


	int i, j, k, savedVal, diagLoc, diag, blockSize, rowTest, colTest = 0; //CURRENT LOCAL VARIABLE COUNT: 9 (can't go above 12)
	//i is row, j is column

	if(M == N){

	}
	else if(M != N){

	}
/**	//CANNOT ASSUME M AND N ARE THE SAME
	for(i = 0; i < M; i+=blockSize){
	//rows for loop
		for(j = 0; j < N; j+=blockSize){
		//columns for loop
			for(k = 0; k < N; k+=blockSize){ **/
				/* blockSize x blockSize mini matrix transposes */
/**				if(i != j){
					B[i][j] = A[i][j];
				}
				else{
					//it's along the diagonal
					savedVal = A[i][j];
					diagLoc = i;
					diag = 1;
				}

			}
			if(diag == 1){
				B[diagLoc][diagLoc] = savedVal;
				diag = 0;
			}

		}
	}**/
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

