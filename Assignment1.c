/*
* Name: Bonita Li
* Student number: 991358694
* Assignment 1
* This is a simple code that has the user enter 10 numbers. The code will then display all the numbers in a column
* and tell the user if the number is a prime number, is odd or even, and what the smallest and largest number that was entered.
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int arr[10]; 
int counter;

//checks if number is prime number and returns "yes" or "no"
const char* isPrime(int num) 
{

    int i;
    int count=0;

    //checks for prime number
    for (counter=2; counter < num/2; counter++) 
    {
        if (num % counter == 0)
        {
            count=1;
            break;
        }
        
    }

    //returns value for whether a number is a prime number or not
    if (count==1)
    {
        return "No";
    } 
    else 
    {
        return "Yes";
    }
}

//checks if number is an odd or even number and returns "odd" or "even"
const char* isOdd(int num)
{

    //checks for odd or even number
    if (num % 2 == 0) 
    {
        return "Even";
    } 
    else
    {
        return "Odd";
    }
   
}

//identifies the smallest and largest number in the inputted numbers
const char* isMinMax(int min, int max,int arr)
{
    //validates min and max number, and returns validation
    if(min == arr)
    {
        return "Min";
    } 
    if (max == arr)
    {
        return "Max";
    }

    return "";


}

//main function used for getting values from user and outputting results
int main() 
{
    int sum=0,min=arr[0],max=arr[0],check;
    double avg;
    char num[50]="string literal";
    //asks user to input 10 numbers
    for(counter = 0; counter< 10; counter++)
    {
        while(1)
        {
            check=1;
            printf("Enter a positive value %d\n", counter+1);
            scanf("%s",num);

            //validates input
            for(int i=0; i<strlen(num); i++) 
            {
                //checks for characters and symbols
                if(!isdigit(num[i])) 
                {
                    printf("Entered value is not a positive integer\n");
                    check=0;
                    break;
                }
            }
                if(check == 1) 
                {
                    arr[counter] = atoi(num);
                    break;
                } 
        }
        
        if (min==0) 
        {
            min=arr[counter];
        }
        //checks for smallest number
        if(arr[counter]<min)
        {
            min=arr[counter];
            
        }

        //checks for largest number
        if (arr[counter]>max)
        {
            max=arr[counter];
        }
    }

    //prints out array of numbers, whethery they are a prime number, odd/even number, and min/max
    printf("\n%3s %10s %10s %11s %12s\n","Sr.","Number","Prime","Odd/Even","Min/Max");
    for ( int index=0; index<10; index++)
    {
        printf("%3d %10d %10s %11s %12s\n", index+1, arr[index], isPrime(arr[index]), isOdd(arr[index]),isMinMax(min,max,arr[index]));
        sum=sum + arr[index];
    } 

    //calculates average of inputted numbers
    avg=(double)sum/10;
    printf("\n\n%-3s %10d\n%-3s %10.1f\n","Sum",sum,"Avg",avg);
}