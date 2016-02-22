#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cndrvcups-common
PKG_VERSION:=3.40
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/cndrvcups-common
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Common printer driver module for Canon printers
  DEPENDS:=+libcups
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/cndrvcups-common/description
  Common printer driver module for Canon printers
endef

define Build/Prepare
	$(CP) -a ./src/* $(PKG_BUILD_DIR)/
endef

define Package/cndrvcups-common/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/backend
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/backend/cnusb $(1)/usr/lib/cups/backend/

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/cnusb-set-cups-backend-permission $(1)/etc/uci-defaults/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_BUILD_DIR)/buftool/{buflist.h,buftool.h} $(1)/usr/include/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/buftool/libbuftool.a $(1)/usr/lib/
endef

$(eval $(call BuildPackage,cndrvcups-common))
