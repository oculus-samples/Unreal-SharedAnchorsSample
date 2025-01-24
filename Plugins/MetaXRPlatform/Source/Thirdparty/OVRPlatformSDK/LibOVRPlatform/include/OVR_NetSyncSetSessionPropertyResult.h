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

#ifndef OVR_NETSYNCSETSESSIONPROPERTYRESULT_H
#define OVR_NETSYNCSETSESSIONPROPERTYRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_NetSyncSession.h"

/// \file
/// A ::ovrNetSyncConnectionHandle allows multiple clients to connect and
/// communicate with each other in real-time. This is the payload from setting
/// the properties of ::ovrNetSyncSessionHandle. You can retrieve the result
/// session via ovr_NetSyncSetSessionPropertyResult_GetSession().
typedef struct ovrNetSyncSetSessionPropertyResult *ovrNetSyncSetSessionPropertyResultHandle;

/// It contains the ::ovrNetSyncSessionHandle that the operation was modifying.
OVRP_PUBLIC_FUNCTION(ovrNetSyncSessionHandle) ovr_NetSyncSetSessionPropertyResult_GetSession(const ovrNetSyncSetSessionPropertyResultHandle obj);


#endif
