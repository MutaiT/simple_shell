#include "command.h"

/**
 * cmd_to_tree - Constructs a binary tree of commands
 * @tokens: The command to parse
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return the
 * address of the root of the new tree
 */
cmdtree_t *cmd_to_tree(const char * const *tokens __attribute__((unused)))
{
	return (NULL);
}

/**
 * free_cmdtree - Frees a binary tree and and set root to NULL
 * @rootptr: Pointer
 * Return: NULL
 */
void free_cmdtree(cmdtree_t **rootptr)
{
	if (rootptr && *rootptr)
	{
		free_cmdtree(&((*rootptr)->success));
		free_cmdtree(&((*rootptr)->failure));
		(*rootptr)->tokens = NULL;
		(*rootptr) = NULL;
	}
}
