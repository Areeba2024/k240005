#include <stdio.h>
void Star_Format(int num)
{
	int j,i,space;
	for(i=0;i<num;i++){
	    if(i < num-1){
            
            for (j = 0; j < 2 * (num-1) - i; j++) {
                printf(" ");
            }
            printf("*");
            if (i != 0) {
                space =( 2 * i )- 1;
                for (j = 0; j < space; j++) {
                    printf(" ");
                }
                printf("*");
            }
        }
        else {
        	for (int k = 0; k < num; k++) {
                printf("*");
            }
            space = (2 * i) - 1;
            for (int j = 0; j < space; j++) {
                printf(" ");
            }

            for (int k = 0; k < num; k++) {
                printf("*");
            }
		}
		printf("\n");
	}
}

void Star_Upper(int num) {
    int gap = 4 * num - 7;//space in between
    int i, j, k;

    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < i + 1; j++) {
            printf(" ");
        }
        printf("*");

        for (k = 0; k < gap; k++) {
            printf(" ");
        }
        gap -= 2;

        printf("*\n");
    }
}

void Star_Lower(int num) {
    int rows = 2 * num - 2;
    int i, j, k,temp = 1, spaces;

    for (i = num - 1; i < rows; i++) {
        spaces = 2 * num - 3 - i;

        for (j = 0; j < spaces; j++) {
            printf(" ");
        }

        printf("*");

        for (k = 0; k < spaces; k++) {
            printf(" ");
        }
        if (i == rows - 1) {
            printf(" ");
        } else {
            printf("*");
        }
        for (k = 0; k < temp; k++) {
            printf(" ");
        }
        temp += 4;
        if (i == rows - 1) {
            printf(" ");
        } else {
            printf("*");
        }
        for (int k = 0; k < spaces; k++) {
            printf(" ");
        }

        printf("*\n");
    }
}


int main(){
	int num;
	printf("Enter an odd Number: ");
	scanf("%d",&num);
    if(num % 2 == 1)
    {
    Star_Format(num);
	  Star_Upper(num);
	  Star_Lower(num);
    }
  	else 
    {
    printf("Invalid try again!");
    }
	return 0;
}
