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

#ifndef OVR_TIME_WINDOW_H
#define OVR_TIME_WINDOW_H

#include "OVR_Platform_Defs.h"

/// \file
/// How far should we go back in time looking at history.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrTimeWindow_ {
  ovrTimeWindow_Unknown,
  ovrTimeWindow_OneHour,
  ovrTimeWindow_OneDay,
  ovrTimeWindow_OneWeek,
  ovrTimeWindow_ThirtyDays,
  ovrTimeWindow_NinetyDays,
} ovrTimeWindow;

/// Converts an ::ovrTimeWindow enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrTimeWindow_ToString(ovrTimeWindow value);

/// Converts a string representing an ::ovrTimeWindow to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrTimeWindow) ovrTimeWindow_FromString(const char* str);

#endif
