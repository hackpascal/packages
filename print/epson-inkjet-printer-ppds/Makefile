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
PKG_MD5SUM:=70faef3377084974476f06c99395504b

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

define Build/Configure
endef

define Build/Compile
endef

define Package/epson-inkjet-printer-ppds/install
	$(INSTALL_DIR) $(1)/usr/share/ppds/Epson
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(1)/usr/share/ppds/Epson
endef

$(eval $(call BuildPackage,epson-inkjet-printer-ppds))
