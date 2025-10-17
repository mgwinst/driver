#include <linux/module.h>
#include <linux/init.h>

static int test_init(void)
{
    printk("hello from the kernel!\n");
    return 0;
}

static void test_exit(void)
{
    printk("goodbye from the kernel!\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
