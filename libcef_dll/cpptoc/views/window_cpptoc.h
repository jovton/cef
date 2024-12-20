// Copyright (c) 2024 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=519bc28c076065156644994840f486d3390ccd3e$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_VIEWS_WINDOW_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_VIEWS_WINDOW_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/views/cef_browser_view_capi.h"
#include "include/capi/views/cef_view_capi.h"
#include "include/capi/views/cef_window_capi.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_view.h"
#include "include/views/cef_window.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefWindowCppToC
    : public CefCppToCRefCounted<CefWindowCppToC, CefWindow, cef_window_t> {
 public:
  CefWindowCppToC();
  virtual ~CefWindowCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_VIEWS_WINDOW_CPPTOC_H_
