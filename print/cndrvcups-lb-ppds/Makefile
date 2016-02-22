#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cndrvcups-lb-ppds
PKG_VERSION:=3.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_MD5SUM:=cf27ff1a6916d5552c089368543dedd7

PKG_BUILD_DEPENDS:=cndrvcups-lb

include $(INCLUDE_DIR)/package.mk

define Package/cndrvcups-lb-ppds
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=PPD files for Canon UFR II/ UFRII LT Printers
  DEPENDS:=+cndrvcups-lb
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  PKGARCH:=all
endef

define Package/cndrvcups-lb-ppds/description
  PPD files for Canon UFR II/ UFRII LT Printers
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/cndrvcups-lb-ppds/install
	$(INSTALL_DIR) $(1)/usr/share/ppds/Canon
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(1)/usr/share/ppds/Canon
endef

$(eval $(call BuildPackage,cndrvcups-lb-ppds))
