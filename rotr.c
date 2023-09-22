#include "monty.h"
/**
<<<<<<< HEAD
*f_rotr- rotates the stack to the bottom
*@head: stack head
*@counter: line_number
*Return: no return
*/
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *copy;

copy = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
=======
  *f_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
>>>>>>> ab4891be8b37a3e8c8d1f19e359263a4dad7e3f3
}
