/*
   Copyright (C) 2012 The Android Open-Source Project
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <android-base/properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include <string>

void gsm_properties();

using android::base::GetProperty;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void vendor_load_properties()
{
    std::string platform;
    std::string bootloader;

    platform = GetProperty("ro.board.platform", "");

    if (platform == "")
        return;

    bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("I9515") != std::string::npos) {
        /* jfveltexx */
        gsm_properties();
        property_override_dual("ro.build.fingerprint","ro.vendor.build.fingerprint","samsung/jfveltexx/jfvelte:5.0.1/LRX22C/I9515XXS1BQD2:user/release-keys");
        property_override("ro.build.description", "jfveltexx-user 5.0.1 LRX22C I9515XXS1BQD2 release-keys");
        property_override_dual("ro.product.model","ro.vendor.product.model","GT-I9515");
        property_override_dual("ro.product.device","ro.vendor.product.device", "jfveltexx");
    } else if (bootloader.find("I9515L") != std::string::npos) {
        /* jfvelteub */
        gsm_properties();
        property_override_dual("ro.build.fingerprint","ro.vendor.build.fingerprint", "samsung/jfvelteub/jfvelte:5.0.1/LRX22C/I9515LUBU1BQF1:user/release-keys");
        property_override("ro.build.description", "jfvelteub-user 5.0.1 LRX22C I9515LUBU1BQF1 release-keys");
        property_override_dual("ro.product.model","ro.vendor.product.model", "GT-I9515L");
        property_override_dual("ro.product.device","ro.vendor.product.device", "jfvelteub");
    } else {
        property_override("ro.build.fingerprint","ERROR.INIT FAILED");
    }
}

void gsm_properties()
{
    android::init::property_set("telephony.lteOnGsmDevice", "1");
    android::init::property_set("ro.telephony.default_network", "9");
    android::init::property_set("telephony.radioAccessFamily", "gsm");
}
