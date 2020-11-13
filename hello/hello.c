/**
 * @file hello.c
 * @author jihongbin (jihongbin@phytium.com.cn)
 * @brief a simple kernel module:hello
 * @version 0.1
 * @date 2020-11-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <linux/init.h>
#include <linux/module.h>

static char *book_name = "hello world test";
module_param(book_name, charp, S_IRUGO);

static int book_num = 4000;
module_param(book_num, int, S_IRUGO);

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello World enter\n");
    printk(KERN_INFO "book name:%s\n",book_name);
    printk(KERN_INFO "book num:%d\n",book_num);

    return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "Hello World exit\n");
}
module_exit(hello_exit);

int add_integar(int a, int b)
{
    return a + b;
}

int sub_integar(int a, int b)
{
    return a - b;
}

EXPORT_SYMBOL_GPL(add_integar);
EXPORT_SYMBOL_GPL(sub_integar);

MODULE_AUTHOR("jihongbin <jihongbin@phytium.com.cn>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("A simplest module");