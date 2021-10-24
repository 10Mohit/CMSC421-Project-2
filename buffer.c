#include<linux/kernel.h>
#include<linux/syscalls.h>
#include<linux/slab.h>
#include "buffer.h"

ring_buffer_421_t *rb;
node_421_t * nodes;

long init_buffer_421(void){
    int i;
    nodes = kmalloc(SIZE_OF_BUFFER * sizeof(node_421_t),GFP_KERNEL);

    if(rb != NULL){
	    return -1;
    }
    for(i = 0; i<SIZE_OF_BUFFER; i++){
        nodes[i%SIZE_OF_BUFFER].data = 0;
        nodes[i%SIZE_OF_BUFFER].next = &nodes[(i+1)%SIZE_OF_BUFFER];
    }
    rb = (ring_buffer_421_t *) kmalloc(sizeof(ring_buffer_421_t),GFP_KERNEL);

    rb->length = 0;
    rb->read = &nodes[0];
    rb->write = &nodes[0];

    return 0;
}

long insert_buffer_421(int i){
    if( rb == NULL){
        return -1;
    }

    if( rb->length == SIZE_OF_BUFFER){
        return -1;
    }

    rb->write->data = i;
    rb->length++;
    rb->write = rb->write->next;

    return 0;
}

long print_buffer_421(void){
    int i=0;
    if(rb == NULL){
        return -1;
    }
    do{
        printk("\n node %d => data:%d",i,rb->read->data);
        rb->read = rb->read->next;
	i=i+1;
    }while(i<SIZE_OF_BUFFER);)
    return 0;
}


long delete_buffer_421(void){
    if(rb == NULL){
        return -1;
    }   
    kfree(nodes);
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
