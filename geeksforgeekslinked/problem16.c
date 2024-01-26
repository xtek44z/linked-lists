#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct node {
    int data ; 
    struct node*link ; 
}node ; 

void create_list(node*head ,int num ) {
node*current ; 
printf("Enter the data of the node 1 : ") ; 
scanf("%d",&(head ->data)) ; 
for(int i =0 ; i<num-1 ; i++){
current = malloc (sizeof(node)) ; 
printf("Enter the data of the node %d : ",i+2) ; 
scanf("%d",&(current ->data)) ; 
current -> link = NULL ; 
head -> link  =current ; 
head = head -> link ; 
}
}

void display(node*head ) {
int count = 0 ; 
while(head !=NULL ){
    count ++ ; 
printf("The data you entered for node %d is : %d\n",count,head -> data) ;
head = head -> link ; 
}
}


int numt(node*head,int count ){
node*temp = head ; 
int result =0  ; 
while(temp !=NULL ){
result += (temp ->data)*(10^count) ; 
count -- ; 
temp = temp -> link ; 
}
printf("The result is : %d\n" ,result) ; 
return result ; 
}


void shit (node*head,int *count ){
node*temp = head ; 
while(temp!=NULL ){
*count = *count + 1 ; 
temp = temp -> link ; 
}
printf("The count is : %d\n",*count) ; 


}


int main (void){
int num, number ,  count =0  ; 
printf("How many nodes are going to be ? ") ; 
scanf("%d",&num) ; 
node *head = malloc(sizeof(node))  ;
node*temp = head ; 
head -> link = NULL ;
create_list(temp, num) ; 
temp = head ; 
display(temp); 
temp =head ;
shit(temp , &count) ; 
temp =head ; 
number =numt(head, count-1) ; 
printf("\nThe number is : %d ",number) ; 


}