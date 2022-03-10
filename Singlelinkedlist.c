#include<stdio.h>

#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *start='\0',*newnode,*temp,*new_node,*ptr;
void create();
void display();
void insert_at_beg();
void insert_at_position();
void insert_at_end();
void searching();
void delete_from_beg();
void delete_from_position();
void delete_from_end();
int main()
{
	int c ;
	while(1)
	{
		printf("\nEnter 1 for creating a linklist");
		printf("\nEnter 2 for displaying a linklist");
		printf("\nEnter 3 for searching");
		printf("\nEnter 4 for inserting node at beginning");
		printf("\nEnter 5 for inserting node at a  given position");
		printf("\nEnter 6 for inserting a node at end");
		printf("\nEnter 7 for deleting node from beginning ");
		printf("\nEnter 8 for deleting node from a given position");
		printf("\nEnter 9 for deleting node from end");
		printf("\nEnter 10 for exit");
	    scanf("%d",&c);
		
		switch(c)
		{
			case 1:create();
			       break;
			case 2:display();
			       break;
			case 3:searching();
			       break;
			case 4:insert_at_beg();
			       break;
			case 5:insert_at_position();
			       break;
			case 6:insert_at_end();
			       break;
			case 7:delete_from_beg();
			       break;
			case 8:delete_from_position();
			       break;
			case 9:delete_from_end();
			       break;
			case 10:exit(0);
		}
	}	
}
void create()
{
	int i=1,choice;
	printf("\nEnter no of nodes you want");
	scanf("%d",&choice);
	while(i<=choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data");
		scanf("%d",&newnode->data);
		newnode->next='\0';
		
		if(start=='\0')
		start=temp=newnode;
		
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		i++;
	}	
}
void display()
{
	temp=start;
	while(temp!='\0')
	{
	  printf("\nThe list you given\n");
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void insert_at_beg()
{
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data");
	scanf("%d",&new_node->data);
	new_node->next='\0';
	
	new_node->next=start;
	start=new_node;
}
void insert_at_end()
{
	temp=start;
	while(temp->next!='\0')
	{
		temp=temp->next;
	}
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data");
	scanf("%d",&new_node->data);
	new_node->next='\0';
	
	temp->next=new_node;
}
void insert_at_position()
{
	int pos,i=1;
	printf("\nEnter position to insert");
	scanf("%d",&pos);
	temp=start;
	ptr=temp->next;
	while(i<pos-1)
	{
		temp=temp->next;
		ptr=temp->next;
		i++;
	}
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data");
	scanf("%d",&new_node->data);
	new_node->next='\0';
	
	new_node->next=ptr;
	temp->next=new_node;
		
}
void searching()
{
	int data,p=0,r=1;
	printf("\nEnter data to search");
	scanf("%d",&data);
	temp=start;
	while(temp!='\0')
	{
		if(temp->data==data)
		{
			p=1;
			break;
		}
		else
		{
			temp=temp->next;
			r++;
		}
	}
	if(p==0)
	printf("\n No not found");
	
	else
	printf("\n No found at %d location",r);
}
void delete_from_beg()
{
	temp=start;
	start=temp->next;
	free(temp);
}
void delete_from_position()
{
	int pos,i=1;
	printf("\nEnter position");
	scanf("%d",&pos);
	temp=start;
	ptr=temp->next;
	while(i<pos-1)
	{
		temp=temp->next;
		ptr=temp->next;
		i++;
	}
	temp->next=ptr->next;
	free(ptr);	
}
void delete_from_end()
{
	temp=start;
	while(temp->next!='\0')
	{
		ptr=temp;
		temp=temp->next;
	}
	ptr->next='\0';
	free(temp);
}