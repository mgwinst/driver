#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x14\x00\x00\x00\x2f\x7a\x25\xa6"
	"complete\0\0\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x20\x00\x00\x00\xd7\x7e\xcc\x02"
	"__dma_request_channel\0\0\0"
	"\x18\x00\x00\x00\xf2\xa3\x0a\x52"
	"dma_alloc_attrs\0"
	"\x24\x00\x00\x00\x97\x70\x48\x65"
	"__x86_indirect_thunk_rax\0\0\0\0"
	"\x20\x00\x00\x00\xb5\x41\x87\x60"
	"__init_swait_queue_head\0"
	"\x24\x00\x00\x00\x0e\xd7\x3a\x4a"
	"wait_for_completion_timeout\0"
	"\x24\x00\x00\x00\x7c\xb2\x83\x63"
	"__x86_indirect_thunk_rdx\0\0\0\0"
	"\x18\x00\x00\x00\x53\x92\x94\x01"
	"dma_free_attrs\0\0"
	"\x1c\x00\x00\x00\x67\xbe\x89\x53"
	"dma_release_channel\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x18\x00\x00\x00\xeb\x7b\x33\xe1"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5D7E045502756A855F644FE");
