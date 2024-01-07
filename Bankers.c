#include<stdio.h>
int required[100],allocate[100],need[100];

void main()
{
    int n;
    int max=12,allocateCount=0;

    printf("Enter the number of processes:\n");
    scanf("%d",&n);

    printf("Enter the required resource for each process: \n");
    for(int i=0; i<n; i++)
    {
        printf("Requirement for Process %d:",i+1);
        scanf("%d",&required[i]);
    }

     printf("\nEnter the Allocated resource for each process: \n");
     for(int i=0; i<n; i++)
    {
        printf("Allocated for process %d:",i+1);
        scanf("%d",&allocate[i]);
        allocateCount+=allocate[i];
