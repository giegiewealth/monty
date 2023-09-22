#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 1024

/**
 * struct stack_s - Stack structure
 * @n: Integer data
 * @next: Pointer to the next element in the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

stack_t *stack = NULL;

/**
 * push - Pushes an element onto the stack
 * @line_number: The line number of the opcode in the file
 * @value: The value to be pushed onto the stack
 */
void push(unsigned int line_number, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = stack;
    stack = new_node;
}
