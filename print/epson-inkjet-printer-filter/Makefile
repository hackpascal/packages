#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=epson-inkjet-printer-filter
PKG_VERSION:=1.0.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_MD5SUM:=9b50c8a1844b38d00bbb3f80e2b1ea24

PKG_INSTALL:=1

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/epson-inkjet-printer-filter
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Epson Inkjet printer driver
  DEPENDS:=+libcups +libcupsimage +libjpeg +libstdcpp
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/epson-inkjet-printer-filter/description
  Epson Inkjet printer driver
endef

define Build/Configure
	chmod +x $(PKG_BUILD_DIR)/{config.guess,config.sub,configure,depcomp,install-sh,ltmain.sh,missing}
	$(call Build/Configure/Default)
endef

define Package/epson-inkjet-printer-filter/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/epson_inkjet_printer_filter $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/epson-inject-filter-set-cups-filter-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,epson-inkjet-printer-filter))
