#
# Copyright (C) 2006-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jre
PKG_VERSION:=8u131
PKG_RELEASE:=1
PKG_MAINTAINER:=Weijie Gao <hackpascal@gmail.com>

JAVA_ARCH=$(if $(filter x86_64,$(ARCH)),x64,i586)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-linux-$(JAVA_ARCH).tar.gz
PKG_SOURCE_URL:=http://download.oracle.com/otn-pub/java/jdk/$(PKG_VERSION)-b11/d54c1d3a095b4ff2b6607d096fa80163
PKG_MD5SUM:=$(if $(filter x64,$(JAVA_ARCH)),9864b3b90840a2bc4604fba513e87453,c88bb459288ee336a0f6109be169bc8c)

JAVA_SO_DIR=$(if $(filter x86_64,$(ARCH)),amd64,i386)

export WGET_OPTIONS = --header "Cookie: oraclelicense=accept-securebackup-cookie"

include $(INCLUDE_DIR)/package.mk

define Package/jre
  SUBMENU:=Java
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=Oracle Java Runtime Environment
  URL:=https://www.java.com/en/
  DEPENDS:=@TARGET_x86||TARGET_x86_64 @USE_GLIBC +glib2 +libstdcpp +libxml2 +libxslt +libffmpeg-mini +libfreetype +libfontconfig +alsa-lib
endef

define Package/jre/description
  Oracle Java Runtime Environment. x86 and x86_64 only.
endef

define Build/Prepare
	tar -zxf $(DL_DIR)/$(PKG_SOURCE) -C $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/jre/install
	$(INSTALL_DIR) $(1)/usr/lib/java
	$(CP) -a $(PKG_BUILD_DIR)/jre1.8.0_131 $(1)/usr/lib/java/
	rm $(1)/usr/lib/java/jre1.8.0_131/lib/$(JAVA_SO_DIR)/libavplugin-{53,54,55}.so
	rm $(1)/usr/lib/java/jre1.8.0_131/lib/$(JAVA_SO_DIR)/libavplugin-ffmpeg-56.so

	$(INSTALL_DIR) $(1)/usr/lib/java/fakelibs
	touch $(1)/usr/lib/java/fakelibs/{libGL.so.1,libX11.so.6,libXext.so.6,libXi.so.6,libXrender.so.1,libXtst.so.6,libXxf86vm.so.1}
	touch $(1)/usr/lib/java/fakelibs/{libatk-1.0.so.0,libcairo.so.2,libgtk-x11-2.0.so.0}
	touch $(1)/usr/lib/java/fakelibs/{libgdk-x11-2.0.so.0,libgdk_pixbuf-2.0.so.0}
	touch $(1)/usr/lib/java/fakelibs/{libpango-1.0.so.0,libpangocairo-1.0.so.0,libpangoft2-1.0.so.0}

	$(INSTALL_DIR) $(1)/etc/profile.d
	$(INSTALL_BIN) ./files/jre-profile $(1)/etc/profile.d/10-jre.sh
endef

$(eval $(call BuildPackage,jre))
