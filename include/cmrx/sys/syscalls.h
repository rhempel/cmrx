/** @ingroup os_syscall
 * @{
 */

#pragma once

/** List of known syscall IDs.
 * These syscall IDs are known and can be used to call services.
 */
enum eSysCalls {
	SYSCALL_GET_TID = 0,
	SYSCALL_SCHED_YIELD,
	SYSCALL_THREAD_CREATE,
	SYSCALL_MUTEX_INIT,
	SYSCALL_MUTEX_DESTROY,
	SYSCALL_MUTEX_UNLOCK,
	SYSCALL_MUTEX_TRYLOCK,
	SYSCALL_RPC_CALL,
	SYSCALL_RPC_RETURN,
	SYSCALL_THREAD_JOIN,
	SYSCALL_THREAD_EXIT,
	SYSCALL_SETITIMER,
	SYSCALL_USLEEP,
	SYSCALL_SIGNAL,
	SYSCALL_KILL,
	SYSCALL_SETPRIORITY,
	SYSCALL_RESET,
	SYSCALL_NOTIFY_OBJECT,
	SYSCALL_WAIT_FOR_OBJECT,
	SYSCALL_ENABLE_IRQ,
	SYSCALL_DISABLE_IRQ,
	SYSCALL_CPUFREQ_GET,
	SYSCALL_GET_MICROTIME,
	SYSCALL_SHUTDOWN,
	_SYSCALL_COUNT
};

/** @} */
