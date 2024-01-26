#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data ; 
  struct node*link ;
}node;



node* create_node (node*head, int num ){
node*current = malloc(sizeof(node)) ; 
printf("Enter the data of the node %d:\n",num) ; 
scanf("%d",&(current-> data)) ;
current -> link = NULL ; 
return  current ;
}


void feedback(int *feed ){
printf("Do you want to create another node ? " ) ; 
scanf("%d",feed) ; 
}


void display (node*head){
int count = 0 ; 
while(head != NULL ){
    count ++  ; 
    printf("The data you entered for node %d is : %d\n",count,head->data) ; 
    head = head -> link ; 
}
}


int check (int num ){
if(num % 2==0){printf("operation cannot be done ") ;return 2 ; } 
else {return 1;}  
}


void fun (node*head, int num){
node*temp = head ;
for(int i =0 ; i<(num/2) ;i++ ){
temp = temp ->link ; 
}
printf("The middle of this linked list is  %d(node : %d) ",temp -> data,(num/2)+1) ; 
}






int main (){
    int feed=0 , num=1 , result;
 
node*current ; 
node*head = malloc (sizeof(node)) ;
node*temp = head ; 
printf("Enter the data of the node 1 \n") ; 
scanf("%d",&(head ->data)) ; 
head -> link = NULL ;  
do{num ++ ;
current = create_node (temp,num); 
temp -> link = current ; 
temp = temp -> link ; 
feedback (&feed) ; 
}while(feed ==1 ) ; 
temp = head ; 
display(temp) ; 
printf("%d \n",num) ; 
result = check(num) ; 
if(result ==1 )fun(head , num) ; 
else return 0 ;
}