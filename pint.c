#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * pint - Prints the value at the top of the stack
 * @line_number: The line number of the opcode in the file
 */
void pint(unsigned int line_number)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

/**
 * main - Main function for monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (strcmp(line, "push") == 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        else if (strncmp(line, "push ", 5) == 0)
        {
            int value = atoi(line + 5);
            if (value == 0 && line[5] != '0')
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(line_number, value);
        }
        else if (strcmp(line, "pint") == 0)
        {
            pint(line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    if (line)
        free(line);

    return (EXIT_SUCCESS);
}
