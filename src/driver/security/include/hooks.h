#ifndef _HOOKS_H_
#define _HOOKS_H_

/*
 * We will monitor certain API's to prevent patching/hooking
 * of the CLI's process in userland to protect against common attacks.
 *
 * We will not be providing protection against malicious kernel modules,
 * as at that point we will end up having to build a whole ass EDR solution 
 * just to protect the CLI lmao.
 */

#include <linux/ptrace.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/uio.h>
#include <linux/sched.h>
#include <linux/rcupdate.h>
#include <linux/errno.h>

#include "../../../pkg/shared_data.h"

int check_pid(pid_t pid);

typedef long (*original_syscall_t)(const struct pt_regs *);

typedef ssize_t (*process_vm_rw_core_t)(pid_t pid, struct iov_iter *iter,
				                        const struct iovec *rvec,
				                        unsigned long riovcnt,
				                        unsigned long flags, int vm_write);

extern original_syscall_t original_ptrace;
asmlinkage long multicrypt_ptrace(const struct pt_regs *regs);
                                    
extern process_vm_rw_core_t original_process_vm_rw_core;
asmlinkage ssize_t multicrypt_process_vm_rw_core(pid_t pid, struct iov_iter *iter,
const struct iovec *rvec, unsigned long riovcnt, unsigned long flags, int vm_write);

#endif