#
# Copyright (C) 2006-2016 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=poppler
PKG_VERSION:=0.41.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://poppler.freedesktop.org/
PKG_MD5SUM:=849a8bd6af5794efb961b70418414e5a

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/poppler
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Poppler PDF rendering library
  DEPENDS:=+libpoppler +fontconfig
  URL:=http://poppler.freedesktop.org/
endef

define Package/poppler/description
  Poppler is a PDF rendering library based on the xpdf-3.0 code base.
endef

define Package/libpoppler
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Poppler PDF rendering library - Core library
  DEPENDS:=+libfontconfig +libjpeg +liblcms2 +libpng +libtiff +zlib +libstdcpp
  URL:=http://poppler.freedesktop.org/
endef

Package/libpoppler/description=$(Package/poppler/description)

CONFIGURE_ARGS += \
	--without-x \
	--disable-gtk-test \
	--disable-poppler-qt4 \
	--disable-poppler-qt5 \
	--disable-gtk-doc-html \
	--disable-cairo-output \
	--enable-gtk-doc-html=no \
	--enable-poppler-cpp \
	--enable-xpdf-headers \
	--enable-zlib \
	--enable-libjpeg \
	--enable-cms=lcms2 \
	--with-font-configuration=fontconfig

define Package/poppler/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/* $(1)/usr/bin/
endef

define Package/libpoppler/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/{libpoppler.so,libpoppler.so.58,libpoppler.so.58.0.0} $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/poppler
	$(CP) -a $(PKG_INSTALL_DIR)/usr/include/poppler/* $(1)/usr/include/poppler/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libpoppler))
$(eval $(call BuildPackage,poppler))
