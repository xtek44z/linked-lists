#include<stdio.h>
#include<stdlib.h>



typedef struct node {
    int data  ;
    struct node*link ; 

}node ; 

void create_list(node*head1,node*head2,int num1,int num2){
    // creating the first linked list // 
head1 -> link = NULL ; 
printf("Enter the data of the node 1 :") ; 
scanf("%d",&(head1->data)) ; 
node*temp = head1 ; 
node*current ; 
for(int i =0 ; i<num1 ;i++){
current = malloc(sizeof(node)) ; 
printf("Enter the data of the node %d : ",i+2);
scanf("%d",&(current->data)) ; 
current ->link = NULL ;
temp -> link = current ; 
temp = temp -> link ; 
}
        //creating the second linked list // 


head2 -> link = NULL ; 
printf("LINKED LIST 2 \nEnter the data of the node 1 :") ; 
scanf("%d",&(head2->data)) ; 
node*temp2 = head2 ; 
node*current2 ; 
for(int i =0 ; i<num2 ;i++){
current2 = malloc(sizeof(node)) ; 
printf("Enter the data of the node %d: ", i+2);
scanf("%d",&(current2->data)) ; 
current2 ->link = NULL ;
temp2 -> link = current2 ; 
temp2= temp2 -> link ; 
}
}

void display(node*head){
    int count =0 ; 
while(head !=NULL){
    count ++   ; 
    printf("node %d : %d\n",count,head->data) ;
    head = head ->link  ; 
}
}







int main (void){
int num1 , num2 ; 
printf("Number of Elements for linked list 1:"); 
scanf("%d",&num1) ; 
printf("Number of Elements for linked list 2:"); 
scanf("%d",&num2) ; 
node*head1= malloc(sizeof(node)) ; 
node*head2= malloc(sizeof(node)) ; 
node*temp,*temp2;
create_list(head1,head2,num1,num2) ; 
printf("DATA FOR LIST 1 : \n");
temp =head1 ; 
display(temp) ; 
printf("\nDATA FOR LIST 2 : \n");
temp2 = head2 ; 
display(temp2) ; 






}