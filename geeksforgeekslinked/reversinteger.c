
#include<stdio.h>


int reverse(int x){
    int count =0 ; 
    int num = x ; 
    int sum =0 ; 
    while(num!=0 ){
        count ++; 
        num= num%10 ; 
    }
    num = x ; 
int arr[count]; 
for(int i =count-1 ; i!=0 ;i--){
  arr[i] =num%10 ; 
}
for(int i =0 ; i<count ;i++){
    printf("%d ",arr[i]); 
}


num =1; 
for(int i =0 ; i<count ; i++){
    sum = sum+ arr[i]*num ; 
    num *=10 ; 
}
return num ; 
}




int main (void){
    int x = 123 ; 
    x = reverse(x) ; 
    printf("the reversed integer is : %d",x); 
}