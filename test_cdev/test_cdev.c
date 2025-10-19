#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/ioctl.h>

#include "ioctl_test.h"

#define MAJOR 0

static int major;

static int test_open(struct inode *inode, struct file *filp)
{
    pr_info("test_cdev - Major: [%d], Minor [%d]\n", imajor(inode), iminor(inode));
    return 0;
}

static int test_release(struct inode *inode, struct file *filp)
{
    pr_info("test_cdev - file is closed");
    return 0;
}

static long int test_ioctl(struct file *filp, unsigned cmd, unsigned long arg)
{
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = test_open,
    .release = test_release,
    .ioctl = test_ioctl
};

static int __init test_init(void)
{
    major = register_chrdev(MAJOR, "test_cdev", &fops);

    if (major < 0) {
        pr_err("test_cdev - failed to register test_cdev\n");
        return major;
    }

    pr_info("test_cdev - successfully registered device. Major: [%d]\n", major);
    return 0;
}

static void __exit test_exit(void)
{
    unregister_chrdev(major, "test_cdev");
    pr_info("test_cdev - successfully unregistered device\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MGWINST");
MODULE_DESCRIPTION("char device");
