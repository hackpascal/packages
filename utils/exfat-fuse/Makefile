#
# exFAT filesystem driver Makefile
#
# Written by Weijie Gao (hackapscal@gmail.com)
#

include $(TOPDIR)/rules.mk

PKG_NAME:=exfat
PKG_VERSION:=1.2.1
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://github.com/relan/exfat.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=b7953e251b0aec68cdd056ddafd2d4c17b338b8b
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/exfat/common
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Filesystem
  URL:=https://github.com/relan/exfat
endef

define Package/exfat
$(Package/exfat/common)
  TITLE:=FUSE-based exFAT Filesystem Driver
  DEPENDS:=+libfuse
endef

define Package/exfat/description
  A full-featured exFAT file system implementation for GNU/Linux and other Unix-like systems as a FUSE module and a set of utilities.
endef

define Package/exfat-utils
$(Package/exfat/common)
  TITLE:=Utilities for exFAT Filesystem
endef

define Package/exfat-utils/config
	source "$(SOURCE)/Config.in"
endef

TARGET_CFLAGS+=$(TARGET_CPPFLAGS) -std=c99 -fPIC

define Package/exfat/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fuse/mount.exfat-fuse $(1)/sbin/mount.exfat-fuse
	ln -s mount.exfat-fuse $(1)/sbin/mount.exfat
endef

define Package/exfat-utils/install
	$(INSTALL_DIR) $(1)/sbin
	if [ "$(CONFIG_PACKAGE_EXFAT_DUMP)" == "y" ]; then $(INSTALL_BIN) $(PKG_BUILD_DIR)/dump/dumpexfat $(1)/sbin/dumpexfat; fi
	if [ "$(CONFIG_PACKAGE_EXFAT_FSCK)" == "y" ]; then \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/fsck/exfatfsck $(1)/sbin/exfatfsck; \
		ln -s exfatfsck $(1)/sbin/fsck.exfat; \
	fi
	if [ "$(CONFIG_PACKAGE_EXFAT_LABEL)" == "y" ]; then $(INSTALL_BIN) $(PKG_BUILD_DIR)/label/exfatlabel $(1)/sbin/exfatlabel; fi
	if [ "$(CONFIG_PACKAGE_EXFAT_MKFS)" == "y" ]; then \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/mkfs/mkexfatfs $(1)/sbin/mkexfatfs; \
		ln -s mkexfatfs $(1)/sbin/mkfs.exfat; \
	fi
endef

$(eval $(call BuildPackage,exfat))
$(eval $(call BuildPackage,exfat-utils))
