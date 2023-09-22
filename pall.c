/**
 * pall - Prints all elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;  /* Create a pointer to traverse the stack */

    (void)line_number; /* Unused parameter */

    /* Loop through the stack and print its elements */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next; /* Move to the next element */
    }
}
