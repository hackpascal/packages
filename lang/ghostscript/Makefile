#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ghostscript
PKG_VERSION:=9.06
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://downloads.ghostscript.com/public/$(PKG_SOURCE)
PKG_MD5SUM:=153ddb0622cb155d2f600146f1e28d84

include $(INCLUDE_DIR)/package.mk

define Package/ghostscript
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=An interpreter for the PostScript language and for PDF
  URL:=http://ghostscript.com/
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  DEPENDS:=+libcups +libcupsimage +libijs +libtiff +libjpeg +libpng +liblcms2 +zlib
endef

define Package/ghostscript/description
  Ghostscript is an interpreter for PostScript and Portable Document
  Format (PDF) files. It is available both under the GNU GPL Affero license
  and for commercial licensing from Artifex. It has been under active
  development for over 20 years and has been ported to many different systems
  during this time.

  Ghostscript consists of a PostScript interpreter layer, and a graphics
  library. Sometimes the Ghostscript graphics library is confusingly also
  referred to simply as Ghostscript. Even more confusingly, sometimes people
  say Ghostscript when they really mean GhostPDL.
endef

CONFIGURE_ARGS += \
	--enable-cups \
	--enable-dynamic \
	--disable-dbus \
	--disable-compile-inits \
	--disable-gtk \
	--disable-contrib \
	--disable-fontconfig \
	--disable-freetype \
	--with-system-libtiff \
	--with-install-cups \
	--with-ijs \
	--without-x \
	--without-omni \
	--without-luratech \
	--without-libidn \
	--without-libpaper \
	--without-jasper \
	--without-jbig2dec  \
	--with-cups-serverbin="/usr/lib/cups" \
	--with-cups-serverroot="/etc/cups" \
	--with-cups-datadir="/usr/share/cups" \
	HOSTCC=$(HOSTCC)

define Build/Configure
	$(RM) -rf $(PKG_BUILD_DIR)/{expat,jasper,freetype,jpeg,ijs,lcms2,lcms,libpng,tiff,zlib}
	$(call Build/Configure/Default)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		$(TARGET_CONFIGURE_OPTS) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		TARGET_ARCH_FILE=$(ARCH)-arch.h \
		all install
endef

define Package/ghostscript/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/* $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/* $(1)/usr/lib/cups/filter

	$(INSTALL_DIR) $(1)/usr/share/cups/model
	$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/model/* $(1)/usr/share/cups/model

	$(INSTALL_DIR) $(1)/usr/share/ghostscript/$(PKG_VERSION)/lib
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/lib/* $(1)/usr/share/ghostscript/$(PKG_VERSION)/lib

	$(INSTALL_DIR) $(1)/usr/share/ghostscript/$(PKG_VERSION)/iccprofiles
	$(CP) -a $(PKG_BUILD_DIR)/iccprofiles/* $(1)/usr/share/ghostscript/$(PKG_VERSION)/iccprofiles/

	$(INSTALL_DIR) $(1)/usr/share/ghostscript/$(PKG_VERSION)/Resource
	$(CP) -a $(PKG_BUILD_DIR)/Resource/{CIDFont,ColorSpace,Decoding,Encoding,Init,SubstCID} $(1)/usr/share/ghostscript/$(PKG_VERSION)/Resource/

	$(INSTALL_DIR) $(1)/usr/share/ghostscript/$(PKG_VERSION)/Resource/{CIDFSubst,CMap,Font}

	$(INSTALL_DIR) $(1)/etc/cups
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/etc/cups/gstoraster.convs $(1)/etc/cups
endef

$(eval $(call BuildPackage,ghostscript))
