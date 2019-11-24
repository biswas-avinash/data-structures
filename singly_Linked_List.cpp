#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//declaring a node
struct node{
	int val;
	struct node *next;
};

struct node *start=NULL;

//create the linked list
void create(){
	struct node *curr,*temp;
	cout<<"Enter the nodes : \n";
	int x;
	do{
		temp=(struct node *)malloc(sizeof(struct node));
		cout<<"Enter value : ";
		cin>>temp->val;
		temp->next=NULL;
		if(start==NULL){
			start=temp;
		}
		else{
			curr->next=temp;
		}
		curr=temp;
		cout<<"Do you want to enter more nodes (0/1) : ";
		cin>>x;
	}while(x>0);
}

//print all nodes
void display(){
	struct node *curr;
	curr=start;
	if(start==NULL){
		cout<<"\nEmpty Linked List";
	}
	else{
		cout<<"\nSingly Linked List : ";
		while(curr!=NULL){
			cout<<curr->val<<" - > ";
			curr=curr->next;
		}	
	}
}

//insert at the end
void insertNode(){
	struct node *temp,*curr;
	curr=start;
	temp=(struct node *)malloc(sizeof(struct node));
	cout<<"\nEnter value to insert : ";
	cin>>temp->val;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=temp;
	}
}

//delete a node from end
void deleteNode(){
	struct node *curr,*curr_prev;
	curr=start;
	curr_prev=NULL;
	while(curr->next!=NULL){
		curr_prev=curr;
		curr=curr->next;
	}
	if(curr==NULL){
		cout<<"Empty Linked List";
	}
	else{
		if(start->next==NULL){
			start=NULL;
		}
		else{
			curr_prev->next=NULL;	
		}
		free(curr);
	}
}

//driver function
int main(){
	create();
	display();
	insertNode();
	display();
	cout<<"\nDeletion";
	deleteNode();
	display();
	return 0;
}
