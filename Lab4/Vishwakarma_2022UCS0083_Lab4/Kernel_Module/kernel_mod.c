#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
int simple_init(void);
void simple_exit(void);

int simple_init(void)
{
  printk(KERN_INFO "Loading Module\n");
  return 0;
}


void simple_exit(void)
{ 
  printk(KERN_INFO "Exiting Module\n");
  return;
}


module_init(simple_init);
module_exit(simple_exit);

 MODULE_LICENSE("MIT");
MODULE_DESCRIPTION("A LOG MODULE");
MODULE_AUTHOR("ASHUTOSH VISHWAKARMA");
