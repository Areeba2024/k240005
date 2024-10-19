//NAME:AREEBA IMRAN
//ID : 24K-0005
//QUESTION 1
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int len,temp,i;
	printf("Enter the length of the array: ");
	scanf("%d",&len);
	int arr[len]; //array to store the user input
	printf("Input %d elements in the array(value must be <9999) \n",len);
	for(i=0;i<len;i++) //loop to store the user input at each array index
	{
		printf("element-%d: ",i);
		scanf("%d",&arr[i]);
	}
	bool flag = true;
	while(flag==true)
	{
		flag = false; //sets the flag for the each round 
		for(i=0;i<len-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp = arr[i];
				arr[i]=arr[i+1];
				arr[i+1]= temp;
				flag = true;
			}
		}
	}
	if(len >= 2) 
	{
	    printf("The Second smallest element in the array is: %d",arr[1]);
	}
	else
	{
	    printf("Doesn't have enough elements");
	}
}
