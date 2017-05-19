#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=epson-inkjet-printer-ppds
PKG_VERSION:=2016-02-21
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_MD5SUM:=287aee16f1553f4e495c01ab12c816e4

include $(INCLUDE_DIR)/package.mk

define Package/epson-inkjet-printer-ppds
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=PPD files for Epson Inkjet printer driver
  DEPENDS:=+epson-inkjet-printer-filter
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  PKGARCH:=all
endef

define Package/epson-inkjet-printer-ppds/description
  PPD files for Epson Inkjet printer driver
endef

define Package/epson-inkjet-printer-ppds/config
config EPSON_INKJET_PRINTER_PPDS_COMPILE
	bool "Compile ppd files"
	depends on PACKAGE_epson-inkjet-printer-ppds
	default n
endef

define Build/Configure
endef

define Build/Compile
endef

define Build/Install
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/tmp-ppds/Epson
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(PKG_BUILD_DIR)/tmp-ppds/Epson

	if [ x$(CONFIG_EPSON_INKJET_PRINTER_PPDS_COMPILE) = xy ]; then \
		ppdbc $(PKG_BUILD_DIR)/tmp-ppds $(PKG_BUILD_DIR)/epson-inkjet-printer-ppds.ppdb; \
	fi
endef

define Package/epson-inkjet-printer-ppds/install
	if [ x$(CONFIG_EPSON_INKJET_PRINTER_PPDS_COMPILE) = xy ]; then \
		$(INSTALL_DIR) $(1)/usr/lib/cups/driver; \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/epson-inkjet-printer-ppds.ppdb $(1)/usr/lib/cups/driver/epson-inkjet-printer-ppds; \
	else \
		$(INSTALL_DIR) $(1)/usr/share/ppds/Epson; \
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(1)/usr/share/ppds/Epson; \
	fi
endef

$(eval $(call BuildPackage,epson-inkjet-printer-ppds))
