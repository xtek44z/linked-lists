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



node* swap_pairwise(node*head,int feed){

node*temp = head ; 
node*current = head -> link ; 
int swap ; 
for(int i =0 ; i<feed ;i++){ 
swap = temp -> data ;
temp -> data = current ->data ; 
current ->data = swap ; 
current = current -> link->link ; 
temp = temp -> link ->link ; 
}
return head ; 
}


int check (int num ){
if(num%2 == 0 ) return (num/2) ; 
else return (num /2)  ; 
}




int main (void){
int num , feed; 
printf("How many nodes are going to be ? ") ; 
scanf("%d",&num) ; 
node *head = malloc(sizeof(node))  ;
node*temp = head ; 
head -> link = NULL ;
create_list(temp, num) ; 
temp = head ; 
display(temp);
feed = check ( num ) ;  
printf("the feed is : %d\n",feed) ; 
temp = head ;
head = swap_pairwise(temp  , feed) ;
temp =head ; 

display(temp) ; 

}