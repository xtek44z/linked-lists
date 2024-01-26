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


void reverse(node*head ){
node*temp2; 
node*temp = NULL ;  
while(head !=NULL ){
temp2 = head -> link ; 
head -> link = temp ;
temp  = head ;  
head = temp2 ; 
}
head = temp ; 
if(head== NULL) printf("error") ; 
else{printf("The reversed liked list is : \n") ; 

   while(head!=NULL){
 printf("%d \n",head -> data) ; 
 head = head ->link ; 
} 
}



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
display(temp); 
 reverse(temp) ; 


} 