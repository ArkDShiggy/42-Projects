#include "queue.h"

t_queue *new_queue(void *node)
{
	t_queue *new;

	new = (t_queue *)ft_malloc(sizeof(t_queue));
	new->node = node;
	new->size = 1;
	new->next = NULL;
	new->last = new;
	return new;
}

void queue_push(t_queue **queue, void *node)
{
	t_queue *new;

	if (*queue)
	{
		new = (t_queue *)ft_malloc(sizeof(t_queue));
		new->node = node;
		new->next = NULL;
		new->size = (*queue)->size + 1;
		new->last = new;
		if ((*queue)->last)
			(*queue)->last->next = new;
		(*queue)->last = new;
	}
	else
		*queue = new_queue(node);
}

void *queue_pop(t_queue **queue)
{
	void *node;
	t_queue *tmp;

	tmp = *queue;
	node = tmp->node;
	*queue = tmp->next;
	if (*queue)
		(*queue)->last = tmp->last;
	free(tmp);
	return node;
}
