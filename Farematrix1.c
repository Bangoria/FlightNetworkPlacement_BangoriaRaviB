/*
	Program 1 : Write a program to simulate the push/pop functionality of a Stack. The requirements
	are

	a) It should be possible to PUSH numbers (0 - 9) on the stack
	only in the proper sequence. Meaning, the allowed sequence is
	PUSH 0, PUSH 1, PUSH 2, PUSH 3, PUSH 4, PUSH 5, PUSH
	6, PUSH 7, PUSH 8, PUSH 9. It should not be possible to skip
	numbers in between. PUSH 2, PUSH 4 is not allowed.

	b) Given a random pattern of numbers, the program should be
	able to validate if it is possible to generate the given pattern
	using a number of PUSH - POP operations. For example: the
	pattern 4 3 2 1 0 9 8 7 6 5 is achievable using the following
	PUSH - POP sequence

	PUSH 0, PUSH 1, PUSH 2, PUSH 3, PUSH 4, POP 4, POP 3,
	POP 2, POP 1, POP 0, PUSH 5, PUSH 6, PUSH 7, PUSH 8,
	PUSH 9, POP 9, POP 8, POP 7, POP 6, POP 5

	The results from the POP commands can be printed on the
	console to show the pattern. This is a valid pattern and can be
	achieved using PUSH - POP


	<b>This code will work in Turbo C compiler. It will not work in gcc.</b>
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