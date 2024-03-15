#include <linux/module.h>
#include <linux/kernel.h>
// Header files ^

// Renamed from init_module, was getting compiler issues
int helloModule(void){
        printk(KERN_INFO "HELLO WORLD! \n");
        return 0;
}

// Same as before, renamed from cleanup_module
void cleanupModule(void){
        printk(KERN_INFO "GOODBYE WORLD! \n");
}

// Added the corrected function names down here
module_init(helloModule);
module_exit(cleanupModule);

MODULE_LICENSE("GPL");
