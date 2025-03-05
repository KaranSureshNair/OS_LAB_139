
#include<stdio.h>

void main(){
int n,pos;
printf("Enter the size of the array:\n");
scanf("%d", &n);

printf("Enter the Array Elements here: \n");
int arr[n];
for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
}

printf("Enter the position to delete :\n");
scanf("%d", &pos);

printf("The array is: \n");
for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
}
printf("\n");

for(int i=0; i<n-1; i++){
    if(pos==i){
        for(int j=i; j<n; j++) arr[j] = arr[j+1];
    }
}

n=n-1;


printf("Array after deletion is:\n");
for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
}

}

