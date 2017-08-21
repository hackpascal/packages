#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vlmcsd
PKG_VERSION:=r1111
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://github.com/Wind4/vlmcsd.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=550df56794aa201fd2dd08153431ca20da2e6846
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

include $(INCLUDE_DIR)/package.mk

define Package/vlmcsd
  SECTION:=net
  CATEGORY:=Network
  TITLE:=KMS Server Emulator for Windows products
  DEPENDS:=+libpthread
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  URL:=https://github.com/Wind4/vlmcsd
endef

define Package/vlmcsd/description
  KMS Server Emulator
endef

define Package/vlmcsd/conffiles
/etc/config/vlmcsd
endef

define Package/vlmcsd/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bin/vlmcsd $(1)/usr/bin

	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/etc/vlmcsd.kmd $(1)/etc/vlmcsd.kmd

	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DATA) ./files/vlmcsd.uci $(1)/etc/config/vlmcsd

	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/vlmcsd.init $(1)/etc/init.d/vlmcsd
endef

$(eval $(call BuildPackage,vlmcsd))
