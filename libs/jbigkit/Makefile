#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jbigkit
PKG_VERSION:=2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.cl.cam.ac.uk/~mgk25/jbigkit/download/
PKG_MD5SUM:=ebcf09bed9f14d7fa188d3bd57349522

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/jbigkit/Default
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://www.cl.cam.ac.uk/~mgk25/jbigkit/
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/jbigkit/description/Default
  JBIG-KIT provides a portable library of compression and decompression
  functions with a documented interface that you can include very easily
  into your image or document processing software. In addition, JBIG-KIT
  provides ready-to-use compression and decompression programs with a simple
  command line interface
endef

define Package/libjbig
$(call Package/jbigkit/Default)
  TITLE:=JBIG-KIT library
endef

Package/libjbig/description=$(Package/jbigkit/description/Default)

define Package/libjbig85
$(call Package/jbigkit/Default)
  TITLE:=JBIG-KIT library (light version)
endef

Package/libjbig85/description=$(Package/jbigkit/description/Default)

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) $(TARGET_CONFIGURE_OPTS) $(MAKE_VARS) lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_BUILD_DIR)/libjbig/{jbig.h,jbig85.h,jbig_ar.h} $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libjbig/{libjbig.a,libjbig.so,libjbig85.a,libjbig85.so} $(1)/usr/lib/
endef

define Package/libjbig/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libjbig/libjbig.so $(1)/usr/lib/
endef

define Package/libjbig85/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libjbig/libjbig85.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libjbig))
$(eval $(call BuildPackage,libjbig85))
