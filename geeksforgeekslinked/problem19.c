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

void sum (node*head){
int sum , count1 = 0 , count2 =0  ; 
printf("Enter the number here : ") ; 
scanf("%d",&sum) ; 
node*temp =head ; 
node*current  ; 
while(temp!=NULL){
    current = temp -> link ;count2 =count1 +1 ; 
    while(current !=NULL ){
    if(temp ->data + current ->data == sum ){
        printf("node %d + node %d add up to the sum(%d+%d)\n",
        count1,count2,temp->data,current ->data
        );

    }
        count2 ++ ; 
        current= current->link ; 
    }


     count1 ++ ; 
    temp = temp -> link  ; 
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
temp =head ; 
sum(temp) ; 

}