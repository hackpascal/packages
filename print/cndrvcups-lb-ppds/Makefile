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

define Package/cndrvcups-lb-ppds/config
config CNDRVCUPS_LB_PPDS_COMPILE
	bool "Compile ppd files"
	depends on PACKAGE_cndrvcups-lb-ppds
	default n
endef

define Build/Configure
endef

define Build/Compile
endef

define Build/Install
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/tmp-ppds/Canon
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(PKG_BUILD_DIR)/tmp-ppds/Canon

	if [ x$(CONFIG_CNDRVCUPS_LB_PPDS_COMPILE) = xy ]; then \
		ppdbc $(PKG_BUILD_DIR)/tmp-ppds $(PKG_BUILD_DIR)/cndrvcups-lb-ppds.ppdb; \
	fi
endef

define Package/cndrvcups-lb-ppds/install
	if [ x$(CONFIG_CNDRVCUPS_LB_PPDS_COMPILE) = xy ]; then \
		$(INSTALL_DIR) $(1)/usr/lib/cups/driver; \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/cndrvcups-lb-ppds.ppdb $(1)/usr/lib/cups/driver/cndrvcups-lb-ppds; \
	else \
		$(INSTALL_DIR) $(1)/usr/share/ppd/Canon; \
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/*.ppd $(1)/usr/share/ppd/Canon; \
	fi
endef

$(eval $(call BuildPackage,cndrvcups-lb-ppds))
