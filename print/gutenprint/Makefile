#
# Copyright (C) 2006-2016 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gutenprint
PKG_MAJOR_VERSION:=5
PKG_MINOR_VERSION:=2
PKG_PATCH_VERSION:=11
PKG_VERSION:=$(PKG_MAJOR_VERSION).$(PKG_MINOR_VERSION).$(PKG_PATCH_VERSION)
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/gimp-print
PKG_MD5SUM:=fa6083535b7235fe531cd57e7345a81f

PKG_BUILD_DEPENDS:=gutenprint/host cups libiconv
HOST_BUILD_DEPENDS:=libiconv/host
PKG_INSTALL:=1

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/gutenprint
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Gutenprint CUPS drivers
  DEPENDS:=$(ICONV_DEPENDS) +libcups +libcupsimage +libgutenprint +libjpeg +libpng +libusb-1.0 +zlib
  URL:=http://gimp-print.sourceforge.net/
endef

define Package/gutenprint/description
  Gutenprint (formerlly gimp-print) CUPS drivers for a wide range of Canon, Epson, HP and
  compatible printers.
endef

define Package/libgutenprint
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Gutenprint CUPS drivers - Core library
  URL:=http://gimp-print.sourceforge.net/
endef

Package/libgutenprint/description=$(Package/gutenprint/description)

CONFIGURE_ARGS+= \
	--enable-shared \
	--disable-static \
	--disable-nls \
	--disable-test \
	--without-doc \
	--without-readline \
	--without-foomatic \
	--without-foomatic3 \
	--enable-escputil=no \
	--enable-test=no \
	--disable-translated-cups-ppds \
	--disable-globalized-cups-ppds \
	--enable-simplified-cups-ppds \
	--bindir=/usr/bin \
	--sbindir=/usr/bin \
	--prefix=/usr \
	--exec-prefix=/usr

define Build/Compile
	# Replace the cross-compiled "extract-string" by a shell-script that
	# runs the host's own compiled version (gutenprint needs to run this)
	(cd $(PKG_BUILD_DIR) && $(MAKE) -C src/xml extract-strings && \
	$(RM) src/xml/extract-strings && \
	echo '#!/bin/sh' > src/xml/extract-strings && \
	echo 'exec $(HOST_BUILD_DIR)/src/xml/extract-strings  "$$$$@" ' \
	>> src/xml/extract-strings && chmod +x src/xml/extract-strings && cp src/xml/extract-strings /tmp/)
	$(call Build/Compile/Default)
endef

define Package/gutenprint/install
	$(INSTALL_DIR) $(1)/etc/cups
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/etc/cups/command.types $(1)/etc/cups

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/cups-calibrate $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/cups-genppd.$(PKG_MAJOR_VERSION).$(PKG_MINOR_VERSION) $(1)/usr/sbin/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) -a $(PKG_INSTALL_DIR)/usr/lib/cups $(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/share/cups/usb
	$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/usb/net.sf.gimp-print.usb-quirks $(1)/usr/share/cups/usb/
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/share/cups/calibrate.ppm $(1)/usr/share/cups/

	$(INSTALL_DIR) $(1)/usr/share/gutenprint/
	$(CP) -a $(PKG_INSTALL_DIR)/usr/share/gutenprint/$(PKG_MAJOR_VERSION).$(PKG_MINOR_VERSION) $(1)/usr/share/gutenprint/
endef

define Package/libgutenprint/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/{libgutenprint.so,libgutenprint.so.2,libgutenprint.so.2.4.0} $(1)/usr/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/gutenprint
	$(CP) $(PKG_INSTALL_DIR)/usr/include/gutenprint/* $(1)/usr/include/gutenprint

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib
endef

define Host/Compile
  $(MAKE) $(HOST_JOBS) -C $(HOST_BUILD_DIR)/src/xml $(HOST_MAKE_FLAGS) extract-strings
endef

define Host/Install
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,gutenprint))
$(eval $(call BuildPackage,libgutenprint))
