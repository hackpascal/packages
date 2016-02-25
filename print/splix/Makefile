#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=splix
PKG_VERSION:=2.0.1.20130902svn
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/splix
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_MD5SUM:=2901e9482dd1a7c44f7b730696868e09
PKG_SOURCE_URL:=https://pkgs.fedoraproject.org/repo/pkgs/splix/$(PKG_SOURCE)/$(PKG_MD5SUM)/

include $(INCLUDE_DIR)/package.mk

define Package/splix
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=SPL printer driver for Unix
  URL:=http://pkgs.fedoraproject.org/cgit/splix.git/
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  DEPENDS:=+libjbig85 +libcups +libcupsimage +libpng +libtiff +libstdcpp
endef

define Package/splix/description
  Splix is a driver for printers that speak SPL (Samsung Printer Language). This includes printers made by Samsung, Dell, and Xerox
endef

define Package/splix/config
config SPLIX_PPDS_COMPILE
	bool "Compile ppd files"
	depends on PACKAGE_splix
	default n
endef

define Build/Configure
	$(SED) "s/^CC\t\t:= gcc/CC\t\t:= $(TARGET_CC)/" -e "s/^CXX\t\t:= g++/CXX\t\t:= $(TARGET_CXX)/" -e "s/^AR\t\t:= ar/AR\t\t:= $(TARGET_AR)/" $(PKG_BUILD_DIR)/Makefile
	$(SED) 's|\(.*\)toqpdl_LDFLAGS\t*:=.*|\1toqpdl_LDFLAGS\t:=$(TARGET_LDFLAGS) -lpthread|' -e 's|\(.*\)toqpdl_LIBS\t*:=.*|\1toqpdl_LIBS\t:=-lpng -ltiff -lcups -lcupsimage -ljbig85|' -e 's|^CXXFLAGS\t\t+= `cups.*|CXXFLAGS\t\t+= $(TARGET_CFLAGS) -Iinclude -Wall $(TARGET_CPPFLAGS)|' -e 's|CUPSFILTER\t*:=.*|CUPSFILTER\t:= /usr/lib/cups/filter|' -e 's|CUPSPPD\t*:=.*|CUPSPPD\t:= /usr/share/cups/model|' $(PKG_BUILD_DIR)/module.mk
	$(SED) 's|g++|$(TARGET_CXX)|' $(PKG_BUILD_DIR)/rules.mk
	mv $(PKG_BUILD_DIR)/*.ppd $(PKG_BUILD_DIR)/ppd/
endef

define Build/Compile
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR) $(MAKE_FLAGS) all
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR)/ppd $(MAKE_FLAGS) all	
endef

define Build/Install
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR) $(MAKE_INSTALL_FLAGS) install

	if [ x$(CONFIG_SPLIX_PPDS_COMPILE) = xy ]; then \
		ppdbc $(PKG_INSTALL_DIR)/usr/share/cups/model/ $(PKG_BUILD_DIR)/splix-ppds.ppdb; \
	fi
endef

define Package/splix/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/optimized/{pstoqpdl,rastertoqpdl} $(1)/usr/lib/cups/filter/

	if [ x$(CONFIG_SPLIX_PPDS_COMPILE) = xy ]; then \
		$(INSTALL_DIR) $(1)/usr/lib/cups/driver; \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/splix-ppds.ppdb $(1)/usr/lib/cups/driver/splix-ppds; \
	else \
		$(INSTALL_DIR) $(1)/usr/share/ppd/Dell; \
		$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/dell/*.ppd $(1)/usr/share/ppd/Dell; \
		$(INSTALL_DIR) $(1)/usr/share/ppd/Lexmark; \
		$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/lexmark/*.ppd $(1)/usr/share/ppd/Lexmark; \
		$(INSTALL_DIR) $(1)/usr/share/ppd/Samsung; \
		$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/samsung/*.ppd $(1)/usr/share/ppd/Samsung; \
		$(INSTALL_DIR) $(1)/usr/share/ppd/Toshiba; \
		$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/toshiba/*.ppd $(1)/usr/share/ppd/Toshiba; \
		$(INSTALL_DIR) $(1)/usr/share/ppd/Xerox; \
		$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/xerox/*.ppd $(1)/usr/share/ppd/Xerox; \
	fi

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/splix-set-cups-filters-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,splix))
