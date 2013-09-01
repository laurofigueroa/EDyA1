#ifndef __QUEUE_H__

#define MAX_QUEUE 20

typedef struct _Queue {
	int data[MAX_QUEUE];
	int front, back;
} Queue;

#define queue_data(l)	(l)->data
#define queue_front(l)	(l)->front
#define queue_back(l)	(l)->back

Queue *queue_create(void);
int queue_frontdata(Queue *);
Queue *queue_enqueue(Queue *, int);
Queue *queue_dequeue(Queue *);
void queue_print(Queue *);
void queue_destroy(Queue *);

#endif
