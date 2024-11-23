/*
//6. Write a C program that finds the maximum element in a given m x n matrix and its position (row,column).
#include<stdio.h>
int main()
{
	int row,col,max,i,j,pos_row,pos_col;
	
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	printf("Enter the number of column: ");
	scanf("%d",&col);
	int matrix[row][col];
	max = matrix[0][0];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Enter the element in %d row and %d column: ",i+1,j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		
			printf("%d|",matrix[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(matrix[i][j] > max)
			{
				max = matrix[i][j];
				pos_row = i+1;
				pos_col = j+1;
			}
			else
			{
				pos_row = 1;
				pos_col = 1;
			}
		}
	}
	printf("The max element is %d at position %d,%d",max,pos_row,pos_col);
}
*/

/*
//7. Write a C program to multiply two matrices of size 3x3 and display the result matrix.
#include<stdio.h>
int main()
{
	int i,j;
	int matrix_A[3][3];
	int matrix_B[3][3];
	int result_matrix[3][3];
	printf("MATRIX 1");
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter the element in %d row and %d column: ",i+1,j+1);
			scanf("%d",&matrix_A[i][j]);
		}
	}

	printf("MATRIX 2");
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter the element in %d row and %d column: ",i+1,j+1);
			scanf("%d",&matrix_B[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			result_matrix[i][j] = matrix_A[i][j] * matrix_B[j][i];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d|",result_matrix[i][j] );
		}
		printf("\n");
	}
		
}
*/
/*
//5. Write a C program to find the saddle point(s) in a given 3x3 matrix. A saddle point is an element that is the smallest in its row and the largest in its column.
#include<stdio.h>
int main()
{
	int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
		}
	}
}
*/
/*
//8. Write a C program to generate a diamond shape pattern using nested loops. The program should take the number of rows for the upper half of the diamond as input from the user.
#include<stdio.h>
int main()
{
	int i,j,k,row;
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	//upper triangle
	for(i=1;i<=row;i++)
    {
	k=1;
	for(j=1;j<=(2*row-1);j++)
	{
		if (j>=row+1-i && j<=row-1+i && k)
		{
			printf("*");
			k=0;
		}
		else
		{
			printf(" ");
			k=1;
		}
	}
	printf("\n");
    }
    //lower triangle
    for(i=row-1;i>=1;i--)
    {
	k=1;
	for(j=(2*row-1);j>=1;j--)
	{
		if (j>=row+1-i && j<=row-1+i && k)
		{
			printf("*");
			k=0;
		}
		else
		{
			printf(" ");
			k=1;
		}
	}
	printf("\n");
    }
}
*/
/*
//3. Generate a pattern of odd numbers in decreasing order starting from a user-specified number using nested loops.
#include<stdio.h>
int main() {
    int max, i, j;
    printf("Enter the max odd number: ");
    scanf("%d", &max);

    for(i = max; i >= 1; i -= 2) 
	{
        
        for(j = max; j >= i; j -= 2) 
		{
            printf("%d ", j);
        }
        printf("\n");  
    }


}
*/

//5. Write a C program to find the saddle point(s) in a given 3x3 matrix. A saddle point is an element that is the smallest in its row and the largest in its column.
#include<stdio.h>
int main() {
    int matrix[3][3];
    int i, j, k;
    int saddle_point = 0;
    int min = matrix[i][0];  
    int index = 0;  
    for(i = 0; i < 3; i++) 
	{
        for(j = 0; j < 3; j++) 
		{
			printf("Enter the element in %d row and %d column: ",i+1,j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d|",matrix[i][j] );
		}
		printf("\n");
	}
		
	printf("\n");
    for(i = 0; i < 3; i++) 
	{
        int min = matrix[i][0];  
        int index = 0;  

        for(j = 1; j < 3; j++) 
		{
            if(matrix[i][j] < min) 
			{
                min = matrix[i][j];
                index = j;
            }
        }
    

        int Saddle = 1;
        for(k = 0; k < 3; k++) 
		{
            if(matrix[k][index] > min) 
			{
                Saddle = 0;  
                break;
            }
        }

        
        if(Saddle) 
		{
            printf("Saddle point at (%d, %d) = %d \n", i + 1, index + 1, min);
            saddle_point = 1;
        }
    }
        if(!saddle_point)
		{
			printf("No saddle point");
		}


}
