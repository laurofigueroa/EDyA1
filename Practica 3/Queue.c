#include <stdlib.h>
#include "Queue.h"
#include <stdio.h>

Queue *queue_create(void)
{
	Queue *newqueue = malloc(sizeof(Queue));
	queue_front(newqueue) = -1;
	queue_back(newqueue) = -1;
	return newqueue;
}

int queue_frontdata(Queue *cola)
{
	if(cola == NULL || queue_front(cola) == -1 || queue_back(cola) == -1)
		return 5000;
	return queue_data(cola)[queue_front(cola)];
}

Queue *queue_enqueue(Queue *cola,int data)
{
	if(cola == NULL){
		Queue *newqueue = queue_create();
		queue_data(cola)[0] = data;
		queue_front(cola) = 0;
		queue_back(cola) = 0;
		return newqueue;
	}
	 else if(queue_front(cola) < queue_back(cola) && queue_front(cola) == 0&& queue_back(cola) < MAX_QUEUE-1){
		queue_data(cola)[++queue_back(cola)] = data;
		return cola;
	}
	else if(queue_front(cola) < queue_back(cola) && queue_front(cola) > 0 && queue_back(cola) == MAX_QUEUE-1) {
		queue_data(cola)[0] = data;
		queue_back(cola) = 0;
		return cola;
	}
	else if(queue_front(cola) < queue_back(cola) && queue_front(cola) == 0 && queue_back(cola) == MAX_QUEUE-1)
		return cola;
	else if(queue_front(cola) == queue_back(cola) && queue_front(cola) != -1 && queue_back(cola) < MAX_QUEUE-1) {
		queue_data(cola)[++queue_back(cola)] = data;
		return cola;
	}
	else if(queue_front(cola) == queue_back(cola) && queue_back(cola) == MAX_QUEUE-1){
		queue_data(cola)[0] = data;
		queue_back(cola) = 0;
		return cola;
	}
	else if(queue_front(cola) == -1 || queue_back(cola) == -1){
		queue_data(cola)[0] = data;
		queue_back(cola) = 0;
		queue_front(cola) = 0;
		return cola;
	}
	int i = queue_back(cola);
	i++;	
	if(queue_front(cola) == i)
		return cola;
	if( queue_front(cola) > queue_back(cola))
		queue_data(cola)[++queue_back(cola)] = data;

	return cola;
}
Queue *queue_dequeue(Queue *cola)
{
	if(cola == NULL)
		return cola;
	else if(queue_front(cola) == -1 || queue_back(cola) == -1) {
		queue_front(cola) = -1;
		queue_back(cola) = -1;
	}
	else if(queue_front(cola) != queue_back(cola) && queue_front(cola) == MAX_QUEUE-1)
		queue_front(cola) = 0;
	else if(queue_front(cola) != queue_back(cola) && queue_front(cola) < MAX_QUEUE-1)
		queue_front(cola)++;
	else if(queue_front(cola) == queue_back(cola)){
		queue_front(cola) = -1;
		queue_back(cola) = -1;
	}
	
	return cola;
}

void queue_print(Queue *cola)
{
	if(cola == NULL || queue_front(cola) == -1 || queue_back(cola) == -1) {
		printf("La cola esta vacia.\n");	return;
	}
	else if(queue_front(cola) > queue_back(cola)) {
		int i;
		for(i = queue_front(cola) ; i < MAX_QUEUE ; i++)
			printf("%d ",queue_data(cola)[i]);
		if(queue_back(cola) == MAX_QUEUE-1){
			puts("");
			return;
		}
		for(i = 0;i <= queue_back(cola); i++)
			printf("%d ",queue_data(cola)[i]);
		puts("");
		return;
	}
	else if(queue_front(cola) <= queue_back(cola)){
		int i;
		for(i = queue_front(cola); i <= queue_back(cola) ; i++)
			printf("%d ",queue_data(cola)[i]);
	}
	puts("");
	return;
}

void queue_destroy(Queue *cola)
{
	free(cola);
}
