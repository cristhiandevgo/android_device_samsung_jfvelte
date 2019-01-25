# Copyright (C) 2009 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# inherit from common jfve
include device/samsung/jfve-common/BoardConfigCommon.mk

# Assert
TARGET_OTA_ASSERT_DEVICE := jfvelte,jfveltexx,i9515,I9515,GT-I9515,GT-i9515,gt-i9515,I9515L,i9515L,i9515l,I9515l,gt-i9515l,GT-I9515L

# Vendor Init
TARGET_INIT_VENDOR_LIB := libinit_jfvelte
TARGET_LIBINIT_DEFINES_FILE := device/samsung/jfvelte/init/init_jfvelte.cpp
