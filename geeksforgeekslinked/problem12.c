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



node*sum_last_n_nodes(node*head , int num ) {
    int n, sum =0  ; 
node*temp = head; 
printf("Enter the number n here : \n") ; scanf("%d",&n) ; 
int times = num -n ; //supposing that if the number n is bigger than num 
//we will consider it as num = n  
for(int i =0 ; i<times ; i++){
    temp = temp -> link ; 
}
while(temp !=NULL){
sum +=temp -> data ; 
temp  =temp -> link ; 
}
printf("The sum is : %d\n",sum ) ; 
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
printf("\n") ; 
temp =head ; 
head = sum_last_n_nodes(temp,num) ; 
 



}