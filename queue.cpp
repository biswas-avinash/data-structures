//@biswas-avinash
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//declaring nodes
struct node{
	int val;
	struct node *next;
};

//front and rear pointers
struct node *front=NULL;
struct node *rear=NULL;

//insert operation
void insertQ(int value){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=value;
	if(front==NULL){
		front=temp;
		rear=temp;
		temp->next=NULL;
	}
	else{
		rear->next=temp;
		rear=temp;
		temp->next=NULL;
	}
}

//prints queue 
void displayQ(){
	struct node *curr;
	curr=front;
	if(front==NULL){
		cout<<"Queue is empty";
	}
	else{
		cout<<"\nQueue is :\nfront<-";
		while(curr!=rear->next){
			cout<<curr->val<<"<-";
			curr=curr->next;
		}
		cout<<"rear";
	}
}

//delete operation
void deleteQ(){
	if(front==NULL){
		cout<<"\nQueue is empty";
	}
	else{
		cout<<"\nDelete operation done successfully, deleted elemet : "<<front->val;
		struct node *temp;
		temp=front;
		if(front==rear){
			rear=NULL;	
		}
		front=front->next;
		temp->next=NULL;
		free(temp);
	}
}

//driver function
int main(){
	int ch,value;
	do{
		cout<<"Enter value to insert : ";
		cin>>value;
		insertQ(value);
		cout<<"Do you want to insert more (0/1) : ";
		cin>>ch;
	}while(ch>0);
	displayQ();
	deleteQ();
	displayQ();
}
