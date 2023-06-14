// Copyright (c) 2023 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=61099a1ba8b16a5e46f5a80d326d1f9bfc99317d$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_WINDOW_DELEGATE_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_WINDOW_DELEGATE_CAPI_H_
#pragma once

#include "include/capi/views/cef_panel_delegate_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_window_t;

///
/// Implement this structure to handle window events. The functions of this
/// structure will be called on the browser process UI thread unless otherwise
/// indicated.
///
typedef struct _cef_window_delegate_t {
  ///
  /// Base structure.
  ///
  cef_panel_delegate_t base;

  ///
  /// Called when |window| is created.
  ///
  void(CEF_CALLBACK* on_window_created)(struct _cef_window_delegate_t* self,
                                        struct _cef_window_t* window);

  ///
  /// Called when |window| is closing.
  ///
  void(CEF_CALLBACK* on_window_closing)(struct _cef_window_delegate_t* self,
                                        struct _cef_window_t* window);

  ///
  /// Called when |window| is destroyed. Release all references to |window| and
  /// do not attempt to execute any functions on |window| after this callback
  /// returns.
  ///
  void(CEF_CALLBACK* on_window_destroyed)(struct _cef_window_delegate_t* self,
                                          struct _cef_window_t* window);

  ///
  /// Called when |window| is activated or deactivated.
  ///
  void(CEF_CALLBACK* on_window_activation_changed)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window,
      int active);

  ///
  /// Called when |window| bounds have changed. |new_bounds| will be in DIP
  /// screen coordinates.
  ///
  void(CEF_CALLBACK* on_window_bounds_changed)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window,
      const cef_rect_t* new_bounds);

  ///
  /// Return the parent for |window| or NULL if the |window| does not have a
  /// parent. Windows with parents will not get a taskbar button. Set |is_menu|
  /// to true (1) if |window| will be displayed as a menu, in which case it will
  /// not be clipped to the parent window bounds. Set |can_activate_menu| to
  /// false (0) if |is_menu| is true (1) and |window| should not be activated
  /// (given keyboard focus) when displayed.
  ///
  struct _cef_window_t*(CEF_CALLBACK* get_parent_window)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window,
      int* is_menu,
      int* can_activate_menu);

  ///
  /// Return true (1) if |window| should be created as a window modal dialog.
  /// Only called when a Window is returned via get_parent_window() with
  /// |is_menu| set to false (0). All controls in the parent Window will be
  /// disabled while |window| is visible. This functionality is not supported by
  /// all Linux window managers. Alternately, use
  /// cef_window_t::show_as_browser_modal_dialog() for a browser modal dialog
  /// that works on all platforms.
  ///
  int(CEF_CALLBACK* is_window_modal_dialog)(struct _cef_window_delegate_t* self,
                                            struct _cef_window_t* window);

  ///
  /// Return the initial bounds for |window| in density independent pixel (DIP)
  /// coordinates. If this function returns an NULL CefRect then
  /// get_preferred_size() will be called to retrieve the size, and the window
  /// will be placed on the screen with origin (0,0). This function can be used
  /// in combination with cef_view_t::get_bounds_in_screen() to restore the
  /// previous window bounds.
  ///
  cef_rect_t(CEF_CALLBACK* get_initial_bounds)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window);

  ///
  /// Return the initial show state for |window|.
  ///
  cef_show_state_t(CEF_CALLBACK* get_initial_show_state)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window);

  ///
  /// Return true (1) if |window| should be created without a frame or title
  /// bar. The window will be resizable if can_resize() returns true (1). Use
  /// cef_window_t::set_draggable_regions() to specify draggable regions.
  ///
  int(CEF_CALLBACK* is_frameless)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window);

  ///
  /// Return true (1) if |window| should be created with standard window buttons
  /// like close, minimize and zoom. This function is only supported on macOS.
  ///
  int(CEF_CALLBACK* with_standard_window_buttons)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window);

  ///
  /// Return whether the titlebar height should be overridden, and sets the
  /// height of the titlebar in |titlebar_height|. On macOS, it can also be used
  /// to adjust the vertical position of the traffic light buttons in frameless
  /// windows. The buttons will be positioned halfway down the titlebar at a
  /// height of |titlebar_height| / 2.
  ///
  int(CEF_CALLBACK* get_titlebar_height)(struct _cef_window_delegate_t* self,
                                         struct _cef_window_t* window,
                                         float* titlebar_height);

  ///
  /// Return true (1) if |window| can be resized.
  ///
  int(CEF_CALLBACK* can_resize)(struct _cef_window_delegate_t* self,
                                struct _cef_window_t* window);

  ///
  /// Return true (1) if |window| can be maximized.
  ///
  int(CEF_CALLBACK* can_maximize)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window);

  ///
  /// Return true (1) if |window| can be minimized.
  ///
  int(CEF_CALLBACK* can_minimize)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window);

  ///
  /// Return true (1) if |window| can be closed. This will be called for user-
  /// initiated window close actions and when cef_window_t::close() is called.
  ///
  int(CEF_CALLBACK* can_close)(struct _cef_window_delegate_t* self,
                               struct _cef_window_t* window);

  ///
  /// Called when a keyboard accelerator registered with
  /// cef_window_t::SetAccelerator is triggered. Return true (1) if the
  /// accelerator was handled or false (0) otherwise.
  ///
  int(CEF_CALLBACK* on_accelerator)(struct _cef_window_delegate_t* self,
                                    struct _cef_window_t* window,
                                    int command_id);

  ///
  /// Called after all other controls in the window have had a chance to handle
  /// the event. |event| contains information about the keyboard event. Return
  /// true (1) if the keyboard event was handled or false (0) otherwise.
  ///
  int(CEF_CALLBACK* on_key_event)(struct _cef_window_delegate_t* self,
                                  struct _cef_window_t* window,
                                  const cef_key_event_t* event);

  ///
  /// Called when the |window| is transitioning to or from fullscreen mode. The
  /// transition occurs in two stages, with |is_competed| set to false (0) when
  /// the transition starts and true (1) when the transition completes. This
  /// function is only supported on macOS.
  ///
  void(CEF_CALLBACK* on_window_fullscreen_transition)(
      struct _cef_window_delegate_t* self,
      struct _cef_window_t* window,
      int is_completed);
} cef_window_delegate_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_WINDOW_DELEGATE_CAPI_H_
