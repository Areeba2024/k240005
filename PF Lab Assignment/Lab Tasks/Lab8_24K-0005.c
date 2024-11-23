
//1. Write a C program that takes a square matrix as input and prints its diagonal elements.

#include<stdio.h>
int main()
{
int i,j;
int a[3][3];
for (i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("Enter the elements in row %d and column %d: ",i+1,j+1);
scanf("%d",&a[i][j]);
}
}
printf("The diagonal elements are: \n");
for (i=0;i<3;i++)
{
   for(j=0;j<3;j++)
{
            if(i==j)
            {
                printf(" %d| ",a[i][j]);

            }

}

}
}//end main

//2. Write a C program that generates a sequence of prime numbers within a given range using
nested loops.

#include<stdio.h>
#include<stdbool.h>
int main()
{
	int start,end,i,j,index=0;
	bool flag = false;
	printf("Enter the starting point: ");
	scanf("%d",&start);
	printf("Enter the ending point: ");
	scanf("%d",&end);
	int prime[end-start+1];
	for(i=start;i<=end;i++)
	{
		flag = false;
		for(j=2;j<=i/2;j++)
		{
			
			if (i % j == 0)
			{
				flag = true;
				break;
			}
		}
		if(flag== false )
		{
			prime[index] = i;
			index++;
		}
	}
	printf("The prime between %d and %d are: ",start,end);
	for(i=0;i<index;i++){
		
		printf("%d ",prime[i]);
	}
}//end main


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
}//end main


//4. Implement a C program to find the transpose of a given m x n matrix. Print the transposed matrix.

#include<stdio.h>
int main()
{
	int row,col,i,j;
	printf("Enter the number of rows of a matrix: ");
	scanf("%d",&row);
	printf("Enter the number of columns of a matrix: ");
	scanf("%d",&col);
	int matrix[row][col];
	int trans[col][row];
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
			trans[j][i] = matrix[i][j];
		}
	}
	printf("\nThe transposed matrix is \n");
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d|",trans[i][j]);
		}
		printf("\n");
	}	
}//end main

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
}//end main


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
}//end main


//7. Write a C program to multiply two matrices of size 3x3 and display the result matrix.

#include<stdio.h>
int main()
{
	int i,j,k,sum=0;
	
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
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d|",matrix_A[i][j] );
		}
		printf("\n");
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
			printf("%d|",matrix_B[i][j] );
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		    sum = 0;
		    for(k=0;k<3;k++)
		    {
		        sum = sum + matrix_A[i][k] * matrix_B[k][j];
		    }
			
			result_matrix[i][j] = sum;
			
		}
	
	}
	printf("RESULT MATRIX \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d|",result_matrix[i][j] );
		}
		printf("\n");
	}
		
}//end main

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
}//end main
