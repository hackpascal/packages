#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cndrvcups-capt-ppds
PKG_VERSION:=2.70
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_MD5SUM:=8217f7cf80bd71c172c44ada920b20dc

PKG_BUILD_DEPENDS:=cndrvcups-capt

include $(INCLUDE_DIR)/package.mk

define Package/cndrvcups-capt-ppds
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=PPD files for Canon i-Sensys series laser printers
  DEPENDS:=+cndrvcups-capt
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  PKGARCH:=all
endef

define Package/cndrvcups-capt-ppds/description
  PPD files for Canon i-Sensys series laser printers
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/cndrvcups-capt-ppds/install
	$(INSTALL_DIR) $(1)/usr/share/ppds/Canon
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(1)/usr/share/ppds/Canon
endef

$(eval $(call BuildPackage,cndrvcups-capt-ppds))
