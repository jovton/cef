// Copyright (c) 2023 The Chromium Embedded Framework Authors. All rights
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
// $hash=952c6b775c3954a28e87a4c15625dcfa14829ec4$
//

#include "libcef_dll/ctocpp/preference_registrar_ctocpp.h"
#include "libcef_dll/ctocpp/value_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool CefPreferenceRegistrarCToCpp::AddPreference(
    const CefString& name,
    CefRefPtr<CefValue> default_value) {
  cef_preference_registrar_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, add_preference)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return false;
  }
  // Verify param: default_value; type: refptr_same
  DCHECK(default_value.get());
  if (!default_value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->add_preference(_struct, name.GetStruct(),
                                        CefValueCToCpp::Unwrap(default_value));

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefPreferenceRegistrarCToCpp::CefPreferenceRegistrarCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefPreferenceRegistrarCToCpp::~CefPreferenceRegistrarCToCpp() {}

template <>
cef_preference_registrar_t* CefCToCppScoped<CefPreferenceRegistrarCToCpp,
                                            CefPreferenceRegistrar,
                                            cef_preference_registrar_t>::
    UnwrapDerivedOwn(CefWrapperType type, CefOwnPtr<CefPreferenceRegistrar> c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
cef_preference_registrar_t* CefCToCppScoped<CefPreferenceRegistrarCToCpp,
                                            CefPreferenceRegistrar,
                                            cef_preference_registrar_t>::
    UnwrapDerivedRaw(CefWrapperType type, CefRawPtr<CefPreferenceRegistrar> c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppScoped<CefPreferenceRegistrarCToCpp,
                               CefPreferenceRegistrar,
                               cef_preference_registrar_t>::kWrapperType =
    WT_PREFERENCE_REGISTRAR;