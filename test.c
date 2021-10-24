#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>



#define __NR_init_buffer_421 442
#define __NR_insert_buffer_421 443
#define __NR_print_buffer_421 444
#define __NR_delete_buffer_421 445


long init_syscall(){
  return syscall(__NR_init_buffer_421);
}

long print_syscall(){
  return syscall(__NR_print_buffer_421);
}

long delete_syscall(){
  return syscall(__NR_delete_buffer_421);
}

long insert_syscall(int i){
  return syscall(__NR_insert_buffer_421,i);
}


int main(){
    int i;
    
    i = init_syscall();
    printf("\ninit_buffer success code: %d",i);
    i = print_syscall();
    i = insert_syscall(7);
    printf("\ninsert_buffer success code: %d",i);
    i = insert_syscall(8);
    printf("\ninsert_buffer success code: %d",i);
    i = insert_syscall(8);
    printf("\ninsert_buffer success code: %d",i);
    i = print_syscall();
    printf("\n print buffer success code: %d",i);
    i = delete_syscall();
    printf("\ndelete_buffer success code: %d",i);
    return 0;
}
