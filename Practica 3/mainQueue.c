#include <stdio.h>
#include "Queue.h"



int main(int argc, char *argv[])
{
	Queue *cola = queue_create();
	cola = queue_enqueue(cola,4);
	cola = queue_enqueue(cola,4);
	cola = queue_enqueue(cola,4);

	cola = queue_enqueue(cola,5);
	cola = queue_enqueue(cola,5);
	cola = queue_enqueue(cola,5);
	
	cola = queue_enqueue(cola,6);
	cola = queue_enqueue(cola,6);
	cola = queue_enqueue(cola,6);
	
	cola = queue_enqueue(cola,7);
	cola = queue_enqueue(cola,7);
	cola = queue_enqueue(cola,7);

	cola = queue_enqueue(cola,8);
	cola = queue_enqueue(cola,8);
	cola = queue_enqueue(cola,8);
	
	cola = queue_enqueue(cola,9);
	cola = queue_enqueue(cola,9);
	cola = queue_enqueue(cola,9);
	
	cola = queue_enqueue(cola,1);
	cola = queue_enqueue(cola,1);
	cola = queue_enqueue(cola,1);
	
	printf("front %d - back %d\n",queue_front(cola),queue_back(cola));
	
	queue_print(cola);
	
	cola = queue_dequeue(cola);
	cola = queue_dequeue(cola);
	cola = queue_dequeue(cola);
	cola = queue_dequeue(cola);
	
	printf("front %d - back %d\n",queue_front(cola),queue_back(cola));
		
	queue_print(cola);

	cola = queue_enqueue(cola,9);
	cola = queue_enqueue(cola,8);
	cola = queue_enqueue(cola,7);

	printf("front %d - back %d\n",queue_front(cola),queue_back(cola));
		
	queue_print(cola);
//	printf("%d %d \n",queue_data(cola)[0],queue_data(cola)[1]);
	queue_destroy(cola);
	return 0;
}
