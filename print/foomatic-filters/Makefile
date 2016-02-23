#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=foomatic-filters
PKG_VERSION:=4.0.17

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.openprinting.org/download/foomatic/$(PKG_SOURCE)
PKG_MD5SUM:=b05f5dcbfe359f198eef3df5b283d896

include $(INCLUDE_DIR)/package.mk

define Package/foomatic-filters
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Foomatic printing filters
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  DEPENDS:=+ghostscript
  URL:=https://www.openprinting.org/
endef

define Package/foomatic-filters/description
  Foomatic is a database-driven system for integrating free software printer
  drivers with common spoolers under Unix. It supports CUPS, LPRng, LPD,
  GNUlpr, Solaris LP, PPR, PDQ, CPS, and direct printing with every free
  software printer driver known to us and every printer known to work with
  these drivers.

  The universal print filter "foomatic-rip", used by spoolers to convert
  PostScript job data into the printer's native format as described by a
  printer/driver-specific PPD file.
endef

CONFIGURE_ARGS += \
	--disable-file-converter-check \
	--disable-dbus

define Build/Configure
	$(call Build/Configure/Default)
endef

define Package/foomatic-filters/install
	$(INSTALL_DIR) $(1)/etc/foomatic/direct
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/filter.conf $(1)/etc/foomatic

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/foomatic-rip $(1)/usr/bin
	
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/foomatic-rip $(1)/usr/lib/cups/filter/foomatic-rip

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/foomatic-filters-set-cups-filter-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,foomatic-filters))
