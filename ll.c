#include<stdio.h>
#include<stdlib.h>
struct ll{
	int data;
	struct ll *link;
}*p;
struct ll *end;
struct ll* reverse(struct ll* llist){
	
	if(llist->link==NULL)
        return llist;
    struct ll* pt=reverse(llist->link);
    llist->link->link=llist;
    llist->link=NULL;
    return pt;
}
void del_atend(){
	if(p==NULL){
	
	printf("NO element in linkedlist\n");
	return;}
	struct ll* temp=p;
	while(temp->link->link!=NULL){
		temp=temp->link;
		}
		
		struct ll *temp1=temp->link;
		temp->link=NULL;
		end=temp;
		free(temp1);
}
void del_atbeg(){
	if(p==NULL){
	
	printf("NO element in linkedlist\n");
	return;}
	struct ll* temp=p;
	p=p->link;
	free(temp);
}
int del_atpos(int pos){
	struct ll *temp,*temp1;
	temp=p;
	if(pos==1){
	
	del_atbeg();
	return;}
	int cou=1;
	//if(end==NULL || end->link!=NULL){
		while(cou!=pos-1){
		temp=temp->link;
		if(temp->link==NULL)
			return -1;
		cou++;
		}
		//end =temp;
		temp1=temp->link;
		temp->link=temp->link->link;
		free(temp1);
		return 0;
}
void insert_atbeg(int d){
	struct ll *temp;
	if(p==NULL){
		p=(struct ll*)malloc(sizeof(struct ll));
		//printf("jhg");
		p->data=d;
		p->link=NULL;
		end=p;
	}
	else{
		temp=(struct ll*)malloc(sizeof(struct ll));
		temp->data=d;
		temp->link=p;
		p=temp;
	}
}
void insert_atend(int d){
	struct ll *temp,*temp1;
	temp=p;
	if(end==NULL || end->link!=NULL){
		while(temp->link!=NULL){
		temp=temp->link;
		}
		end =temp;
	}
	temp1=(struct ll*)malloc(sizeof(struct ll));
		temp1->data=d;
		temp1->link=NULL;
		end->link=temp1;
}
int insert_atpos(int d,int pos){
	struct ll *temp,*temp1;
	temp=p;
	if(pos==1){
	
	insert_atbeg(d);
	return;}
	int cou=1;
	//if(end==NULL || end->link!=NULL){
		while(cou!=pos-1){
		temp=temp->link;
		if(temp==NULL)
			return -1;
		cou++;
		}
		//end =temp;
	
	temp1=(struct ll*)malloc(sizeof(struct ll));
		temp1->data=d;
		temp1->link=temp->link;
		temp->link=temp1;
		return 0;
}
void print(){
	struct ll *temp=p;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int ele_atlast_n(int n){
	struct ll *temp,*prev;
	temp=p;
	while(n){
		temp=temp->link;
		if(temp==NULL)    //out of range pos
			return -1;
		n--;
	}
	
	prev=p;
	while(temp!=NULL){
		temp=temp->link;
		prev=prev->link;
	}
	int res=prev->data;
	return res;
}
int middle_ind(){
	struct ll* slow,*fast;
	slow=p;
	fast=p;
	while(fast!=NULL){
		fast=fast->link;
		if(fast==NULL)
		break;
		fast=fast->link;
		if(fast==NULL)
		break;
		slow=slow->link;
	}
	return slow->data;
}
void main(){
	int ch=-1,n,res;
	while(ch!=0){
		printf("enter choice:- 1 for insert at beg \n 2 for insert at end \n 3 for insert at particular pos\n 4 to print\n 5 for delete at beg \n 6 for delete at end \n 7 for delete at particular pos\n 8 for to find nth element from last\n 9 to find middle element\n 10 to reverse\n 0 for exit\n");
		int da,po;
		scanf("%d",&ch);
		switch(ch){
			case 0:break;
			case 1:printf("enter data ");
			scanf("%d",&da);
			insert_atbeg(da);
			break;
			case 2:printf("enter data ");
			scanf("%d",&da);
			insert_atend(da);
			break;
			case 3:printf("enter data ");
			scanf("%d",&da);
			printf("enter position ");
			scanf("%d",&po);
			int c=insert_atpos(da,po);
			if(c==-1)
			printf("Invalid position\n");
			break;
			case 4:print();
				break;
			case 5:del_atbeg();
			break;
			case 6:del_atend();
			break;
			case 7:
			printf("enter position ");
			scanf("%d",&po);
			int cu=del_atpos(po);
			if(cu==-1)
			printf("Invalid position\n");
			break;
			case 8:
			printf("enter n ");
			scanf("%d",&n);
			int res=ele_atlast_n(n);
			printf("%d\n",res);
			break;
			case 9:
			res=middle_ind();
			printf("%d\n",res);
			break;
			case 10:
			if(p!=NULL)p=reverse(p);
			else printf("NO element in linkedlist\n");
			break;
			default:printf("Invalid Choice\n");
			break;
		}
		
	}
	//printf("%d",p->data);
}
