#include<linux/kernel.h>
#include<linux/syscalls.h>
#include<linux/slab.h>
#include "buffer.h"

// #define SIZE_OF_BUFFER 20

// typedef struct node_421 {
// 	struct node_421 *next;
// 	int data;
// } node_421_t;

// typedef struct ring_buffer_421 {
//    int length;
//    node_421_t *read;
//    node_421_t *write;
// } ring_buffer_421_t;

ring_buffer_421_t *rb;
node_421_t * nodes;

long init_buffer_421(void){
    int i;
    nodes = kmalloc(SIZE_OF_BUFFER * sizeof(node_421_t),GFP_KERNEL);

    if(nodes == NULL){
	    return -1;
    }

    for(i = 0; i<SIZE_OF_BUFFER; i++){
        nodes[i%SIZE_OF_BUFFER].data = 0;
        nodes[i%SIZE_OF_BUFFER].next = &nodes[(i+1)%SIZE_OF_BUFFER];
    }
    // node_421_t *temp = &nodes[0];
    // for(int i = 0; i<2*SIZE_OF_BUFFER; i++){
    //     printf("%d",temp->data);
    //     temp = temp->next;
    // }
    // node_421_t *temp = &nodes[19];
    // printf("%d",temp->next->data);
    rb = (ring_buffer_421_t *) kmalloc(sizeof(ring_buffer_421_t),GFP_KERNEL);

    rb->length = 0;
    rb->read = &nodes[0];
    rb->write = &nodes[0];

    // sprintf("%ld",sizeof(nodes));
    return 0;
}

long insert_buffer_421(int i){
    if( rb == NULL){
        return -1;
    }
    //printf("%d",SIZE_OF_BUFFER);
    if( rb->length == SIZE_OF_BUFFER){
        return -1;
    }

    rb->write->data = i;
    rb->length++;
    rb->write = rb->write->next;

    return 0;
}

long print_buffer_421(void){
    int i;
    if( rb == NULL){
        return -1;
    }
    // printf("\nsize : %d",rb->length);
    // printf("\nfirst element : %d",rb->read->data);
    // printf("\nfirst element : %d",rb->read->next->next->data);
    for(i = 0; i<SIZE_OF_BUFFER; i++){
        printk("\n node %d => data:%d",i,rb->read->data);
        rb->read = rb->read->next;
    }
    return 0;
}


long delete_buffer_421(void){
    if( rb == NULL){
        return -1;
    }
    // node_421_t *temp;

    // for(int i = 0; i<SIZE_OF_BUFFER; i++){
    //     free(nodes[i].data);
    //     free(nodes[i].next);
    // }
    kfree(nodes);
    // free(rb->read);
    // // free(rb->length);
    // free(rb->write);
    kfree(rb);
    return 0;
}

SYSCALL_DEFINE0(init_buffer_421){
  return init_buffer_421();
}

SYSCALL_DEFINE0(print_buffer_421){
  return print_buffer_421();
}

SYSCALL_DEFINE0(delete_buffer_421){
  return delete_buffer_421();
}

SYSCALL_DEFINE1(insert_buffer_421,int, i){
  return insert_buffer_421(i);
}
/*
long sys_insert_buffer_421(int i){
  return insert_buffer_421(i);
}
/*
long sys_print_buffer_421(void){
return print_buffer_421();
}

long sys_delete_buffer_421(void){
return delete_buffer_421();
}
*/
