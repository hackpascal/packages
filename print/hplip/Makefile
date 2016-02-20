#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2015 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=hplip
PKG_VERSION:=3.15.7
PKG_RELEASE:=1

PKG_SOURCE:=hplip-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/hplip
PKG_MD5SUM:=13be6f818c4dd27518320b2b230c907f

ifneq ($(BUILD_VARIANT),prn)
PKG_BUILD_DEPENDS := libsane
endif

include $(INCLUDE_DIR)/package.mk

define Package/hplip/Default
  URL:=http://hplipopensource.com/
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/hplip
$(call Package/hplip/Default)
  TITLE:=HP Linux Imaging and Printing Drivers
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libhpip +libhpipp +libhpmud +libcups +libcupsimage +libjpeg +libstdcpp
  VARIANT:=default
endef

define Package/hplip-cups
$(call Package/hplip/Default)
  TITLE:=HP Linux Imaging and Printing Drivers (CUPS only)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libhpmud +libcups +libcupsimage +libjpeg +libstdcpp
  VARIANT:=prn
endef

define Package/hplip-full
$(call Package/hplip/Default)
  TITLE:=HP Linux Imaging and Printing Drivers (with data files)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libhpip +libhpipp +libhpmud +libcups +libcupsimage +libjpeg +libstdcpp
  VARIANT:=full
endef

define Package/hplip-python
$(call Package/hplip/Default)
  TITLE:=HP Linux Imaging and Printing Drivers (all files, large)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libhpip +libhpipp +libhpmud +libcups +libcupsimage +libjpeg +libstdcpp +python-light
  VARIANT:=full
endef

define Package/hplip/description
  HPLIP (Hewlett-Packard Linux Imaging & Printing) is an HP-developed
  solution for printing, scanning, and faxing with HP inkjet and laser
  based printers in Linux. The HPLIP project provides printing support
  for 2432 printer models, including Deskjet, Officejet, Photosmart,
  PSC (Print Scan Copy), Business Inkjet, LaserJet, Edgeline MFP, and
  LaserJet MFP. (Note: Not all models are currently supported. See
  Supported Printers for more information.)

  HPLIP is free, open source software distributed under the MIT, BSD,
  and GPL license.
endef

Package/hplip-cups/description=$(Package/hplip/description)
Package/hplip-full/description=$(Package/hplip/description)
Package/hplip-python/description=$(Package/hplip/description)

define Package/hplip/config
config HPLIP_PPDS_FILES
	bool "Add ppd files (very large)"
	depends on PACKAGE_hplip || PACKAGE_hplip-cups || PACKAGE_hplip-full || PACKAGE_hplip-python
	default n
endef

define Package/libhpip
$(call Package/hplip/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libhpmud
  TITLE:=HP OfficeJet image-processing library
endef

define Package/libhpip/description
	HP OfficeJet image-processing library
endef

define Package/libhpipp
$(call Package/hplip/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libhpmud
  TITLE:=HP CUPS IPP library
endef

define Package/libhpipp/description
	HP CUPS IPP library
endef

define Package/libhpmud
$(call Package/hplip/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libusb-1.0
  TITLE:=HP multi-point transport driver
endef

define Package/libhpmud/description
	HP multi-point transport driver
endef

CONFIGURE_ARGS += \
	_python_sysroot="$(STAGING_DIR)" \
	_python_prefix="/usr" \
	_python_exec_prefix="/usr" \
	--disable-doc-build \
	--enable-hpcups-install \
	--enable-new-hpcups \
	--disable-network-build \
	--disable-gui-build \
	--disable-dbus-build \
	--disable-fax-build \
	--enable-udev_sysfs_rules \
	--enable-cups-drv-install \
	--enable-cups-ppd-install \
	--disable-qt4 \
	--enable-policykit \
	--with-cupsbackenddir=/usr/lib/cups/backend \
	--with-cupsfilterdir=/usr/lib/cups/filter

ifeq ($(BUILD_VARIANT),prn)
CONFIGURE_ARGS += --disable-scan-build
endif

define Build/Configure
	$(call Build/Configure/Default)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		$(TARGET_CONFIGURE_OPTS) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

ifeq ($(CONFIG_HPLIP_PPDS_FILES),y)
define Package/hplip-ppds/install
	$(INSTALL_DIR) $(1)/usr/share/ppd
	$(CP) -a $(PKG_INSTALL_DIR)/usr/share/ppd/* $(1)/usr/share/ppd/
endef
else
define Package/hplip-ppds/install
endef
endif

define Package/hplip-cups/install
$(call Package/hplip-ppds/install, $(1))
	$(INSTALL_DIR) $(1)/etc/hp
	$(CP) $(PKG_INSTALL_DIR)/etc/hp/hplip.conf $(1)/etc/hp/hplip.conf
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_DIR) $(1)/usr/lib/cups/backend
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/backend/hp $(1)/usr/lib/cups/backend
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/hpcups $(1)/usr/lib/cups/filter
	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/hplip-set-cpus-backends-permission $(1)/etc/uci-defaults/
endef

define Package/hplip/install
$(call Package/hplip-cups/install, $(1))
	$(INSTALL_DIR) $(1)/etc/sane.d
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/etc/sane.d/dll.conf $(1)/etc/sane.d/dll.conf
	$(INSTALL_DIR) $(1)/usr/lib/sane
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/sane/*.so* $(1)/usr/lib/sane
endef

define Package/hplip-full/install
$(call Package/hplip/install, $(1))
	$(INSTALL_DIR) $(1)/usr/share/hplip/data/models/
	$(CP) $(PKG_INSTALL_DIR)/usr/share/hplip/data/models/models.dat $(1)/usr/share/hplip/data/models/
endef

define Package/hplip-python/install
$(call Package/hplip/install, $(1))
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/* $(1)/usr/bin/

	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/{hpps,pstotiff} $(1)/usr/lib/cups/filter

	$(CP) -a $(PKG_INSTALL_DIR)/usr/lib/python* $(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/share/cups/drv/hp
	$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/drv/hp/* $(1)/usr/share/cups/drv/hp/

	$(INSTALL_DIR) $(1)/usr/share/hplip/
	$(CP) -a $(PKG_INSTALL_DIR)/usr/share/hplip/* $(1)/usr/share/hplip/

endef

define Package/libhpip/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/libhpip*.so* $(1)/usr/lib
endef

define Package/libhpipp/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/libhpipp*.so* $(1)/usr/lib
endef

define Package/libhpmud/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/libhpmud*.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,hplip))
$(eval $(call BuildPackage,hplip-cups))
$(eval $(call BuildPackage,hplip-full))
$(eval $(call BuildPackage,hplip-python))
$(eval $(call BuildPackage,libhpip))
$(eval $(call BuildPackage,libhpipp))
$(eval $(call BuildPackage,libhpmud))
