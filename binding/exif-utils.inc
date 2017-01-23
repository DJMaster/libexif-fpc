(*! \file exif-utils.h
 *  \brief EXIF data manipulation functions and types 
 *)
(*
 * Copyright (c) 2001 Lutz Mueller <lutz@users.sourceforge.net>
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

// #ifndef __EXIF_UTILS_H__
// #define __EXIF_UTILS_H__

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

// #include <libexif/exif-byte-order.h>
// #include <libexif/exif-format.h>
// #include <libexif/_stdint.h>


(* If these definitions don't work for you, please let us fix the 
 * macro generating _stdint.h *)

type 
(*! EXIF Unsigned Byte data type *)
  ExifByte = cuchar; (* 1 byte  *)

(*! EXIF Signed Byte data type *)
  ExifSByte = cschar; (* 1 byte  *)

(*! EXIF Text String data type *)
  ExifAscii = pchar;

(*! EXIF Unsigned Short data type *)
  ExifShort = cuint16; (* 2 bytes *)
	
(*! EXIF Signed Short data type *)
  ExifSShort = cint16; (* 2 bytes *)
	
(*! EXIF Unsigned Long data type *)
  ExifLong = cuint32; (* 4 bytes *)
	
(*! EXIF Signed Long data type *)
  ExifSLong = cint32; (* 4 bytes *)

(*! EXIF Unsigned Rational data type *)
  ExifRational = record
    numerator: ExifLong;
    denominator: ExifLong;
  end;

  ExifUndefined = cchar; (* 1 byte  *)

(*! EXIF Signed Rational data type *)
  ExifSRational = record
    numerator: ExifSLong;
    denominator: ExifSLong;
  end;


(*! Retrieve an #ExifShort value from memory.
 *
 * \param[in] b pointer to raw EXIF value in memory
 * \param[in] order byte order of raw value
 * \return value
 *)
function exif_get_short(const b: pcuchar; order: ExifByteOrder): ExifShort; cdecl; external LIB_LIBEXIF;

(*! Retrieve an #ExifSShort value from memory.
 *
 * \param[in] b pointer to raw EXIF value in memory
 * \param[in] order byte order of raw value
 * \return value
 *)
function exif_get_sshort(const b: pcuchar; order: ExifByteOrder): ExifSShort; cdecl; external LIB_LIBEXIF;

(*! Retrieve an #ExifLong value from memory.
 *
 * \param[in] b pointer to raw EXIF value in memory
 * \param[in] order byte order of raw value
 * \return value
 *)
function exif_get_long(const b: pcuchar; order: ExifByteOrder): ExifLong; cdecl; external LIB_LIBEXIF;

(*! Retrieve an #ExifSLong value from memory.
 *
 * \param[in] b pointer to raw EXIF value in memory
 * \param[in] order byte order of raw value
 * \return value
 *)
function exif_get_slong(const b: pcuchar; order: ExifByteOrder): ExifSLong; cdecl; external LIB_LIBEXIF;

(*! Retrieve an #ExifRational value from memory.
 *
 * \param[in] b pointer to raw EXIF value in memory
 * \param[in] order byte order of raw value
 * \return value
 *)
function exif_get_rational(const b: pcuchar; order: ExifByteOrder): ExifRational; cdecl; external LIB_LIBEXIF;

(*! Retrieve an #ExifSRational value from memory.
 *
 * \param[in] b pointer to raw EXIF value in memory
 * \param[in] order byte order of raw value
 * \return value
 *)
function exif_get_srational(const b: pcuchar; order: ExifByteOrder): ExifSRational; cdecl; external LIB_LIBEXIF;

(*! Store an ExifShort value into memory in EXIF format.
 *
 * \param[out] b buffer in which to write raw value
 * \param[in] order byte order to use
 * \param[in] value data value to store
 *)
procedure exif_set_short(b: pcuchar; order: ExifByteOrder; value: ExifShort); cdecl; external LIB_LIBEXIF;

(*! Store an ExifSShort value into memory in EXIF format.
 *
 * \param[out] b buffer in which to write raw value
 * \param[in] order byte order to use
 * \param[in] value data value to store
 *)
procedure exif_set_sshort(b: pcuchar; order: ExifByteOrder; value: ExifSShort); cdecl; external LIB_LIBEXIF;

(*! Store an ExifLong value into memory in EXIF format.
 *
 * \param[out] b buffer in which to write raw value
 * \param[in] order byte order to use
 * \param[in] value data value to store
 *)
procedure exif_set_long(b: pcuchar; order: ExifByteOrder; value: ExifLong); cdecl; external LIB_LIBEXIF;

(*! Store an ExifSLong value into memory in EXIF format.
 *
 * \param[out] b buffer in which to write raw value
 * \param[in] order byte order to use
 * \param[in] value data value to store
 *)
procedure exif_set_slong(b: pcuchar; order: ExifByteOrder; value: ExifSLong); cdecl; external LIB_LIBEXIF;

(*! Store an ExifRational value into memory in EXIF format.
 *
 * \param[out] b buffer in which to write raw value
 * \param[in] order byte order to use
 * \param[in] value data value to store
 *)
procedure exif_set_rational(b: pcuchar; order: ExifByteOrder; value: ExifRational); cdecl; external LIB_LIBEXIF;

(*! Store an ExifSRational value into memory in EXIF format.
 *
 * \param[out] b buffer in which to write raw value
 * \param[in] order byte order to use
 * \param[in] value data value to store
 *)
procedure exif_set_srational(b: pcuchar; order: ExifByteOrder; value: ExifSRational); cdecl; external LIB_LIBEXIF;

(*! \internal *)
procedure exif_convert_utf16_to_utf8(out_: pchar; const in_: pcushort; maxlen: cint); cdecl; external LIB_LIBEXIF;

(* Please do not use this function outside of the library. *)

(*! \internal *)
procedure exif_array_set_byte_order(format: ExifFormat; data: pcuchar; size: cuint; o_orig: ExifByteOrder; o_new: ExifByteOrder); cdecl; external LIB_LIBEXIF;

//TODO #undef  MIN
//TODO #define MIN(a, b)  (((a) < (b)) ? (a) : (b))

//TODO #undef  MAX
//TODO #define MAX(a, b)  (((a) > (b)) ? (a) : (b))

(* For compatibility with older versions *)

const
(*! \deprecated Use EXIF_TAG_SUB_SEC_TIME instead. *)
  EXIF_TAG_SUBSEC_TIME = EXIF_TAG_SUB_SEC_TIME deprecated;

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_UTILS_H__ *)
