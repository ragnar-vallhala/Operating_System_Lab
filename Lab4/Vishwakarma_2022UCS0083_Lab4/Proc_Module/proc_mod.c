#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

#define FILENAME "proc_mod_file"
#define CONTENT  "Hello from the Proc file!\n" 

/*
 * Function Signatures: The Compiler was throwing warning without these.
 */
static int create_mod(void);
static void remove_mod(void);


struct proc_dir_entry *proc_mod;

static ssize_t proc_mod_file_read(struct file *file, char *buf, size_t count, loff_t *pos)
{
    static int completed_reading = 0;
    if (completed_reading)
    {
        completed_reading = 0;  // Allow further reads after the first read
        return 0;
    }
    completed_reading = 1;

    size_t len = strlen(CONTENT);
    if (*pos >= len)
        return 0;

    if (count > len - *pos)
        count = len - *pos;

    if (copy_to_user(buf, CONTENT + *pos, count))
        return -EFAULT;

    *pos += count;
    return count;
}

static struct proc_ops proc_mod_file_ops = {.proc_read=proc_mod_file_read};

static int create_mod(void)
{
  proc_mod = proc_create(FILENAME,0666,NULL,&proc_mod_file_ops);
  if(!proc_mod)
  {
    printk(KERN_INFO "proc_mod failed to create %s.",FILENAME);
    return 1;
  }
  printk(KERN_INFO "proc_mod loaded and %s created.",FILENAME);
  return 0;
}

static void remove_mod(void)
{
  remove_proc_entry(FILENAME,NULL);

}


module_init(create_mod);
module_exit(remove_mod);

MODULE_LICENSE("MIT");
MODULE_DESCRIPTION("");
MODULE_AUTHOR("ASHUTOSH VISHWAKARMA");
