#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=c2esp
PKG_VERSION:=27
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/cupsdriverkodak
PKG_MD5SUM:=dd63fb1aa1c551ecfd1f3c585b36db74

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/c2esp
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=CUPS driver for Kodak Aio
  URL:=http://sourceforge.net/projects/cupsdriverkodak/
  DEPENDS:=+libcupsfilters +libcupsimage +libjbig85
endef

define Package/c2esp/description
  CUPS filters and ppd files for the kodak ESP and Hero all in one printers on
  linux. Likely to work on all ESP and Hero printers
endef

CONFIGURE_ARGS += \
	--with-cupsfilterdir="/usr/lib/cups/filter" \
	--with-cupsdatadir="/usr/share/cups"

define Package/c2esp/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/* $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/usr/share/ppd/Kodak
	$(CP) $(PKG_BUILD_DIR)/ppd/*.ppd $(1)/usr/share/ppd/Kodak

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/c2esp-set-cups-filters-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,c2esp))
