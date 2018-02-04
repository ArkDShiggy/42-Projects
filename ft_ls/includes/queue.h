#ifndef QUEUE_H
# define QUEUE_H

# include "libft.h"

typedef struct		s_queue
{
	struct s_queue	*next;
	struct s_queue	*last;
	void			*node;
	int				size;
}					t_queue;

t_queue				*new_queue(void *node);
void				queue_push(t_queue **queue, void *node);
void				*queue_pop(t_queue **queue);

#endif
