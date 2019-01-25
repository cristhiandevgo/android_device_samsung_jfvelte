$(call inherit-product, device/samsung/jfvelte/full_jfvelte.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

PRODUCT_BUILD_PROP_OVERRIDES += \
  PRODUCT_NAME=jfvelte \
  TARGET_DEVICE=jfvelte

PRODUCT_DEVICE := jfvelte
PRODUCT_NAME := lineage_jfvelte
