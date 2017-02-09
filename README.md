Android Things Native Library
=============================

This repository contains the symbols and the headers for the Android Things
[Native PIO API](https://developer.android.com/things/sdk/pio/native.html) for the following architecture:
- `armeabi-v7a`
- `x86`

Usage
=====

- Unzip the latest [release](https://github.com/androidthings/native-libandroidthings/releases) in the native project directory (or in a shared location if you have many native projects).
- Add the following lines to the native project `CMakeLists.txt`:
```
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} <path_to_FindAndroidThings_directory.cmake>)
find_package(AndroidThings REQUIRED)
include_directories(${ANDROIDTHINGS_INCLUDE_DIRS})
target_link_libraries(<your_target_name> ${ANDROIDTHINGS_LIBRARIES})
```
- Add the following arch to the native module `build.gradle`:
```
defaultConfig {
    ndk {
        abiFilters 'armeabi-v7a', 'x86'
    }
}
```

License
=======

Copyright 2016 The Android Open Source Project, Inc.

Licensed to the Apache Software Foundation (ASF) under one or more contributor
license agreements.  See the NOTICE file distributed with this work for
additional information regarding copyright ownership.  The ASF licenses this
file to you under the Apache License, Version 2.0 (the "License"); you may not
use this file except in compliance with the License.  You may obtain a copy of
the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
License for the specific language governing permissions and limitations under
the License.
