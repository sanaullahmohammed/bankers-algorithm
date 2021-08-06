#include<stdio.h>

int calculateNeed(int a, int b, int max1[10][10], int alloc1[10][10]);
void isSafe(int n2,int m2, int avail2[10], int need2[10][10], int alloc2[10][10]);

int main(){
int alloc[10][10], max[10][10], avail[10];

printf("Enter the number of resources\n");
scanf("%d", &n);

printf("Enter the number of processes\n");
scanf("%d", &m);

for(int i=0; i<n; n++){
    for(int j=0; j<m; j++)
    scanf("%d", alloc[i][j]);
}

for(int i=0; i<n; n++){
    for(int j=0; j<m; j++)
    scanf("%d", max[i][j]);
}

printf("Enter the available number of resources\n");        
for(int i=0; i<n; n++){
    scanf("%d", avail[i]);
}

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
    for (int i = 0;i < a; i++) { 
        for (int j = 0;j < b; j++) { 
          arr[i][j] = max1[i][j] - alloc1[i][j]; 
        } 
    }  
    return (arr[a][b]);         
}

void isSafe(int n2,int m2, int avail2[10], int need2[10][10], int alloc2[10][10]) {
    int count = 0;
    int safeSequence[10];
    int finish[10] ;
    
    for (int i = 0;i < n2; i++) 
    { 
      finish[i] = 0;
    } 
    int work[10] ;
    for (int i = 0;i < m2; i++) 
    { 
         work[i] = avail2[i]; 
    } 

    while (count < n2) 
    { 
        int flag = 0;
        
        for (int i = 0;i < n2; i++) 
        { 
            if (finish[i] == 0)
             { 
                int j; 
                for (j = 0; j < m2; j++) 
                {         
                    if (need2[i][j] <= work[j])
                    break; 
                }
                if (j == m2) 
                { 
                    safeSequence[count++] = i; 
                    finish[i] = 1;
                    flag = 1;
                    for (j = 0; j < m2; j++) 
                    { 
                    work[j] = work[j] + alloc2[i][j]; 
                    } 
                } 
            } 
        } 
    }
