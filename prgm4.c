#include <stdio.h>

/* static storage: global array and static local inside a function */
int global_buf[5];         /* static allocation at program load */
void fill_print(void){
    static int local_buf[3];   /* also static: lifetime = whole program */
    for(int i=0;i<3;i++) local_buf[i]=10+i;
    for(int i=0;i<3;i++) printf("local[%d]=%d\n",i,local_buf[i]);
}

int main(void){
    for(int i=0;i<5;i++) global_buf[i]=i*2;
    for(int i=0;i<5;i++) printf("global[%d]=%d\n",i,global_buf[i]);
    puts("---");
    fill_print();
    return 0;
}
