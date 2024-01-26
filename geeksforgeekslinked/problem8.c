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



node* delete_node(node*point){
node*temp = point ; 
point = point -> link ; 
free(temp) ; 
return point ; 

}


node* find_dup(node*head ){
node *temp = head ; int num  ; 
node*current ;
while(temp != NULL){

num = temp->data ; 
current = temp ; 
    while(current != NULL){
        if(num == current->link->data){
        current->link = delete_node(current->link) ; 
        }
        else {
        current = current -> link ; 
        }
}
temp = temp -> link ; 
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
head = find_dup(temp) ;
temp =head ; 
display(temp) ; 

}