(*! \file exif-loader.h
 * \brief Defines the ExifLoader type
 *)
(*
 * Copyright (c) 2003 Lutz Mueller <lutz@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details. 
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA.
 *)

// #ifndef __EXIF_LOADER_H__
// #define __EXIF_LOADER_H__

// #include <libexif/exif-data.h>
// #include <libexif/exif-log.h>
// #include <libexif/exif-mem.h>

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

(*! Allocate a new #ExifLoader.
 *
 *  \return allocated ExifLoader
 *)
function exif_loader_new(): PExifLoader; cdecl; external LIB_LIBEXIF;

(*! Allocate a new #ExifLoader using the specified memory allocator.
 *
 *  \param[in] mem the ExifMem
 *  \return allocated ExifLoader
 *)
function exif_loader_new_mem(mem: PExifMem): PExifLoader; cdecl; external LIB_LIBEXIF;

(*! Increase the refcount of the #ExifLoader.
 *
 *  \param[in] loader the ExifLoader to increase the refcount of.
 *)
procedure exif_loader_ref(loader: PExifLoader); cdecl; external LIB_LIBEXIF;

(*! Decrease the refcount of the #ExifLoader.
 * If the refcount reaches 0, the loader is freed.
 *
 * \param[in] loader ExifLoader for which to decrease the refcount
 *)
procedure exif_loader_unref(loader: PExifLoader); cdecl; external LIB_LIBEXIF;

(*! Load a file into the given #ExifLoader from the filesystem.
 * The relevant data is copied in raw form into the #ExifLoader.
 *
 * \param[in] loader loader to write to
 * \param[in] fname path to the file to read
 *)
procedure exif_loader_write_file(loader: PExifLoader; const fname: pchar); cdecl; external LIB_LIBEXIF;

(*! Load a buffer into the #ExifLoader from a memory buffer.
 * The relevant data is copied in raw form into the #ExifLoader.
 *
 * \param[in] loader loader to write to
 * \param[in] buf buffer to read from
 * \param[in] sz size of the buffer
 * \return 1 while EXIF data is read (or while there is still hope that
 *   there will be EXIF data later on), 0 otherwise.
 *)
function exif_loader_write(loader: PExifLoader; buf: pcuchar; sz: cuint): cuchar; cdecl; external LIB_LIBEXIF;

(*! Free any data previously loaded and reset the #ExifLoader to its
 * newly-initialized state.
 *
 * \param[in] loader the loader
 *)
procedure exif_loader_reset(loader: PExifLoader); cdecl; external LIB_LIBEXIF;

(*! Create an #ExifData from the data in the loader. The loader must
 * already contain data from a previous call to #exif_loader_write_file
 * or #exif_loader_write.
 *
 * \note The #ExifData returned is created using its default options, which
 * may take effect before the data is returned. If other options are desired,
 * an #ExifData must be created explicitly and data extracted from the loader
 * using #exif_loader_get_buf instead.
 *
 * \param[in] loader the loader
 * \return allocated ExifData
 *
 * \see exif_loader_get_buf
 *)
function exif_loader_get_data(loader: PExifLoader): PExifData; cdecl; external LIB_LIBEXIF;

(*! Return the raw data read by the loader.  The returned pointer is only
 * guaranteed to be valid until the next call to a function modifying
 * this #ExifLoader.  Either or both of buf and buf_size may be NULL on
 * entry, in which case that value is not returned.
 *
 * \param[in] loader the loader
 * \param[out] buf read-only pointer to the data read by the loader, or NULL
 *                 in case of error
 * \param[out] buf_size size of the data at buf, or 0 in case of error
 *)
procedure exif_loader_get_buf(loader: PExifLoader; const buf: ppcuchar; buf_size: pcuint); cdecl; external LIB_LIBEXIF;

(*! Set the log message object used by this #ExifLoader.
 * \param[in] loader the loader
 * \param[in] log #ExifLog
 *)
procedure exif_loader_log(loader: PExifLoader; log: PExifLog); cdecl; external LIB_LIBEXIF;

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_LOADER_H__ *)
