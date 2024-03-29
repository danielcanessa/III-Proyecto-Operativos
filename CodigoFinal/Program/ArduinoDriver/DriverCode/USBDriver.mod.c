#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9412fa01, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa00a98b4, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x2a3a81eb, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xb6c371b5, __VMLINUX_SYMBOL_STR(usb_deregister_dev) },
	{ 0x853eb0f0, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x9ed4dc05, __VMLINUX_SYMBOL_STR(usb_register_dev) },
	{ 0x5fe56825, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x60e231b8, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0x6e938e79, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x6d0fc37d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xb749ae89, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xe8d95da6, __VMLINUX_SYMBOL_STR(usb_find_interface) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x28a7ca7b, __VMLINUX_SYMBOL_STR(usb_bulk_msg) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x123f0dc, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xec9526a6, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xef29303f, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0xb6ca0c88, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xfa0d5760, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0x2cf8b42f, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xfa55aab7, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v2341p0001d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "A536D4DA176136B6EC13164");
