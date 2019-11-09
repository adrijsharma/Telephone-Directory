#include<stdio.h>
void add();
void view();
void search();
void reset();
int caller()
{
    int selection;
    printf("\n\nPlease select the required option\n");
    printf("1. Search a contact\n2. View all contacts\n3. Add contact\n4. Edit a contact\n5. Delete a contact\n");
    printf("6. Starred contacts\n7. Manage groups\n8. Merge contacts\n9. Recenty views\n10. Reset everything to default\n11. Close the directory");
    printf("\n\nEnter your selected choice: ");
    scanf("%d",&selection);
    switch(selection)
    {
	case(3):
	    add();
	    caller();
	    break;
	case(2):
	    view();
	    caller();
	    break;
	case(1):
	    search();
	    caller();
	    break;
	case(10):
	    reset();
	    caller();
	    break;
    }
}
int main()
{
    printf("Welcome to telephone directory\n");
    caller();
    return 0;
}
