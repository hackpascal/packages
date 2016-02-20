#
# Copyright (C) 2006-2016 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=qpdf
PKG_VERSION:=6.0.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_MD5SUM:=e014bd3ecf1c4d1a520bbc14d84ac20e

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/qpdf
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=A command-line program for transformations on PDF files
  DEPENDS:=+libqpdf
  URL:=http://qpdf.sourceforge.net/
endef

define Package/qpdf/description
  QPDF is a command-line program that does structural, content-preserving
  transformations on PDF files. It could have been called something like pdf-to-pdf.
  It also provides  many useful capabilities to developers of PDF-producing software
  or for people who just want to look at the innards of a PDF file to learn more
  about how they work.
endef

define Package/libqpdf
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=QPDF - Core library
  DEPENDS:= +libpcre +zlib +libstdcpp
  URL:=http://qpdf.sourceforge.net/
endef

Package/libqpdf/description=$(Package/qpdf/description)

CONFIGURE_ARGS += \
	--with-random=/dev/urandom

define Package/qpdf/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/* $(1)/usr/bin/
endef

define Package/libqpdf/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/{libqpdf.so,libqpdf.so.17,libqpdf.so.17.0.0} $(1)/usr/lib/
endef

define Build/Compile
	$(call Build/Compile/Default, LIBTOOL="./libtool --tag=CXX")
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/qpdf
	$(CP) $(PKG_INSTALL_DIR)/usr/include/qpdf/* $(1)/usr/include//qpdf/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libqpdf))
$(eval $(call BuildPackage,qpdf))
