#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void bubbleSort(int arr[],int n){
 for (int i = 0; i < n - 1; i++)
 for (int j = 0; j < n - i - 1; j++)
 if (arr[j] > arr[j + 1]){
 int temp = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = temp;
 }
 printf("\nSorted array by Bubble sort in child process = ");
 for(int i = 0;i<n;i++){
 printf("%d ",arr[i]);
 }
 printf("\n");
}
 else{
 wait(NULL);
 printf("\n\n\n****** Parent PROCESS ********\n");
 printf("\nIt is parent process with pid = %d and ppid = %d \n",getpid(),getppid());
 selectionSort(arr,n);
 printf("\n ***** PARENT PROCESS TERMINATED *****");
 }
}

