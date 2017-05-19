#
# Copyright (C) 2006-2009 OpenWrt.org
# Copyright (C) 2005-2016 Weijie Gao <hackpascal@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cndrvcups-capt
PKG_VERSION:=2.70
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/cndrvcups-capt-filters
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Filters for Canon i-Sensys series laser printers
  DEPENDS:=+cndrvcups-common
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/cndrvcups-capt-filters/description
  Printer driver for Canon i-Sensys series laser printers (filters)
endef

define Package/cndrvcups-capt-backend
  SECTION:=print
  CATEGORY:=Printing and Imaging
  TITLE:=Backend for Canon i-Sensys series laser printers
  DEPENDS:=+cndrvcups-common
  MAINTAINER:=Weijie Gao <hackpascal@gmail.com>
endef

define Package/cndrvcups-capt-backend/description
  Printer driver for Canon i-Sensys series laser printers (backend)
endef

define Build/Prepare
	$(CP) -a ./src/* $(PKG_BUILD_DIR)/
endef

define Package/cndrvcups-capt-filters/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/filter
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pstocapt/filter/pstocapt $(1)/usr/lib/cups/filter/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pstocapt2/filter/pstocapt2 $(1)/usr/lib/cups/filter/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pstocapt3/filter/pstocapt3 $(1)/usr/lib/cups/filter/

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/capt-set-cups-filters-permission $(1)/etc/uci-defaults/
endef

define Package/cndrvcups-capt-backend/install
	$(INSTALL_DIR) $(1)/usr/lib/cups/backend
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/backend/ccp $(1)/usr/lib/cups/backend/

	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_BIN) ./files/capt-set-cups-backend-permission $(1)/etc/uci-defaults/
endef

$(eval $(call BuildPackage,cndrvcups-capt-filters))
$(eval $(call BuildPackage,cndrvcups-capt-backend))
