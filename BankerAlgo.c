/*  Step 1
        work and finish are vectors of lenght m and n respectively. Initialize
        work = available and finish[i] = false for i = 0,1,....,n-1 
    Step 2
        Find an i such that
        a. finish[i] == false
        b. need[i] <= work[i]
        If no such i exists, go to step 4.
    Step 3
        work = work + allocation[i]
        finish[i] = true
        go to step 2
    Step 4 
        If finish[i] == true for alli. then system is in safe state
*/

#include<stdio.h>

int calculateNeed(int a, int b, int max1[10][10], int alloc1[10][10]);
void isSafe(int n2,int m2, int avail2[10], int need2[10][10], int alloc2[10][10]);

int main(){
int alloc[10][10], max[10][10], avail[10];
int n, m;       // n = no. of resources  m = no. of processes 

printf("Enter the number of resources\n");
scanf("%d", &n);

printf("Enter the number of processes\n");
scanf("%d", &m);

// Allocation Matrix
printf("Enter the allocation matrix\n");        // n x m matrix
for(int i=0; i<n; n++){
    for(int j=0; j<m; j++)
    scanf("%d", alloc[i][j]);
    }

// Max. Matrix
printf("Enter the max matrix\n");        // n x m matrix
for(int i=0; i<n; n++){
    for(int j=0; j<m; j++)
    scanf("%d", max[i][j]);
    }

// Available resources
printf("Enter the available number of resources\n");        
for(int i=0; i<n; n++){
    scanf("%d", avail[i]);
    }
/* available resources can also be calculated through allocation matrix and total number of resources(if provided). 
    1. find the sum of each column in allocation matrix and get a 1-D array (say A[])
    2. total resources is a 1-D array (say B[])
    3. let available be C[]; C[] = B[] - A[]
    */
printf("Need matrix is:");
 int need[10][10] ;
need[10][10] = calculateNeed(n, m, max, alloc );
  for (int i = 0;i < n; i++) 
    { 
        for (int j = 0;j < m; j++) 
         { 
        printf("%d" , need[i][j]); 
         } 
    }   

  isSafe(n, m, avail,  need,  alloc );
}

int calculateNeed(int a, int b, int max1[10][10], int alloc1[10][10]) { 
    int arr[10][10];
    for (int i = 0;i < a; i++) 
    { 
        for (int j = 0;j < b; j++) 
         { 
        arr[i][j] = max1[i][j] - alloc1[i][j]; 
         } 
    }  
   return (arr[a][b]);
          
} 

void isSafe(int n2,int m2, int avail2[10], int need2[10][10], int alloc2[10][10]) {
    int count = 0;
    int safeSequence[10]; 

    /*  Step 1
        work and finish are vectors of lenght m and n respectively. Initialize
        work = available and finish[i] = false for i = 0,1,....,n-1 
    */
    int finish[10] ;
    //finish array to find the already allocated process 
    for (int i = 0;i < n2; i++) 
    { 
      finish[i] = 0;  // iitialising to false
    } 

    //work array to store the copy of available resources
    int work[10] ;
    for (int i = 0;i < m2; i++) 
    { 
         work[i] = avail2[i]; 
    } 

     while (count < n2) 
    { 
        int flag = 0;   // false
        /* Step 2
            Find an i such that
            a. finish[i] == false
            b. need[i] <= work[i]
            If no such i exists, go to step 4.
        */
        for (int i = 0;i < n2; i++) 
        { 
            if (finish[i] == 0)             // part a
             { 
                int j; 
                for (j = 0; j < m2; j++) 
                {         
                    if (need2[i][j] <= work[j])  // part b
                    break; 
                } 

                /* Step 3
                    work = work + allocation[i]
                    finish[i] = true
                    go to step 2
                */
                if (j == m2) 
                { 
                    safeSequence[count++] = i; 
                    finish[i] = 1;   // marking as true
                    flag = 1;        // marking true
                          
                    for (j = 0; j < m2; j++) 
                    { 
                    work[j] = work[j] + alloc2[i][j]; 
                    } 
                } 
            } 
        } 
    }

/* Step 4 
    If finish[i] == true for all i, then system is in safe state
*/
    if (count < n2) 
    { 
        printf("The System is UnSafe!\n"); 
    } 
    else
    { 
        //printf("The given System is Safe"); 
        printf("Following is the SAFE Sequence\n"); 
                for (int i = 0;i < n2; i++) 
        { 
            printf("P" + safeSequence[i]); 
            if (i != n2-1) 
            printf(" -> "); 
        } 
    } 
} 
