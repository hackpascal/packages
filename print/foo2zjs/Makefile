#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=foo2zjs
PKG_VERSION:=2015-10-24

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar
PKG_SOURCE_URL:=https://www.openprinting.org/download/foomatic/$(PKG_NAME).tar.gz
PKG_MD5SUM:=638e8d4ce44c41328a87a383bbd36525

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/foo2zjs
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Printer drivers using foomatic on CUPS
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  URL:=http://foo2zjs.rkkda.com/
  DEPENDS:=+libcups +ghostscript
endef

define Package/foo2zjs/description
  foo2zjs is an open source printer driver for printers that use the
  Zenographics ZjStream wire protocol for their print data, such as the
  Minolta/QMS magicolor 2300 DL or Konica Minolta magicolor 2430 DL or
  HP LaserJet 1020 or HP LaserJet Pro P1102 or HP LaserJet Pro P1102w or
  HP LaserJet Pro CP1025nw. These printers are often erroneously referred to
  as winprinters or GDI printers. However, Microsoft GDI only mandates the API
  between an application and the printer driver, not the protocol on the wire
  between the printer driver and the printer. In fact, ZjStream printers are
  raster printers which happen to use a very efficient wire protocol which was
  developed by Zenographics and licensed by most major printer manufacturers
  for at least some of their product lines. ZjStream is just one of many wire
  protocols that are in use today, such as Postscript, PCL, Epson, etc.
endef

define Package/foo2zjs/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/usb_printerid $(1)/bin

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{foo2hbpl2-wrapper,foo2lava-wrapper,foo2slx-wrapper,foo2zjs-wrapper,foo2hiperc-wrapper} $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{foo2oak-wrapper,foo2xqx-wrapper,foo2hp2600-wrapper,foo2qpdl-wrapper,foo2zjs-pstops} $(1)/usr/bin

	$(INSTALL_DIR) $(1)/usr/share/cups/ppd-updaters
	$(INSTALL_DATA) ./files/printer-driver-foo2zjs-common.ppd-updater $(1)/usr/share/cups/ppd-updaters

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{arm2hpdl,foo2lava,foo2xqx,hbpldecode,opldecode,xqxdecode,foo2hbpl2,foo2oak,foo2zjs} $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{hipercdecode,qpdldecode,zjsdecode,foo2hiperc,foo2qpdl,lavadecode,slxdecode,foo2hp} $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{foo2slx,gipddecode,oakdecode} $(1)/usr/bin

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/icc2ps/foo2zjs-icc2ps $(1)/usr/bin

	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/command2foo2lava-pjl $(1)/usr/lib/cups/filter

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/foo2zjs-set-cups-filter-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,foo2zjs))
