/*
 * (C) Copyright 2014 Chen-Yu Tsai <wens@csie.org>
 *
 * Configuration settings for the Allwinner A23 (sun8i) CPU
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * A23 specific configuration
 */

#ifdef CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_SUNXI
#endif

#ifdef CONFIG_MACH_SUN8I_H3
	#define CONFIG_SUNXI_USB_PHYS	4
#elif defined CONFIG_MACH_SUN8I_A83T
	#define CONFIG_SUNXI_USB_PHYS	3
#elif defined CONFIG_MACH_SUN8I_V3S
	#define CONFIG_SUNXI_USB_PHYS	1
#else
	#define CONFIG_SUNXI_USB_PHYS	2
#endif

#define CONFIG_BOOTCOMMAND   "sf probe 0 108000000; "      \
	"sf read 0x41000000 0x0F0000 0x010000; "  \
	"sf read 0x41010000 0x300000 0x800000; " \
	"bootz 0x41010000 - 0x41000000"

#define CONFIG_BOOTARGS      "console=ttyS2,115200 earlyprintk panic=5 rootwait mtdparts=spi32766.0:960k(uboot),64k(dtb),1M(background),1M(animation),8M(kernel),-(appendfs) root=/dev/ram0 rdinit=/init vt.global_cursor_default=0"

/*
 * Include common sunxi configuration where most the settings are
 */
#include <configs/sunxi-common.h>

#endif /* __CONFIG_H */
