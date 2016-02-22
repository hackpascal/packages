#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cndrvcups-lb
PKG_VERSION:=3.10
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/cndrvcups-lb
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Printer driver for Canon UFR II/ UFRII LT Printers
  DEPENDS:=+cndrvcups-common
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/cndrvcups-lb/description
  Printer driver for Canon UFR II/ UFRII LT Printers
endef

define Build/Prepare
	$(CP) -a ./src/* $(PKG_BUILD_DIR)/
endef

define Package/cndrvcups-lb/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pstoufr2cpca/filter/pstoufr2cpca $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/pstoufr2cpca-set-cups-filter-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,cndrvcups-lb))
