/* Creating a platform driver for the virtual platform device */
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>

/* Invoked when the device is connected to platform bus */
static int platdrv_probe(struct platform_device *pdev)
{
  pr_info("%s\r\n",__func__);
  return 0;
}

/* Invoked when the device is disconnected from platform bus */
static int platdrv_remove(struct platform_device *pdev)
{
  pr_info("%s\r\n",__func__);
  return 0;
}

/* Allocate the Platform Driver and bind it with the Virtual Platform Device */ 
static struct platform_driver platdrv = {
  .driver = {
    /* Must match the name of the virtual platform device */
    .name  = "virtual_platform_device",
    .owner = THIS_MODULE,
  },
  .probe  = platdrv_probe,
  .remove = platdrv_remove,
};

static int __init platform_driver_init(void)
{
  pr_info("%s\r\n",__func__);
  /* Register the platform driver with the platform core */
  platform_driver_register(&platdrv);
  return 0;
}

static void __exit platform_driver_exit(void)
{
  pr_info("%s\r\n",__func__);
  /* Unregister the platform driver from the platform core */
  platform_driver_unregister(&platdrv);
}

module_init(platform_driver_init);
module_exit(platform_driver_exit);

MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Platform Driver for Virtual Platform Device");
MODULE_LICENSE("GPL");
