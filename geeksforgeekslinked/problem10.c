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


int check (int num){
    if(num % 2 ==0 )return 1  ;
    else return 2 ; 
}


node*change_middle_tohead(node*head,int num  ){
node*temp = head ; 
node*current ; 

for(int i =0 ; i<(num/2) -1; i++){
    temp = temp -> link   ; 
}
current = temp -> link ; 
temp -> link = current -> link ; 
current ->link = head ; 
head =current ; 
return head ; 



}




int main (void){
int num, feed ; 
printf("How many nodes are going to be ? ") ; 
scanf("%d",&num) ; 
node *head = malloc(sizeof(node))  ;
node*temp = head ; 
head -> link = NULL ;
create_list(temp, num) ; 
temp = head ; 
display(temp); 
feed = check(num ) ; 

if(feed ==1)printf("\noperation cannnot be done ! \n") ; 
else {temp = head ; 
head  =change_middle_tohead(temp, num) ;
}
 
temp = head ;
printf("\n") ;  
display(temp) ; 

}