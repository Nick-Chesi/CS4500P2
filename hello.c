#include <linux/module.h>
#include <linux/kernel.h>
// Header files ^

int init_module(void){
        printk(KERN_INFO "HELLO WORLD! \n");
        return 0;
}

void cleanup_module(void){
        printk(KERN_INFO "GOODBYE WORLD! \n");
}

module_init(init_module);
module_exit(cleanup_module);

MODULE_LICENSE("GPL");
