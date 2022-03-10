#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *start='\0',*temp,*newnode,*newnode1,*nextnode,*ptr;
void create();
void display();
void insert_at_beg();
void insert_at_pos();
void insert_at_end();
void delete_from_beg();
void delete_from_pos();
void delete_from_end();
void searching();
void reverse();
int main()
{
	int c;
	while(1)
	{
		printf("\nPress 1 for creation of doubly linklist");
		printf("\nPress 2 for display");
		printf("\nPress 3 for inserting a node at beginning");
		printf("\nPress 4 for inserting a node at a given position");
		printf("\nPress 5 for inserting a node at end");
		printf("\nPress 6 for deletion of a node from beginning");
		printf("\nPress 7 for deletion of a node from a position");
		printf("\nPress 8 for deletion of a node from end");
		printf("\nPress 9 for searching a value");
		printf("\nPress 10 for reverse the linklist");
		printf("\nPress 11 for exit");
		scanf("%d",&c);
		switch(c)
		{
			case 1:create();
			        break;
			case 2:display();
			        break;
			case 3:insert_at_beg();
			        break;
			case 4:insert_at_pos();
			        break;
			case 5:insert_at_end();
			        break;
			case 6:delete_from_beg();
			        break;
			case 7:delete_from_pos();
			        break;
			case 8:delete_from_end();
			        break;
			case 9:searching();
			        break;
			case 10:reverse();
			        break;
			case 11:exit(0);	      
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
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data");
		scanf("%d",&newnode->data);
		newnode->prev=newnode->next='\0';
		
		if(start=='\0')
		{
			start=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
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
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void insert_at_beg()
{
	newnode1=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data");
	scanf("%d",&newnode1->data);
	newnode1->prev=newnode1->next='\0';
	
	temp=start;
	if(start=='\0')
	{
		start=newnode1;
	}
	else
	{
		temp->prev=newnode1;
		newnode1->next=temp;
		start=newnode1;
	}	
}
void insert_at_pos()
{
	int i=1,pos;
	printf("\nEnter position");
	scanf("%d",&pos);
	temp=start;
	if(start=='\0')
	{
		start=temp=newnode1;
	}
	else
	{
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	newnode1=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data");
	scanf("%d",&newnode1->data);
	newnode1->prev=newnode1->next='\0';
	
	newnode1->prev=temp;
	newnode1->next=temp->next;
	temp->next=newnode1;
	newnode1->next->prev=newnode1;	
	}
}
void insert_at_end()
{
  temp=start;
  if(start=='\0')
  {
  	start=newnode1;
  }
  else
  {
  while(temp->next!='\0')
  {
  	temp=temp->next;
  }
  newnode1=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter data");
  scanf("%d",&newnode1->data);
  newnode1->prev=newnode1->next='\0';
  
  temp->next=newnode1;
  newnode1->prev=temp;
  }  
}
void delete_from_beg()
{
	temp=start;
	if(start->next=='\0')
	{
		start='\0';
		free(temp);
	}
	else
	{
		start=temp->next;
		free(temp);
	}
}
void delete_from_pos()
{
	int i=1,pos;
	printf("\nEnter position");
	scanf("%d",&pos);
	temp=start;
	ptr=temp->next;
	if(start->next='\0')
	{
		start='\0';
		free(temp);
	}
	else
	{
		while(i<pos-1)
		{
			temp=temp->next;
			ptr=temp->next;
			i++;
		}
		temp->next=ptr->next;
		ptr->next->prev=temp;
		free(ptr);
	}	
}
void delete_from_end()
{
	temp=start;
	if(start->next='\0')
	{
		start='\0';
		free(temp);
	}
	else
	{
		while(temp->next!='\0')
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next='\0';
		free(temp);			
	}
}
void searching()
{
	int value,p=0,r=1;
	printf("\nEnter value");
	scanf("%d",&value);
	temp=start;
	while(temp!='\0')
	{
		if(temp->data==value)
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
	if(p==1)
	{
		printf("\n value found at %d location",r);
	}
	else
	{
	printf("\n value not found");
    }
}
void reverse()
{
    temp=nextnode=start;
   	ptr='\0';
   	while(nextnode!='\0')
   	{
   	  nextnode=nextnode->next;
   	  temp->next=ptr;
   	  ptr=temp;
	  temp=nextnode;	 	
	 }
	start=ptr;
}








