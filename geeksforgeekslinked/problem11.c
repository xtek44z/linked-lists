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


node *delete_alternate(node*head,int num ){
node*prev = head; 
node*current ;
node*next ; 
int count = 1; 
while(count != num){ 
 
    if(count % 2 == 0){
    
    current = prev -> link ; 
    next  = current -> link ; 
    prev -> link = next ; 
    free(current) ;
    current = NULL ;
    prev = prev -> link ; 
    }
      count ++ ; 
}

return head ; 

}







int main (void){
int num ; 
printf("How many nodes are going to be ? ") ; 
scanf("%d",&num) ; 
node *head = malloc(sizeof(node))  ;
node*temp = head ; 
head -> link = NULL ;
create_list(temp, num) ; 
temp = head ; 
temp = head ; 
head = delete_alternate(temp, num ) ; 
display(temp) ; 

}