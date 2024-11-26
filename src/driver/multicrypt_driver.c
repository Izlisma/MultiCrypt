#include <linux/module.h>
#include <linux/kernel.h>

MODULE_NAME("multicrypt");
MODULE_DESCRIPTION("MultiCrypt - an open source encrypted filesystem management software");
MODULE_AUTHOR("Humzak711 && SynclonSec");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");

static int __init constructor(void)
{

}

static void __exit destructor(void)
{

}

module_init(constructor);
module_exit(destructor);