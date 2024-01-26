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

node* sort(node*head){
node*temp = head ; 
node*current  ; 
int swap ; 
while(temp->link !=NULL){
current = temp ->link ; 
    while(current!=NULL){
     if(temp->data > current ->data ){
      swap = temp ->data ; 
      temp->data = current ->data ; 
      current ->data = swap ; 
    }    
    current = current->link ; 
    }
temp = temp -> link ; 
}

return head ;

}


node*insert_in_sorted(node*head){
    int element, done = 0  ; 
    node*temp =head ;
    node*next = temp -> link ; 
printf("Enter the element you want to insert :") ; 
scanf("%d",&element) ; 
node*current = malloc(sizeof(node)) ; 
current -> link = NULL; 
current -> data = element ; 
while(temp -> link !=NULL){
    if(element<next ->data && element > temp ->data){
        done =1 ; 
        break ; 

    }
temp = temp -> link ; 
next = next -> link ; 
}

if(done==1){//inserting in the middle 
temp -> link  = current ; 
current ->link = next ; 

}
else if(done == 0 && element<head->data){//inserting in the beginning 
current -> link = head ; 
head = current ; 
}
else if (done== 0 && element>temp -> data ){//inserting at the end 
temp -> link = current  ; 

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
display(temp); 
temp = head ;
head = sort(temp) ; 
temp =head ; 
display(temp) ; 
temp =head ; 
head = insert_in_sorted(temp) ; 
temp =head ; 
display(temp) ; 

}