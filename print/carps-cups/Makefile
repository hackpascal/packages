#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=carps-cups
PKG_VERSION:=2015-05-11
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://github.com/ondrej-zary/carps-cups.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=eb47211bca1cb26a996fe2faad00da0fc55ff867
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz

include $(INCLUDE_DIR)/package.mk

define Package/carps-cups
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Driver for Canon CARPS printers
  DEPENDS:=+libcups +libcupsimage
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  URL:=https://github.com/ondrej-zary/carps-cups
endef

define Package/carps-cups/description
  Driver for Canon CARPS printers
endef

define Package/carps-cups/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rastertocarps $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/usr/share/ppd/Canon
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/ppd/*.ppd $(1)/usr/share/ppd/Canon/

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/rastertocarps-set-cups-filter-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,carps-cups))
