/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBANDROIDTHINGS_INCLUDE_BOOT_ACTION_BOOT_ACTION_H_
#define LIBANDROIDTHINGS_INCLUDE_BOOT_ACTION_BOOT_ACTION_H_

#include <sys/cdefs.h>

__BEGIN_DECLS

/// A single boot action key/value parameter.
///
/// These parameters can be set when programmatically rebooting the device,
/// and are passed into boot_action_init().
typedef struct ABootActionParameter {
  const char* key;
  const char* value;
} ABootActionParameter;

__END_DECLS

#endif  //  LIBANDROIDTHINGS_INCLUDE_BOOT_ACTION_BOOT_ACTION_H_
