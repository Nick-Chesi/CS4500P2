#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h> // Required for accessing task_struct

// Part 2 code:

int printSelfInit(){
        struct task_struct *task;

        printk(KERN_INFO "STARTING PART2 MODULE");

        // Iterate through the current process and its parents until init process
        for(task = current; task != &init_task; task = task->real_parent){
                printk(KERN_INFO "Process: %s PID: %d State: %ld\n", task->comm, task->pid, task->state);
        }

        // Print information about the init process
        printk(KERN_INFO "Process: %s PID: %d State: %ld\n", init_task.comm, init_task.pid, init_task.state);

        return 0;
}

void printSelfExit(){
        printk(KERN_INFO "LEAVING THE PART 2 MODULE!\n");
}

// Registering functions
module_init(printSelfInit);
module_exit(printSelfExit);

MODULE_LICENSE("GPL");
