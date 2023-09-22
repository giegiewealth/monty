#include "monty.h"
/**
<<<<<<< HEAD
* f_pint - prints the top
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
=======
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
>>>>>>> ab4891be8b37a3e8c8d1f19e359263a4dad7e3f3
}
