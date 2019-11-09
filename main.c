#include<stdio.h>
void add();
void view();
void search();
void reset();
int caller(int selection)
{
    switch(selection)
    {
	case(1):
	    add();
	    break;
	case(2):
	    view();
	    break;
	case(3):
	    search();
	    break;
	case(10):
	    reset();
	    break;
    }
}
int main()
{
    int selection;
    printf("Welcome to telephone directory\n");
    printf("Please select the required option\n");
    printf("1. Add a new number\n2. View all the numbers\n3. Search a number\n");
    printf("10. Reset everything to default\n");
    printf("Enter your selected choice: ");
    scanf("%d",&selection);
    caller(selection);
    return 0;
}
