#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__


typedef struct _Node {
   void* a_value;
   struct _Node* next;
} Node;


Node* pq_enqueue(Node** a_head, void* a_value, int (*cmp_fn)(const void*, const void*));

                       
Node* pq_dequeue(Node** a_head);


Node* stack_push(Node** a_head, void* a_value);

                       
Node* stack_pop(Node** a_head);


void destroy_list(Node** a_head, void (*destroy_value_fn)(void*));

 
#endif

#define PRIORITY_QUEUE_H_V2
