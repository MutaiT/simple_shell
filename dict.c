#include "dict.h"

/**
  * get_dict_val - Get a value from a dictionary
  * @head: dict
  * @key: Entry key
  *
  * Return: Pointer to the entry value
  */
char *get_dict_val(dict_t *head, const char *key)
{
	if (!key)
		return (NULL);

	while (head)
	{
		if (!_strcmp(head->key, key))
			return (head->val);
		head = head->next;
	}

	return (NULL);
}


/**
  * get_dict_node - Retrieves a node by key
  * @head: dict
  * @key: Entry key
  *
  * Return: Node or NULL
  */
dict_t *get_dict_node(dict_t *head, const char *key)
{
	if (!head)
		return (NULL);
	if (!_strcmp(head->key, key))
		return (head);
	return (get_dict_node(head->next, key));
}


/**
  * add_dict_node_end - Adds node at the end of list
  * @headptr: Pointer to dict
  * @key: Entry key
  * @val: Entry val
  * Return: Pointer to list
  */
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val)
{
	dict_t *new;

	if (!headptr)
		return (NULL);

	if (*headptr)
		return (add_dict_node_end(&((*headptr)->next), key, val));

	new = malloc(sizeof(dict_t));
	if (!new)
		return (NULL);

	new->key = _strdup(key);
	new->val = _strdup(val);
	new->next = NULL;

	*headptr = new;
	return (new);
}


/**
  * del_dict_node - Deletes a node
  * @headptr: Pointer to dict
  * @key: Entry key
  *
  * Return: Pointer to resulting list
  */
dict_t *del_dict_node(dict_t **headptr, const char *key)
{
	dict_t *tmp;

	if  (!(headptr && *headptr))
		return (NULL);
	if (!_strcmp((*headptr)->key, key))
	{
		tmp = *headptr;
		(*headptr) = tmp->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
	else
		del_dict_node(&((*headptr)->next), key);
	return (*headptr);
}


/**
 * free_dict - Free a linked list and and set head to NULL
 * @headptr: The first list node
 */
void free_dict(dict_t **headptr)
{
	if (!*headptr)
		return;

	free_dict(&((*headptr)->next));
	free((*headptr)->key);
	free((*headptr)->val);
	free(*headptr);
	*headptr = NULL;
}
