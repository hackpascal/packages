#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fxlinuxprint
PKG_VERSION:=1.0.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://download.fujixerox.co.jp/pub/exe/apeosport/c4300series/$(PKG_SOURCE_URL)
PKG_MD5SUM:=7045d505e6fcb4c4455a40163ed72709

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-src-$(PKG_VERSION)

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/fxlinuxprint
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=CUPS filter for Fuji Xerox printers
  DEPENDS:=+ghostscript
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  URL:=http://www.fujixerox.co.jp/download/apeosport/download/c4300series/linux_module.html
endef

define Package/fxlinuxprint/description
  CUPS filter and PPD file for the following Fuji Xerox printers
  ApeosPort-II C7500 / C6500 / C5400
  DocuCentre-II C7500 / C6500 / C5400
  ApeosPort-II C4300 / C3300 / C2200
  DocuCentre-II C4300 / C3300 / C2200
  ApeosPort-II 7000 / 6000 / 5000
  DocuCentre-II 7000 / 6000 / 5000
  ApeosPort-II 4000 / 3000
  DocuCentre-II 4000 / 3000
endef

define Package/fxlinuxprint/install
	$(INSTALL_DIR) $(1)/etc/cups
	$(CP) $(PKG_INSTALL_DIR)/etc/cups/* $(1)/etc/cups

	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/* $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/usr/share/ppd/FujiXerox
	$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/FujiXerox/en/fxlinuxprint.ppd $(1)/usr/share/ppd/FujiXerox

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/fxlinuxprint-set-cups-filters-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,fxlinuxprint))
