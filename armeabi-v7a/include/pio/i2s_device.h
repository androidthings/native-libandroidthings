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
typedef enum AI2sEncoding {
  AI2S_ENCODING_PCM_8_BIT,
  AI2S_ENCODING_PCM_16_BIT,
  AI2S_ENCODING_PCM_24_BIT,
  AI2S_ENCODING_PCM_32_BIT
} AI2sEncoding;

/// Flags to specify I2s bus direction.
typedef enum AI2sFlags {
  AI2S_FLAG_DIRECTION_IN = 1 << 0,
  AI2S_FLAG_DIRECTION_OUT = 1 << 1
} AI2sFlags;

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

/// Gets the timestamp when a specific sample entered the kernel.
/// @param i2s Pointer to the AI2s struct.
/// @param frame_position Output indicating number of frames read.
/// @param nano_time Output indicating time (ns) when the frame was read.
/// @param success Output indicating success (1) or failure (0).
/// @return 0 on success, errno on error. This will only be nonzero on a fatal
///         error such as the I2S device couldn't be found; in the normal case
///         that a timestamp isn't available the success param will be used.
int AI2sDevice_getInputTimestamp(const AI2sDevice* i2s,
                                 int64_t* frame_position,
                                 int64_t* nano_time,
                                 int* success);

/// Gets the timestamp when a specific sample exited the kernel.
/// @param i2s Pointer to the AI2s struct.
/// @param frame_position Output indicating number of frames written.
/// @param nano_time Output indicating time (ns) when the frame was written.
/// @param success Output indicating success (1) or failure (0).
/// @return 0 on success, errno on error. This will only be nonzero on a fatal
///         error such as the I2S device couldn't be found; in the normal case
///         that a timestamp isn't available the success param will be used.
int AI2sDevice_getOutputTimestamp(const AI2sDevice* i2s,
                                  int64_t* frame_position,
                                  int64_t* nano_time,
                                  int* success);

/// Destroys an AI2s struct.
/// @param i2s Pointer to the AI2s struct.
void AI2sDevice_delete(AI2sDevice* i2s);

/// @}

__END_DECLS

#endif  // SYSTEM_PERIPHERALMANAGER_I2S_H_
