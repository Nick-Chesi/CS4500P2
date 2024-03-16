#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/pid.h>

// Holding target pid
int target_pid = 0;
// Expose target_pid as module param
module_param(target_pid, int, 0);

static int __init partThreeInit(void) {
    struct task_struct *task;
    struct pid *pidStruct;

    // Check if the pid exists else terminate
    pidStruct = find_get_pid(target_pid);
    if (!pidStruct) {
        printk(KERN_ERR "CANNOT LOCATE PROCESS AT PID: %d\n", target_pid);
        return -1;
    }

    // Get the task structure for the specific PID, else terminate
        task = pid_task(pidStruct, PIDTYPE_PID);
    if (!task) {
        printk(KERN_ERR "UNABLE TO LOCATE PROCESS AT PID: %d\n", target_pid);
        return -1;
    }

    // Iterate through the process and its parents until init process
    for (; task != &init_task; task = task->real_parent) {
        printk(KERN_INFO "Process Name: %s\n", task->comm);
        printk(KERN_INFO "PID: %d\n", task->pid);
        printk(KERN_INFO "Process State: %ld\n", task->state);
    }

    // init process info
    printk(KERN_INFO "Process: %s, PID: %d, State: %ld\n", init_task.comm, init_task.pid, init_task.state);
    return 0;
}

static void __exit partThreeExit(void) {
    printk(KERN_INFO "GOODBYE FROM PART 3!\n");
}

// Registering modules
module_init(partThreeInit);
module_exit(partThreeExit);

MODULE_LICENSE("GPL");
