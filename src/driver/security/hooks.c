#include "include/hooks.h"

int check_pid(pid_t pid) 
{   
    rcu_read_lock();
    struct task_struct task = *find_task_by_vpid(pid);
    rcu_read_unlock();
    if (task == NULL)
        return 0
    
    return strcmp(task->comm, MULTICRYPT_CLI_PROCESS_NAME) == 0;

}

original_syscall_t original_ptrace = NULL;
asmlinkage long multicrypt_ptrace(const struct pt_regs *registers)
{
    if (check_pid(registers->si))
        return -EINVAL;

    return original_ptrace(registers);
}

process_vm_rw_core_t original_process_vm_rw_core = NULL;
asmlinkage ssize_t multicrypt_process_vm_rw_core(pid_t pid, struct iov_iter *iter,
const struct iovec *rvec, unsigned long riovcnt, unsigned long flags, int vm_write)
{
    if (check_pid(pid))
        return -EINVAL;
        
    return original_process_vm_rw_core(pid, iter, rvec, riovcnt, flags, vm_write);
}