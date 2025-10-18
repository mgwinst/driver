#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>

static int major;

static int test_open(struct inode *inode, struct file *filp)
{
    pr_info("test_cdev - Major: [%d], Minor [%d]\n", imajor(inode), iminor(inode));
    pr_info("test_cdev - filep->f_mode 0x%x\n",filp->f_mode);
    pr_info("test_cdev - filep->f_flags 0x%x\n",filp->f_flags);

    return 0;
}

static int test_release(struct inode *inode, struct file *filp)
{
    pr_info("test_cdev - file is closed");
    return 0;
}

static struct file_operations fops = {
    .open = test_open,
    .release = test_release
};

static int __init test_init(void)
{
    major = register_chrdev(0, "test_cdev", &fops);

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
MODULE_DESCRIPTION("Registering a char device");
