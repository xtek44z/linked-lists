#include<stdio.h>
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


void find(node*head,int target){
    node*temp  = head ; 
    for(int i =0 ; i<target-1 ; i++){
        temp = temp -> link ; 
    }
   printf("\nThe data is : %d ",temp ->data) ; 
}




int main (void){
int num, target ; 
printf("How many nodes are going to be ? ") ; 
scanf("%d",&num) ; 
node *head = malloc(sizeof(node))  ;
node*temp = head ; 
head -> link = NULL ;
create_list(temp, num) ; 
temp = head ; 
display(temp);
printf("Enter the number here : ") ; 
scanf("%d",&target) ;
if(target > num || target < 0){
    printf("Invalid input ") ; 
}  
else {
 temp = head ; 
find(temp,target) ;   
}
 


}