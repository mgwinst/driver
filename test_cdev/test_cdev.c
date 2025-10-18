#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major;

static struct file_operations fops = {};

static int __init test_init(void)
{
    major = register_chrdev(0, "test_cdev", &fops);
    if (major < 0) {
        printk("test_cdev - failed to register test_cdev\n");
        return major;
    }
    printk("successfully registered test_cdev - Device major number: [%d]\n", major);
    return 0;
}

static void __exit test_exit(void)
{
    unregister_chrdev(major, "test_cdev");
    printk("successfully unregistered test_cdev\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MGWINST");
MODULE_DESCRIPTION("Registering a char device");
