/*
  This code will work in Turbo C compiler. It will not work in gcc.
*/
#include<stdio.h>

#define MAX 100

enum validity{true, false} valid;

struct stack
{
  int top;
	int ele[MAX];
}s;

void push(int x)
{
	if(s.top <= MAX)
	{
		s.ele[++s.top] = x;
	}
	else
	{
		printf("\n\nERROR : Stack Overflow. Press any key to exit.");
		getch();
		exit(0);
	}
}

int pop()
{
	if(s.top >= 0)
	{
		return s.ele[s.top--];
	}
	else
	{
		printf("\n\nERROR : Stack Underflow. Press any key to exit.");
		getch();
		exit(0);
	}
	return 0;
}

void empty_stack()
{
	int i = s.top;
	while(i >= 0)
	{
		printf(" %d",pop());
		i--;
	}
	printf("\n");
}

int main()
{
	int i = 0;
	char user_input[MAX];
	int  temp_storage[MAX] , j = -1;
	int  temp_int , previous_temp_int;

	s.top = -1;

	printf("Enter pattern of numbers\n(Maximum length is %d)  :",MAX);
	scanf("%s",user_input);

	printf("\n\nPATTERN:\n\n");

	while(1)
	{
		if(user_input[i] == '\0' || i >= MAX)
		{
			if(valid == true)
			{
				while(j >= 0)
				{
					push(temp_storage[j]);
					j--;
				}
			}
			empty_stack();
			break;
		}

		temp_int = user_input[i] - '0';  // Convert char to int.
		if(temp_int >= 0 && temp_int <= 9)
		{
			if(j == -1)
			{
				valid = false;
				temp_storage[++j] = temp_int;
				previous_temp_int = temp_int;
			}
			else if(temp_int == previous_temp_int - 1)
			{
				valid = true;
				temp_storage[++j] = temp_int;
				previous_temp_int = temp_int;
			}
			else if(valid == true)
			{
				while(j >= 0)
				{
					push(temp_storage[j]);
					j--;
				}
				j = -1;
				empty_stack();
				continue;
			}
			else
			{
				valid = false;
				break;
			}
		}
		else
		{
			printf("\n\nERROR : %c is not valid digit. Press any key to exit.",user_input[i]);
			getch();
			exit(0);
		}
		i++;
	}

	if(valid == true)
		printf("\n\nValid pattern");
	else
		printf("\n\nNot valid pattern.");

	return 0;
}