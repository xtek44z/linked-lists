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


node*rearrange(node*head, int num, int odd , int even){
    int count =0 , swap; 
node*temp = head ;
node*current= head -> link  ;  
for(int i =0 ; i< num-1 ; i++){

 while(count!=odd){
    if(current-> data % 2 !=0 && current ->data > temp ->data){
        
    }
    else if (current-> data % 2 !=0 && current ->data < temp ->data){

    }

count ++; 
    }
        
}
}



void count (node*head , int *odd ,int *even , int num){
    for(int i =0; i<num-1 ; i++){
        if(head->data %2 ==0)*even ++ ;
        else *odd ++ ; 
        head =head-> link ; 
    }
}


int main (void){
int num,odd=0 ,even =0 ; 
printf("How many nodes are going to be ? ") ; 
scanf("%d",&num) ; 
node *head = malloc(sizeof(node))  ;
node*temp = head ; 
head -> link = NULL ;
create_list(temp, num) ; 
temp = head ; 
display(temp); 
count(temp,&odd,&even,num) ; 
temp = head ;
head = rearrange(temp,num,odd,even) ; 
temp = head ;
display(temp) ; 



}