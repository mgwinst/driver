#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>

static int major;

static ssize_t test_read(struct file* f, char __user* u, size_t len, loff_t* offset)
{
    pr_info("test_cdev - read() is called\n");
    return 0;
}

static struct file_operations fops = {
    .read = test_read
};

static int __init test_init(void)
{
    major = register_chrdev(0, "test_cdev", &fops);
    if (major < 0) {
        pr_err("test_cdev - failed to register test_cdev\n");
        return major;
    }
    pr_info("successfully registered test_cdev - Device major number: [%d]\n", major);
    return 0;
}

static void __exit test_exit(void)
{
    unregister_chrdev(major, "test_cdev");
    pr_info("successfully unregistered test_cdev\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MGWINST");
MODULE_DESCRIPTION("Registering a char device");
