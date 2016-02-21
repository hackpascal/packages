#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=epson-alcx11-filter
PKG_VERSION:=1.1
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/epson-alcx11-filter
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Epson AL-CX11 printer driver
  DEPENDS:=+foomatic-filters
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  PKGARCH:=all
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/epson-alcx11-filter/install
	$(INSTALL_DIR) $(1)/usr/share/ppd/Epson
	$(INSTALL_DATA) ./files/Epson-AL-CX11-fm3.ppd $(1)/usr/share/ppd/Epson/
endef

$(eval $(call BuildPackage,epson-alcx11-filter))
