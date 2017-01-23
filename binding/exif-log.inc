(*! \file exif-log.h
 *  \brief Log message infrastructure
 *)
(*
 * Copyright (c) 2004 Lutz Mueller <lutz@users.sourceforge.net>
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

// #ifndef __EXIF_LOG_H__
// #define __EXIF_LOG_H__

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

// #include <libexif/exif-mem.h>
// #include <stdarg.h>

(*! Create a new logging instance.
 * \see exif_log_free
 *
 * \return new instance of #ExifLog
 *)
function exif_log_new(): PExifLog; cdecl; external LIB_LIBEXIF;
function exif_log_new_mem(d: PExifMem): PExifLog; cdecl; external LIB_LIBEXIF;
procedure exif_log_ref(log: PExifLog); cdecl; external LIB_LIBEXIF;
procedure exif_log_unref(log: PExifLog); cdecl; external LIB_LIBEXIF;

(*! Delete instance of #ExifLog.
 * \see exif_log_new
 *
 * \param[in] log #ExifLog
 * \return new instance of #ExifLog
 *)
procedure exif_log_free(log: PExifLog); cdecl; external LIB_LIBEXIF;

type
  ExifLogCode = (
	EXIF_LOG_CODE_NONE,
	EXIF_LOG_CODE_DEBUG,
	EXIF_LOG_CODE_NO_MEMORY,
	EXIF_LOG_CODE_CORRUPT_DATA
  );

(*! Return a textual description of the given class of error log.
 *
 * \param[in] code logging message class
 * \return textual description of the log class
 *)
function exif_log_code_get_title(code: ExifLogCode): pchar; cdecl; external LIB_LIBEXIF;

(*! Return a verbose description of the given class of error log.
 *
 * \param[in] code logging message class
 * \return verbose description of the log class
 *)
function exif_log_code_get_message(code: ExifLogCode): pchar; cdecl; external LIB_LIBEXIF;

(*! Log callback function prototype.
 *)
type
  ExifLogFunc = procedure (log: PExifLog; code: ExifLogCode; const domain: pchar; const format: pchar; data: pointer; args: array of const); cdecl;

(*! Register log callback function.
 * Calls to the log callback function are purely for diagnostic purposes.
 *
 * \param[in] log logging state variable
 * \param[in] func callback function to set
 * \param[in] data data to pass into callback function
 *)
procedure exif_log_set_func(log: PExifLog; func: ExifLogFunc; data: pointer); cdecl; external LIB_LIBEXIF;

//TODO #ifndef NO_VERBOSE_TAG_STRINGS
//TODO void     exif_log  (log: PExifLog, ExifLogCode, const char *domain,
//TODO 		    const char *format, ...)
//TODO #ifdef __GNUC__
//TODO 			__attribute__((__format__(printf,4,5)))
//TODO #endif
//TODO ;
//TODO #else
//TODO #if defined(__STDC_VERSION__) &&  __STDC_VERSION__ >= 199901L
//TODO #define exif_log(...) do { } while (0)
//TODO #elif defined(__GNUC__)
//TODO #define exif_log(x...) do { } while (0)
//TODO #else
//TODO #define exif_log (void)
//TODO #endif
//TODO #endif

procedure exif_logv(log: PExifLog; code: ExifLogCode; const domain: pchar; const format: pchar; args: array of const); cdecl; external LIB_LIBEXIF;

(* For your convenience *)
//TODO #define EXIF_LOG_NO_MEMORY(l,d,s) exif_log ((l), EXIF_LOG_CODE_NO_MEMORY, (d), "Could not allocate %lu byte(s).", (unsigned long)(s))

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_LOG_H__ *)
