/* Creating a virtual platform device */
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>

/* Specify the properties of the device and its layout to kernel */
/* Memory Region and Interrupt Lines etc can be specified as property */
/* In SoC the same is achieved using a device tree entry */

/* Run $cat /proc/iomem with root permissions to see currently used addresses */
/* Choose any unused address range and assign it to start and end fields */

/* After deploying module, this entry will appear in /proc/iomem with the device
   name, start and end addresses */ 
/* After deploying module, another entry will be created in /sys/devices/platform
   with a separate folder containing all the details of this device */ 
static struct resource pdev_resources[] = 
{
  {
    .start = 0x10000000,
    .end   = 0x10010000,
    .flags = IORESOURCE_MEM,
    .name  = "virtual platform device"
  },
  {
    .start = 5,
    .end   = 5,
    .flags = IORESOURCE_IRQ,
    .name  = "irq",
  }
};

/* Allocate the Platform Device and bind it with its resource structure */ 
static struct platform_device pdev = {
  .name = "virtual_platform_device",
  .resource = pdev_resources,
  .num_resources = ARRAY_SIZE(pdev_resources),
};

static int __init platform_device_init(void)
{
  pr_info("%s\r\n",__func__);
  /* Register the platform device with the platform core */
  platform_device_register(&pdev);
  return 0;
}

static void __exit platform_device_exit(void)
{
  pr_info("%s\r\n",__func__);
  /* Unregister the platform device from the platform core */
  platform_device_unregister(&pdev);
}

module_init(platform_device_init);
module_exit(platform_device_exit);

MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Virtual Platform Device");
MODULE_LICENSE("GPL");
