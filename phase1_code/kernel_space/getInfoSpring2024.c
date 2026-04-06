#include <linux/getInfoSpring2024.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>

asmlinkage int sys_getInfoSpring2024(struct structSpring2024 *data){
    //cli();  //close all kernel interrupts

    struct structSpring2024 kernelspacestructure;
    struct task_struct *current;

    copy_from_user(&kernelspacestructure, data, sizeof(struct structSpring2024));

    //kernelspacestructure.fieldofx = refferedpointerunderkernel->field;
    kernelspacestructure.pid = current->pid;
    kernelspacestructure.pid_parent = current->p_pptr->pid;
    kernelspacestructure.process_counter = current->counter;
    kernelspacestructure.nice = current->nice;
    kernelspacestructure.nice_parent = current->p_pptr->nice;
    kernelspacestructure.uid = current->uid;

    //if the flag value in the structure is a positive integer and it is smaller than or equal 24, otherwise returns -1.
    if(kernelspacestructure.flag <= 0){
        return -1;
    } else if(kernelspacestructure.flag > 24){
        if(kernelspacestructure.process_counter == 0){
            kernelspacestructure.weight = 0;
        } else {
            kernelspacestructure.weight = kernelspacestructure.process_counter + 20 - kernelspacestructure.nice;
        }
        return kernelspacestructure.weight;
    }

    printk(" process id: %ld\n process id of parent process: %ld\n counter value of the process: %ld\n nice value of the process: %ld\n nice value of parent process’s owner: %ld\n user id of process owner: %ld\n", 
        kernelspacestructure.pid, kernelspacestructure.pid_parent, kernelspacestructure.process_counter, kernelspacestructure.nice, kernelspacestructure.nice_parent, kernelspacestructure.uid);

    copy_to_user(data, &kernelspacestructure, sizeof(struct structSpring2024));

    //sti(); // start all kernel interrupts

    return 0;
}
