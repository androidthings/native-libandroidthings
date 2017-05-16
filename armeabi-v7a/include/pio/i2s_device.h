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

#ifndef SYSTEM_PERIPHERALMANAGER_I2S_H_
#define SYSTEM_PERIPHERALMANAGER_I2S_H_

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

/// @defgroup I2s I2s Interface
/// @brief Functions to control I2S pins.
///
/// These functions can be used to control I2S.
/// @{

/// Possible encodings
typedef enum APcmEncoding {
  APCM_ENCODING_8_BIT,
  APCM_ENCODING_16_BIT,
  APCM_ENCODING_24_BIT,
  APCM_ENCODING_32_BIT
} APcmEncoding;

typedef struct AI2sDevice AI2sDevice;

/// Writes raw data to the I2S device. Multi-channel audio data is interleaved.
/// @param i2s Pointer to the AI2s struct.
/// @param data Data to write.
/// @param offset Offset to first byte in data.
/// @param size Number of bytes to write.
/// @param bytes_written Number of bytes written.
/// @return 0 on success, errno on error.
int AI2sDevice_write(const AI2sDevice* i2s,
                     const void* data,
                     int offset,
                     int size,
                     int* bytes_written);

/// Reads raw data from the I2S device. Multi-channel audio data is interleaved.
/// @param i2s Pointer to the AI2s struct.
/// @param data Buffer to fill with data read.
/// @param offset Offset to first byte in data.
/// @param size Number of bytes to read.
/// @param bytes_read Number of bytes read.
/// @return 0 on success, errno on error.
int AI2sDevice_read(
    const AI2sDevice* i2s, void* data, int offset, int size, int* bytes_read);

/// Destroys an AI2s struct.
/// @param i2s Pointer to the AI2s struct.
void AI2sDevice_delete(AI2sDevice* i2s);

/// @}

__END_DECLS

#endif  // SYSTEM_PERIPHERALMANAGER_I2S_H_
