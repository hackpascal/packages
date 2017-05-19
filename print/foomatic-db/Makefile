#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=foomatic-db
PKG_DATE:=20150819
PKG_VERSION:=4.0-$(PKG_DATE)

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.openprinting.org/download/foomatic/$(PKG_SOURCE)
PKG_MD5SUM:=b8049e61a3dad76044e83dde0087e0a0

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_DATE)

include $(INCLUDE_DIR)/package.mk

define Package/foomatic-db-ppds
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Foomatic database
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
  URL:=https://www.openprinting.org/
  PKGARCH:=all
endef

define Package/foomatic-db-ppds/description
  The collected knowledge about printers, drivers, and driver options in XML
  files, used to generate PPD files. It also contains manufacturer-supplied
  PPD files which got released under free software licenses.
endef

define Package/openprinting-ppds
$(call Package/foomatic-db-ppds)
  TITLE+= (for openprinting-cups-filters)
endef

Package/openprinting-ppds/description=$(Package/foomatic-db-ppds/description)

define Package/foomatic-db-ppds/config
config FOOMATIC_DB_PPDS_COMPILE
	bool "Compile ppd files"
	depends on PACKAGE_foomatic-db-ppds
	default n
endef

define Package/openprinting-ppds/config
config OPENPRINTING_PPDS_COMPILE
	bool "Compile ppd files"
	depends on PACKAGE_openprinting-ppds
	default n
endef

CONFIGURE_ARGS += \
	--with-drivers=NOOBSOLETES,NOEMPTYCMDLINE

define Build/Compile
	# Move files
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/ppds-openprinting
	$(CP) -a $(PKG_BUILD_DIR)/db/source/PPD/* $(PKG_BUILD_DIR)/ppds-openprinting

	# Remove non-PPD files from PPD repositories, CUPS 1.4 reports errors
	# on these files.
	-find $(PKG_BUILD_DIR)/ppds-openprinting -type f \! -name '*.ppd' -print0 | xargs -0 rm

	# Fix common errors in PPDs that make CUPS choke (OpenPrinting
	# bug #164, Debian bug #493104)
	for f in `find $(PKG_BUILD_DIR)/ppds-openprinting -name '*.ppd'`; do sed -i -e 's/^\*CloseUI\(\s+\)/*CloseUI:\1/' -e 's/\*1284DeviceId/*1284DeviceID/' $$$$f; done

	rm -rf $(PKG_BUILD_DIR)/db/source/PPD/*

	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR=$(PKG_INSTALL_DIR) install

	# Build PPD files
	FOOMATICDB=$(PKG_INSTALL_DIR)/usr/share/foomatic foomatic-compiledb -f -j `grep -c '^processor' /proc/cpuinfo` -t ppd -d $(PKG_BUILD_DIR)/ppds-foomatic-db `ls -1 $(PKG_INSTALL_DIR)/usr/share/foomatic/db/source/driver/*.xml | perl -p -e 's:^.*db/source/driver/(\S*)\.xml\s*$$:\1\n:'`

	if [ x$(CONFIG_FOOMATIC_DB_PPDS_COMPILE) = xy ]; then \
		ppdbc $(PKG_BUILD_DIR)/ppds-foomatic-db $(PKG_BUILD_DIR)/foomatic-db-ppds.ppdb; \
	fi

	if [ x$(CONFIG_OPENPRINTING_PPDS_COMPILE) = xy ]; then \
		ppdbc $(PKG_BUILD_DIR)/ppds-openprinting $(PKG_BUILD_DIR)/openprinting-ppds.ppdb; \
	fi
endef

define Build/Install
	# empty
endef

define Package/foomatic-db-ppds/install
	if [ x$(CONFIG_FOOMATIC_DB_PPDS_COMPILE) = xy ]; then \
		$(INSTALL_DIR) $(1)/usr/lib/cups/driver; \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/foomatic-db-ppds.ppdb $(1)/usr/lib/cups/driver/foomatic-db-ppds; \
	else \
		$(INSTALL_DIR) $(1)/usr/share/ppd; \
		$(CP) -a $(PKG_BUILD_DIR)/ppds-foomatic-db/* $(1)/usr/share/ppd; \
	fi
endef

define Package/openprinting-ppds/install
	if [ x$(CONFIG_OPENPRINTING_PPDS_COMPILE) = xy ]; then \
		$(INSTALL_DIR) $(1)/usr/lib/cups/driver; \
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/openprinting-ppds.ppdb $(1)/usr/lib/cups/driver/openprinting-ppds; \
	else \
		$(INSTALL_DIR) $(1)/usr/share/ppd; \
		$(CP) -a $(PKG_BUILD_DIR)/ppds-openprinting/* $(1)/usr/share/ppd; \
	fi
endef

$(eval $(call BuildPackage,foomatic-db-ppds))
$(eval $(call BuildPackage,openprinting-ppds))
