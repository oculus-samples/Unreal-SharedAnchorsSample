/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PRODUCT_H
#define OVR_PRODUCT_H

#include "OVR_Platform_Defs.h"
#include "OVR_Price.h"
#include "OVR_ProductType.h"

/// \file
/// The class that represents the product information for a specific IAP which
/// is available for purchase in your app. You can retrieve more information
/// about the product(s) by using their SKU with ovr_IAP_GetProductsBySKU()
typedef struct ovrProduct *ovrProductHandle;

/// The description for the product. The description should be meaningful and
/// explanatory to help outline the product and its features.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetDescription(const ovrProductHandle obj);

/// The formatted string for the ::ovrPriceHandle. This is the same value
/// stored in ::ovrPriceHandle.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetFormattedPrice(const ovrProductHandle obj);

/// The name of the product. This will be used as a the display name and should
/// be aligned with the user facing title.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetName(const ovrProductHandle obj);

/// The ::ovrPriceHandle of the product contains the currency code, the amount
/// in hundredths, and the formatted string representation.
OVRP_PUBLIC_FUNCTION(ovrPriceHandle) ovr_Product_GetPrice(const ovrProductHandle obj);

/// The unique string that you use to reference the product in your app. The
/// SKU is case-sensitive and should match the SKU reference in your code.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetSKU(const ovrProductHandle obj);

/// The type of product. An In-app purchase (IAP) add-on can be
/// ovrProductType_DURABLE(), ovrProductType_CONSUMABLE(), or a
/// ovrProductType_SUBSCRIPTION().
OVRP_PUBLIC_FUNCTION(ovrProductType) ovr_Product_GetType(const ovrProductHandle obj);


#endif
