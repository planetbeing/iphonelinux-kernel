/*
 *  arch/arm/mach-apple_iphone/include/mach/usb.h
 *
 *  Copyright (C) 2008 Yiduo Wang
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef IPHONE_HW_USB_H
#define IPHONE_HW_USB_H

#include <mach/hardware.h>

#define POWER_USB 0x200

// Device
#define USB IO_ADDRESS(0x38400000)
#define USB_PHY IO_ADDRESS(0x3C400000)

// Registers
#define OPHYPWR 0
#define OPHYCLK 0x4
#define ORSTCON 0x8
#define GOTGCTL 0x0
#define GOTGINT 0x4
#define GAHBCFG 0x8
#define GUSBCFG 0xC
#define GRSTCTL 0x10
#define GINTSTS 0x14
#define GINTMSK 0x18
#define GRXFSIZ 0x24
#define GNPTXFSIZ 0x28
#define GNPTXFSTS 0x2C
#define DIEPMSK 0x810
#define DOEPMSK 0x814
#define DAINT 0x818
#define DAINTMSK 0x81C
#define USB_INREGS 0x900
#define USB_OUTREGS 0xB00

#define DCFG 0x800
#define DCTL 0x804
#define DSTS 0x808

#define USB_ENDPOINT_DIRECTIONS 0x44
#define USB_ONOFF 0xE00

// Values
#define USB_INTERRUPT 0x13

#define USB_OTGCLOCKGATE 0x2
#define USB_PHYCLOCKGATE 0x23
#define USB_ONOFF_OFF 3	// bits 0, 1

#define OPHYPWR_FORCESUSPEND 0x1
#define OPHYPWR_PLLPOWERDOWN 0x2
#define OPHYPWR_XOPOWERDOWN 0x4
#define OPHYPWR_ANALOGPOWERDOWN 0x8
#define OPHYPWR_UNKNOWNPOWERDOWN 0x10
#define OPHYPWR_POWERON 0x0	// all the previous flags are off

#define OPHYCLK_CLKSEL_MASK 0x3
#define OPHYCLK_CLKSEL_48MHZ 0x0
#define OPHYCLK_CLKSEL_12MHZ 0x2
#define OPHYCLK_CLKSEL_24MHZ 0x3

#define GOTGCTL_BSESSIONVALID (1 << 19)
#define GOTGCTL_SESSIONREQUEST (1 << 1)

#define ORSTCON_PHYSWRESET 0x1
#define ORSTCON_LINKSWRESET 0x2
#define ORSTCON_PHYLINKSWRESET 0x4

#define GAHBCFG_DMAEN (1 << 5)
#define GAHBCFG_BSTLEN_SINGLE (0 << 1)
#define GAHBCFG_BSTLEN_INCR (1 << 1)
#define GAHBCFG_BSTLEN_INCR4 (3 << 1)
#define GAHBCFG_BSTLEN_INCR8 (5 << 1)
#define GAHBCFG_BSTLEN_INCR16 (7 << 1)
#define GAHBCFG_MASKINT 0x1

#define GUSBCFG_TURNAROUND_MASK 0xF
#define GUSBCFG_TURNAROUND_SHIFT 10
#define GUSBCFG_HNPENABLE (1 << 9)
#define GUSBCFG_SRPENABLE (1 << 8)
#define GUSBCFG_PHYIF16BIT (1 << 3)
#define USB_UNKNOWNREG1_START 0x1708

#define GRSTCTL_AHBIDLE (1 << 31)
#define GRSTCTL_CORESOFTRESET 0x1

#define GINTMSK_NONE 0x0
#define GINTMSK_OTG (1 << 2)
#define GINTMSK_SOF (1 << 3)
#define GINTMSK_SUSPEND (1 << 11)
#define GINTMSK_RESET (1 << 12)
#define GINTMSK_EPMIS (1 << 17)
#define GINTMSK_INEP (1 << 18)
#define GINTMSK_OEP (1 << 19)
#define GINTMSK_DISCONNECT (1 << 29)

#define RX_FIFO_DEPTH 0x1C0
#define TX_FIFO_DEPTH 0x1C0
#define TX_FIFO_STARTADDR 0x200

#define GNPTXFSIZ_DEPTH_SHIFT 16

#define GNPTXFSTS_GET_TXQSPCAVAIL(x) GET_BITS(x, 16, 8)

#define DAINTMSK_ALL 0xFFFFFFFF
#define DAINTMSK_OUT_SHIFT 16
#define DAINTMSK_IN_SHIFT 0

#define DCTL_SFTDISCONNECT 0x2
#define DCTL_SETD0PID (1 << 28)
#define DCTL_PROGRAMDONE (1 << 11)
#define DCTL_CGOUTNAK (1 << 10)
#define DCTL_CGNPINNAK (1 << 8)
#define DCTL_NEXTEP_MASK 0xF
#define DCTL_NEXTEP_SHIFT 11

#define DSTS_GET_SPEED(x) GET_BITS(x, 1, 2)

#define DCFG_NZSTSOUTHSHK 0x1
#define DCFG_DEVICEADDR_UNSHIFTED_MASK 0x7F
#define DCFG_DEVICEADDR_SHIFT 4
#define DCFG_DEVICEADDRMSK (DCFG_DEVICEADDR_UNSHIFTED_MASK << DCFG_DEVICEADDR_SHIFT)


#define DOEPTSIZ0_SUPCNT_MASK 0x3
#define DOEPTSIZ0_SUPCNT_SHIFT 29
#define DOEPTSIZ0_PKTCNT_MASK 0x1
#define DEPTSIZ0_XFERSIZ_MASK 0x7F
#define DIEPTSIZ_MC_MASK 0x3
#define DIEPTSIZ_MC_SHIFT 29
#define DEPTSIZ_PKTCNT_MASK 0x3FF
#define DEPTSIZ_PKTCNT_SHIFT 19
#define DEPTSIZ_XFERSIZ_MASK 0x1FFFF

// ENDPOINT_DIRECTIONS register has two bits per endpoint. 0, 1 for endpoint 0. 1, 2 for end point 1, etc.
#define USB_EP_DIRECTION(ep) ((__raw_readl(USB + USB_ENDPOINT_DIRECTIONS) >> ((ep) * 2)) & 0x3)
#define USB_ENDPOINT_DIRECTIONS_BIDIR 0
#define USB_ENDPOINT_DIRECTIONS_IN 1
#define USB_ENDPOINT_DIRECTIONS_OUT 2

#define USB_START_DELAYMS 10
#define USB_RESET_DELAYUS 1000
#define USB_SFTDISCONNECT_DELAYMS 4
#define USB_ONOFFSTART_DELAYUS 100
#define USB_PHYPWRPOWERON_DELAYUS 10
#define USB_RESET2_DELAYUS 20
#define USB_RESETWAITFINISH_DELAYUS 1000
#define USB_SFTCONNECT_DELAYUS 250
#define USB_PROGRAMDONE_DELAYUS 10

#define USB_EPCON_ENABLE (1 << 31)
#define USB_EPCON_SETNAK (1 << 27)
#define USB_EPCON_CLEARNAK (1 << 26)
#define USB_EPCON_ACTIVE (1 << 15)
#define USB_EPCON_TYPE_MASK 0x3
#define USB_EPCON_TYPE_SHIFT 18
#define USB_EPCON_MPS_MASK 0x7FF

#define USB_EPINT_INEPNakEff 0x40
#define USB_EPINT_INTknEPMis 0x20
#define USB_EPINT_INTknTXFEmp 0x10
#define USB_EPINT_TimeOUT 0x8
#define USB_EPINT_AHBErr 0x4
#define USB_EPINT_EPDisbld 0x2
#define USB_EPINT_XferCompl 0x1

#define USB_EPINT_Back2BackSetup (1 << 6)
#define USB_EPINT_OUTTknEPDis 0x10
#define USB_EPINT_SetUp 0x8
#define USB_EPINT_EpDisbld 0x1
#define USB_EPINT_NONE 0
#define USB_EPINT_ALL 0xFFFFFFFF

#define USB_NUM_ENDPOINTS 6

#define USB_2_0 0x0200

#define USB_HIGHSPEED 0
#define USB_FULLSPEED 1
#define USB_LOWSPEED 2
#define USB_FULLSPEED_48_MHZ 3

#define USB_CONTROLEP 0

#endif
