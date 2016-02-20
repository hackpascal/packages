#
# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cups
PKG_VERSION:=2.1.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-source.tar.bz2
PKG_SOURCE_URL:= http://www.cups.org/software/$(PKG_VERSION)
PKG_MD5SUM:=c4e57a66298bfdba66bb3d5bedd317a4

include $(INCLUDE_DIR)/package.mk

define Package/cups/Default
  URL:=http://www.cups.org/
endef

define Package/cups
$(call Package/cups/Default)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libcups +libcupsmime +libcupscgi +libcupsppdc +libusb-1.0 +libdbus
  TITLE:=Common UNIX Printing System (daemon)
endef

define Package/cups/description
	Common UNIX Printing System (daemon)
endef

define Package/cups/conffiles
/etc/cups/classes.conf
/etc/cups/cupsd.conf
/etc/cups/printers.conf
endef

define Package/cups-bsd
$(call Package/cups/Default)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libcups
  TITLE:=Common UNIX Printing System - BSD commands (old)
endef

define Package/cups-bsd/description
	Common UNIX Printing System - BSD commands (old)
endef

define Package/cups-client
$(call Package/cups/Default)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libcups +libcupsimage +libcupsmime
  TITLE:=Common UNIX Printing System - Client commands
endef

define Package/cups-client/conffiles
/etc/cups/client.conf
endef

define Package/cups-client/description
	Common UNIX Printing System - Client commands
endef

define Package/cups-filters
$(call Package/cups/Default)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libcupsimage
  TITLE:=Common UNIX Printing System - Filter
endef

define Package/cups-filters/description
	Common UNIX Printing System - Filter
endef

define Package/cups-ppdc
$(call Package/cups/Default)
  SECTION:=print
  CATEGORY:=Printing and Imaging
  DEPENDS:=+libcupsppdc
  TITLE:=Common UNIX Printing System - PPDC utils
endef

define Package/cups-ppdc/description
	Common UNIX Printing System - PPDC utils
endef

define Package/libcups
$(call Package/cups/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+zlib +libpthread +libpng +libjpeg
  TITLE:=Common UNIX Printing System - Core library
endef

define Package/libcups/description
	Common UNIX Printing System - Core library
endef

define Package/libcupscgi
$(call Package/cups/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libcups
  TITLE:=Common UNIX Printing System - CGI library
endef

define Package/libcupscgi/description
	Common UNIX Printing System - CGI library
endef

define Package/libcupsimage
$(call Package/cups/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libcups +libpng +libjpeg
  TITLE:=Common UNIX Printing System - Image library
endef

define Package/libcupsimage/description
	Common UNIX Printing System - Image library
endef

define Package/libcupsmime
$(call Package/cups/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libcups
  TITLE:=Common UNIX Printing System - MIME library
endef

define Package/libcupsmime/description
	Common UNIX Printing System - MIME library
endef

define Package/libcupsppdc
$(call Package/cups/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libcups +libstdcpp
  TITLE:=Common UNIX Printing System - PPDC library
endef

define Package/libcupsppdc/description
	Common UNIX Printing System - PPDC library
endef

define Build/Configure
	$(call Build/Configure/Default, \
		--with-cups-user="nobody" \
		--with-cups-group="nogroup" \
		--with-pdftops="none" \
		--with-dbusdir=/etc/dbus-1 \
		--with-components="embedded" \
		--without-perl \
		--without-python \
		--without-php \
		--without-java \
		--enable-shared \
		--enable-image \
		--enable-libusb \
		--enable-threads \
		--enable-debug \
		--disable-dbus \
		--disable-ssl \
		--disable-gnutls \
		--disable-dnssd \
		--disable-launchd \
		--disable-systemd \
		--disable-ldap \
		--disable-pam \
		--disable-slp \
		--disable-openssl \
		--disable-cdsassl \
		--disable-gssapi \
		--disable-tiff, \
		UNAME="Linux" \
		LIBS="$(TARGET_LDFLAGS) -lz -lpng -ljpeg" \
	)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		$(TARGET_CONFIGURE_OPTS) \
		DSTROOT="$(PKG_INSTALL_DIR)" \
		STRIP="/bin/true" \
		all install
endef

define Package/cups/install
	rm -rf $(1)/etc/cups
	$(INSTALL_DIR) $(1)/etc/cups
	$(CP) $(PKG_INSTALL_DIR)/etc/cups/* $(1)/etc/cups/
	rm -rf $(1)/etc/cups/certs
	ln -sf /tmp $(1)/etc/cups/certs
	rm -f $(1)/usr/bin/cups-config
	$(INSTALL_DIR) $(1)/usr/lib/cups
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/backend $(1)/usr/lib/cups
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/cgi-bin $(1)/usr/lib/cups
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/daemon $(1)/usr/lib/cups
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/driver $(1)/usr/lib/cups
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/monitor $(1)/usr/lib/cups
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/{commandtops,pstops} \
		$(PKG_INSTALL_DIR)/usr/lib/cups/filter/gziptoany \
		$(1)/usr/lib/cups/filter
	$(INSTALL_DIR) $(1)/usr/share/cups/templates
	$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/templates/*.tmpl \
		$(1)/usr/share/cups/templates/
	$(INSTALL_DIR) $(1)/usr/share/cups/mime
	$(CP) $(PKG_INSTALL_DIR)/usr/share/cups/mime/* $(1)/usr/share/cups/mime/
	$(INSTALL_DIR) $(1)/usr/share/doc/cups
	$(CP) $(PKG_INSTALL_DIR)/usr/share/doc/cups/index.html \
		$(1)/usr/share/doc/cups/
	$(CP) $(PKG_INSTALL_DIR)/usr/share/doc/cups/*.css \
		$(1)/usr/share/doc/cups/
	$(CP) $(PKG_INSTALL_DIR)/usr/share/doc/cups/images \
		$(1)/usr/share/doc/cups/
	$(INSTALL_DIR) $(1)/usr/sbin
	# overwrite default config with our own
	$(CP) ./files/etc/cups/* $(1)/etc/cups/
	# install initscript with priority 60
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/cupsd.init $(1)/etc/init.d/cupsd
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/usr/sbin/{cupsctl,cupsd} \
		$(1)/usr/sbin/
	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/etc/uci-defaults/set-cups-backends-permission $(1)/etc/uci-defaults/
endef

define Package/cups-bsd/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/{lprm,lpq,lpr} $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/lpc $(1)/usr/sbin/
endef

define Package/cups-client/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/usr/bin/{lp,cancel,cupstestppd,cupstestdsc} \
		$(PKG_INSTALL_DIR)/usr/bin/{ipptool,lpoptions,lpstat,lppasswd} \
		$(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/usr/sbin/{cupsaccept,cupsaddsmb,cupsfilter} \
		$(PKG_INSTALL_DIR)/usr/sbin/{lpadmin,lpinfo,lpmove} \
		$(1)/usr/sbin/
	(cd $(1)/usr/sbin; ln -sf cupsaccept accept; ln -sf cupsaccept cupsenable; ln -sf cupsaccept cupsdisable; ln -sf cupsaccept reject; ln -sf cupsaccept cupsreject;)
endef

define Package/cups-filters/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/cups/filter/{rastertodymo,rastertoepson,rastertohp,rastertolabel,rastertopwg} \
		$(1)/usr/lib/cups/filter
	(cd $(1)/usr/lib/cups/filter; ln -sf rastertolabel rastertodymo;)
endef

define Package/cups-ppdc/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/usr/bin/{ppdc,ppdhtml,ppdi,ppdmerge,ppdpo} \
		$(1)/usr/bin/
endef

define Package/libcups/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcups.so* $(1)/usr/lib/
endef

define Package/libcupscgi/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcupscgi.so* $(1)/usr/lib/
endef

define Package/libcupsimage/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcupsimage.so* $(1)/usr/lib/
endef

define Package/libcupsmime/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcupsmime.so* $(1)/usr/lib/
endef

define Package/libcupsppdc/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcupsppdc.so* $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(2)/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/cups-config $(2)/bin/
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/cups $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcups*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,cups))
$(eval $(call BuildPackage,libcups))
$(eval $(call BuildPackage,libcupscgi))
$(eval $(call BuildPackage,libcupsimage))
$(eval $(call BuildPackage,libcupsmime))
$(eval $(call BuildPackage,libcupsppdc))
$(eval $(call BuildPackage,cups-bsd))
$(eval $(call BuildPackage,cups-client))
$(eval $(call BuildPackage,cups-filters))
$(eval $(call BuildPackage,cups-ppdc))
