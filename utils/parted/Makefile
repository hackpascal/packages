#
# Copyright (C) 2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=parted
PKG_VERSION:=3.2
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/parted-$(PKG_VERSION)
PKG_SOURCE:=parted-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=@GNU/parted
PKG_MD5SUM:=0247b6a7b314f8edeb618159fa95f9cb

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/parted
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=disc
  TITLE:=GNU Parted
  URL:=http://www.gnu.org/software/parted/
  DEPENDS:= +libparted +libreadline +libncurses
endef

define Package/parted/description
  GNU Parted manipulates partition tables. This is useful for creating 
  space for new operating systems, reorganizing disk usage, copying data 
  on hard disks and disk imaging. The package contains a library, 
  libparted, as well as well as a command-line frontend, parted, 
  which can also be used in scripts.
endef

define Package/libparted
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=GNU Parted - Core library
  URL:=http://www.gnu.org/software/parted/
  DEPENDS:= +libuuid +libblkid
endef

define Package/libparted-fs-resize
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=GNU Parted - Filesystem resize library
  URL:=http://www.gnu.org/software/parted/
endef

TARGET_CFLAGS += \
	$(if $(CONFIG_USE_MUSL),-Dloff_t=off_t)

CONFIGURE_ARGS += \
	--disable-device-mapper

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/parted
	$(CP) $(PKG_INSTALL_DIR)/usr/include/parted/*.h $(1)/usr/include/parted
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) -a $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

define Package/parted/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/{parted,partprobe} $(1)/usr/sbin/
endef

define Package/libparted/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/libparted.so* $(1)/usr/lib/
endef

define Package/libparted-fs-resize/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/libparted-fs-resize.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,parted))
$(eval $(call BuildPackage,libparted))
$(eval $(call BuildPackage,libparted-fs-resize))
