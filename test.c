#include "push_swap.h"
#include <stdio.h>

int main()
{
	int	dataset[6] = {2, 1, 3, 6, 5, 8};
	t_stack	a;
	t_stack	b;
	t_node	*ptr;
	int		i;

	init_stack(&a, 'a');
	init_stack(&b, 'b');
	for (i = 0; i < 6; i++)
		a.push_bottom(&a, get_node(dataset[i]));
	
	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
	s(&a);
	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
	p(&a, &b);
	p(&a, &b);
	p(&a, &b);
	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = b.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");

	rab(&a, &b);
	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = b.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");

	rr(&a);
	rr(&b);
	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = b.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	

	s(&a);
	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}

	printf("\n\n");
	p(&b, &a);
	p(&b, &a);
	p(&b, &a);

	ptr = a.top;
	for (i = 0; i < a.size; i++)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("size b = %d\n", b.size);
}