/*
  This code will work in Turbo C compiler. It will not work in gcc.
*/
#include<stdio.h>
#include<alloc.h>

struct node
{
  int ele;
	struct node *next;
};

struct node * addnode(struct node *l, int x) // To add nodes at the end of list.
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->next = NULL;
	temp->ele = x;


	if(l == NULL)
		return temp;
	else
	{
		l->next = temp; // l is last node
		return temp;
	}
}

void delete_after(struct node *p) // Delete node after node p
{
       struct node  *temp;

       temp = p->next;
       p->next = temp->next;
       free(temp);
}

int count(struct node *first) // Count number of nodes in list
{
	int c=0;
	struct node *temp = first->next;

	if(first->next == first)
		return 1;

	while(temp != first)
	{
		c++;
		temp = temp->next;
	}
	c++;
	return c;
}

void exit_prog(struct node *temp) // At exit time, free runtime allocated memory.
{
	struct node *p,*start;

	start = temp->next;
	while(start != temp)
	{
		p=start->next;
		free(start);
		start=p;
	}
	exit(0);
}


int main(void)
{
	int i,j,random_num;
	int total_kids;
	struct node *start, *list, *p;


	/*******************************************
		          Initial proccedure
	********************************************/
	printf("Enter total number of kids : ");
	scanf("%d",&total_kids);

	if(total_kids == 0)
	{
		printf("\nERROR  0 is not valid number of kids. Press any key to exit.");
		getch();
		exit(0);
	}
	else if(total_kids == 1)
	{
		printf("\n\n\nWinner : 1");
		getch();
		exit(0);
	}

	i = 0;
	list = NULL;

	while(i < total_kids)
	{
		list = addnode(list, i);
		list->next = start;

		if(i == 0)
		{
			start=list;
		}
		i++;
	}

	printf("Enter random number between 1 to %d : ",total_kids-1);
	scanf("%d",&random_num);

	if(random_num <= 0 || random_num >= total_kids)
	{
		printf("\nERROR  Random number is not valid. Press any key to exit.");
		getch();
		exit_prog(start);
	}



	/*******************************************
		          Algo Implementation
	********************************************/
	p = list;
	while(count(p) > 1) //While there are more than one node in list.
	{
		j = 0;
		while(j < random_num - 1)
		{
			p = p->next;
			j++;
		}
		delete_after(p);
	}

	printf("\nWinner : %d",p->ele);

	exit_prog(p);
	return 0;
}


