#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (strcmp_(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
