#include <linux/changeflag.h>
#include <stdbool.h>
#include <linux/kernel.h>
int flag=0;
asmlinkage int sys_changeflag(int schFlag){
	flag = schFlag;
	return flag;
}
