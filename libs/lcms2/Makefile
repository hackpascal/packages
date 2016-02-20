#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=lcms2
PKG_VERSION:=2.7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/lcms
PKG_MD5SUM:=06c1626f625424a811fb4b5eb070839d

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/lcms2
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Little CMS color engine
  DEPENDS:=+liblcms2
  URL:=http://www.littlecms.com/
endef

define Package/lcms2/description
  An OPEN SOURCE small-footprint color management engine, with special
  focus on accuracy and performance. It uses the International Color
  Consortium standard (ICC), which is the modern standard when regarding to
  color management. The ICC specification is widely used and is referred to
  in many International and other de-facto standards. It was approved as an
  International Standard, ISO 15076-1, in 2005.
endef

define Package/liblcms2
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Little CMS color engine - Core library
  DEPENDS:=+libtiff +libjpeg +zlib
  URL:=http://www.littlecms.com/
endef

dePackage/liblcms2/description=$(Package/lcms2/description)

define Package/lcms2/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/* $(1)/usr/bin/
endef

define Package/liblcms2/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/{liblcms2.so,liblcms2.so.2,liblcms2.so.2.0.7} $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib
endef

$(eval $(call BuildPackage,lcms2))
$(eval $(call BuildPackage,liblcms2))
