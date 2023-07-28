#include "shell.h"

/**
 * add_alias_end - Adds a node to the end of an alias_t linked list.
 * @head: A pointer to the head of the alias_t list.
 * @name: The name of the new alias to be addded.
 * @value: The value of the new alias to be added.
 *
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *new_alias = malloc(sizeof(alias_t));
	alias_t *last;

	if (!new_alias)
		return (NULL);

	new_alias->next = NULL;
	new_alias->name = malloc(sizeof(char) * (_strlen(name) + ));
	if (!new_alias->name)
	{
		free(new_alias);
		return (NULL);
	}
	new alias->value = value;
	_strcpy(new_alias->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_alias;
	}
	else
		*head = new_alias;

	return (new_alias);
}

/**
 * add_node_end - Adds a node to the end of a list_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @dir: The directory path for the new node to contain.
 *
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 */
list_t *add_node_end(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * free_alias_list - Frees an alias_t linked list.
 * @head: The head of the alias_t list.
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head);
		head = next;
	}
}

/**
 * free_list - frees a list_t linked list.
 * @head: The head of the list_t list.
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
