#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node{
	int val;
	struct node *down;
};

struct node *top=NULL;

void push(int value){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=value;
	if(top==NULL){
		temp->down=NULL;
		top=temp;
	}
	else{
		temp->down=top;
		top=temp;
	}
}

void display_stack(){
	struct node *curr;
	curr=top;
	if(top==NULL){
		cout<<"\nEmpty Stack";
	}
	else{
		cout<<"\nStack is :";
		while(curr!=NULL){
			cout<<"\n"<<curr->val;
			curr=curr->down;
		}
	}
}

void peek(){
	if(top==NULL){
		cout<<"Stack is empty";
	}
	else{
		cout<<"TOP is : "<<top->val;
	}
}

void pop(){
	if(top==NULL){
		cout<<"\nStack is already empty";
	}
	else{
		cout<<"\nPop operation successful, poped element = "<<top->val;
		struct node *temp;
		temp=top;
		top=top->down;
		temp->down=NULL;
		free(temp);
	}
}

int main(){
	int ch,value;
	do{
		cout<<"Enter element to push : ";
		cin>>value;
		push(value);
		cout<<"Do yo want to push more elements (0/1) : ";
		cin>>ch;
	}while(ch>0);
	display_stack();
	pop();
	display_stack();
	return 0;
}
