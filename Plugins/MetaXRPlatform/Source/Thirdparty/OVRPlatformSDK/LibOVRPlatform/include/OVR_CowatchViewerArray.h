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

#ifndef OVR_COWATCHVIEWERARRAY_H
#define OVR_COWATCHVIEWERARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_CowatchViewer.h"
#include <stdbool.h>
#include <stddef.h>

/// \file
/// Represents a paginated list of ::ovrCowatchViewerHandle elements. It allows
/// you to easily access and manipulate the elements in the paginated list,
/// such as the size of the list and if there is a next page of elements
/// available.
typedef struct ovrCowatchViewerArray *ovrCowatchViewerArrayHandle;

/// Access the indexed element in this list. Note that the index is zero-based,
/// so the first element has an index of 0.
OVRP_PUBLIC_FUNCTION(ovrCowatchViewerHandle) ovr_CowatchViewerArray_GetElement(const ovrCowatchViewerArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_CowatchViewerArray_GetNextUrl(const ovrCowatchViewerArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_CowatchViewerArray_GetSize(const ovrCowatchViewerArrayHandle obj);

/// Indicates whether there is a next page of elements that can be retrieved.
/// If this value is true, you can use the next_url field to request the next
/// page of elements.
OVRP_PUBLIC_FUNCTION(bool) ovr_CowatchViewerArray_HasNextPage(const ovrCowatchViewerArrayHandle obj);


#endif
