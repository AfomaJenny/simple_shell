#include "shell.h"
/**
* list_len - determines length of linked list
* @h: pointer to first node
*
* Return: size of list
*/
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
/**
* list_to_strings - returns an array of strings of the list->str
* @head: pointer to first node
*
* Return: array of strings
*/
char **list_to_strings(list_t *head)
{
	size_t count = list_len(head);
	char **strings = malloc(sizeof(char *) * (count + 1));
	size_t i = 0;

	if (!strings)
		return (NULL);

	while (head)
	{
		strings[i] = _strdup(head->str);
		if (!strings[i])
		{
			free_strings(strings);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
/**
* print_list - prints all elements of a list_t linked list
* @h: pointer to first node
*
* Return: size of list
*/
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(';');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
* node_starts_with - returns node whose string starts with prefix
* @node: pointer to list head
* @prefix: string to match
* @c: the next character after prefix to match
*
* Return: match node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
* get_node_index - gets the index of a node
* @head: pointer to list head
* @node: pointer to the node
*
* Return: index of node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}