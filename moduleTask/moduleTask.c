#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/fs.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("THP");

static char *filename = "default_file.txt";
static unsigned int interval = 5;
static struct timer_list custom_timer;
static struct file *file;

module_param(filename, charp, 0644);
MODULE_PARM_DESC(filename, "Output filename");

module_param(interval, uint, 0644);
MODULE_PARM_DESC(interval, "Timer interval in seconds");

void timer_func(struct timer_list *timer)
{
	char message[100] = "Hello from kernel module\n";
    
	if (file) {
		printk(KERN_INFO "Writing to file: %s", message);
		kernel_write(file, message, strlen(message), 0);
	}

	mod_timer(&custom_timer, jiffies + msecs_to_jiffies(interval * 1000));
}

static int __init task_module_init(void)
{
	printk(KERN_INFO "Task Module: Initialization\n");

	file = filp_open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (!file) {
		printk(KERN_ALERT "Task Module: Failed to open file\n");
		return -ENOENT;
	}

	timer_setup(&custom_timer, timer_func, 0);
	mod_timer(&custom_timer, jiffies + msecs_to_jiffies(interval * 1000));

	return 0;
}

static void __exit task_module_exit(void)
{
	printk(KERN_INFO "Task Module: Exit\n");

	if (file) filp_close(file, NULL);

	del_timer(&custom_timer);
}

module_init(task_module_init);
module_exit(task_module_exit);
