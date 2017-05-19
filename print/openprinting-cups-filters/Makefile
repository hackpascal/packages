#
# Copyright (C) 2006-2016 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=openprinting-cups-filters
PKG_VERSION:=1.8.2
PKG_RELEASE:=1

PKG_SOURCE:=cups-filters-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://www.openprinting.org/download/cups-filters/
PKG_MD5SUM:=a32a83aef1808e4ccabad96a593a9f89
PKG_BUILD_DIR:=$(BUILD_DIR)/cups-filters-$(PKG_VERSION)

PKG_INSTALL:=1

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/openprinting-cups-filters
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=OpenPrinting CUPS filters - Filters
  DEPENDS:=+libcups +libcupsfilters +libfontembed +libfontconfig +glib2 +libijs +libpoppler +libqpdf +ghostscript
  URL:=http://www.openprinting.org
endef

define Package/openprinting-cups-filters/description
  CUPS filters maintained by OpenPrinting.
  The CUPS Filters package contains backends, filters and other software that
  was once part of the core CUPS distribution but is no longer maintained by
  Apple Inc.
endef

define Package/libcupsfilters
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=OpenPrinting CUPS filters - Core library
  DEPENDS:=+libcups +libcupsimage +libjpeg +libpng +libtiff +zlib
  URL:=http://www.openprinting.org
endef

Package/libcupsfilters/description=$(Package/openprinting-cups-filters/description)

define Package/libfontembed
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=OpenPrinting CUPS filters - Font embed library
  DEPENDS:=+libjpeg +libtiff
  URL:=http://www.openprinting.org
endef

define Package/openprinting-cups-backends
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=OpenPrinting CUPS filters - Backends
  DEPENDS:=+libcupsimage +libtiff
  URL:=http://www.openprinting.org
endef

define Package/openprinting-cups-backends/description
  Backends of OpenPrinting CUPS filters

  Including
    Backend error handler (BEH)
    Serial
    Parallel
    Implicitclass
endef

Package/libfontembed/description=$(Package/openprinting-cups-filters/description)

CONFIGURE_ARGS += \
	--enable-imagefilters \
	--enable-poppler-cpp \
	--with-pdftops=gs \
	--with-gs-path=/usr/bin/gs \
	--with-pdftops-path=/usr/bin/gs \
	--disable-gnutls \
	--disable-openssl \
	--disable-cdsassl \
	--disable-ssl \
	--disable-gssapi \
	--disable-avahi \
	--disable-dbus \
	--disable-foomatic

define Package/openprinting-cups-filters/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/ttfread $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/cups-browsed $(1)/usr/sbin/

	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/* $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/usr/share/cups/mime
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/share/cups/mime/* $(1)/usr/share/cups/mime/

	$(INSTALL_DIR) $(1)/usr/share/ppd/cupsfilters
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/share/ppd/cupsfilters/* $(1)/usr/share/ppd/cupsfilters/

	$(INSTALL_DIR) $(1)/etc/cups
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/etc/cups/cups-browsed.conf $(1)/etc/cups/

	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/cups-browsed.init $(1)/etc/init.d/cups-browsed

endef

define Package/libcupsfilters/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/{libcupsfilters.so,libcupsfilters.so.1,libcupsfilters.so.1.0.0} $(1)/usr/lib/
endef

define Package/libfontembed/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/{libfontembed.so,libfontembed.so.1,libfontembed.so.1.0.0} $(1)/usr/lib/
endef

define Package/openprinting-cups-backends/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/backend
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/backend/* $(1)/usr/lib/cups/backend/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libcupsfilters))
$(eval $(call BuildPackage,libfontembed))
$(eval $(call BuildPackage,openprinting-cups-filters))
$(eval $(call BuildPackage,openprinting-cups-backends))
