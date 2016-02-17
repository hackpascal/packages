#
# Copyright (C) 2007-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=w8021x
PKG_VERSION:=1.0.0
PKG_RELEASE:=1

PKG_MAINTAINER:=Weijie Gao <hackpascal@gmail.com>

include $(INCLUDE_DIR)/package.mk

define Package/w8021x
  SECTION:=net
  CATEGORY:=Network
  DEPENDS:=+wpa-cli
  TITLE:=Wired 802.1X AUthentication
endef

define Package/w8021x/description
  Scripts used for wired 802.1X authentication
endef

define Build/Compile
endef

define Package/w8021x/install
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) ./src/etc/config/w8021x $(1)/etc/config/
	$(INSTALL_BIN) ./src/etc/init.d/w8021x $(1)/etc/init.d/
	$(INSTALL_BIN) ./src/usr/sbin/* $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,w8021x))
