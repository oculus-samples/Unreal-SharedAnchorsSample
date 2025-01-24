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

#ifndef OVR_ORGSCOPEDID_H
#define OVR_ORGSCOPEDID_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// \file
/// An ID for a ::ovrUserHandle which is unique per Developer Center
/// organization. This ID allows different apps within the same org to be able
/// to identify the user. You can retrieve this ID by using
/// ovr_User_GetOrgScopedID().
typedef struct ovrOrgScopedID *ovrOrgScopedIDHandle;

/// The unique id of the ::ovrUserHandle in each organization, allowing
/// different apps within the same Developer Center organization to have a
/// consistent id for the same user.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_OrgScopedID_GetID(const ovrOrgScopedIDHandle obj);


#endif
