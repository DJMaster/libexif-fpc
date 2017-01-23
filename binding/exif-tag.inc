(*! \file exif-tag.h
 *  \brief Handling EXIF tags
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

// #ifndef __EXIF_TAG_H__
// #define __EXIF_TAG_H__

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

// #include <libexif/exif-ifd.h>
// #include <libexif/exif-data-type.h>

const
(* GPS tags overlap with above ones. *)
  EXIF_TAG_GPS_VERSION_ID = $0000;
  EXIF_TAG_GPS_LATITUDE_REF = $0001; (* INTEROPERABILITY_INDEX   *)
  EXIF_TAG_GPS_LATITUDE = $0002; (* INTEROPERABILITY_VERSION *)
  EXIF_TAG_GPS_LONGITUDE_REF = $0003;
  EXIF_TAG_GPS_LONGITUDE = $0004;
  EXIF_TAG_GPS_ALTITUDE_REF = $0005;
  EXIF_TAG_GPS_ALTITUDE = $0006;
  EXIF_TAG_GPS_TIME_STAMP = $0007;
  EXIF_TAG_GPS_SATELLITES = $0008;
  EXIF_TAG_GPS_STATUS = $0009;
  EXIF_TAG_GPS_MEASURE_MODE = $000a;
  EXIF_TAG_GPS_DOP = $000b;
  EXIF_TAG_GPS_SPEED_REF = $000c;
  EXIF_TAG_GPS_SPEED = $000d;
  EXIF_TAG_GPS_TRACK_REF = $000e;
  EXIF_TAG_GPS_TRACK = $000f;
  EXIF_TAG_GPS_IMG_DIRECTION_REF = $0010;
  EXIF_TAG_GPS_IMG_DIRECTION = $0011;
  EXIF_TAG_GPS_MAP_DATUM = $0012;
  EXIF_TAG_GPS_DEST_LATITUDE_REF = $0013;
  EXIF_TAG_GPS_DEST_LATITUDE = $0014;
  EXIF_TAG_GPS_DEST_LONGITUDE_REF = $0015;
  EXIF_TAG_GPS_DEST_LONGITUDE = $0016;
  EXIF_TAG_GPS_DEST_BEARING_REF = $0017;
  EXIF_TAG_GPS_DEST_BEARING = $0018;
  EXIF_TAG_GPS_DEST_DISTANCE_REF = $0019;
  EXIF_TAG_GPS_DEST_DISTANCE = $001a;
  EXIF_TAG_GPS_PROCESSING_METHOD = $001b;
  EXIF_TAG_GPS_AREA_INFORMATION = $001c;
  EXIF_TAG_GPS_DATE_STAMP = $001d;
  EXIF_TAG_GPS_DIFFERENTIAL = $001e;

(*! What level of support a tag enjoys in the EXIF standard *)
type
  ExifSupportLevel = (
	(*! The meaning of this tag is unknown *)
	EXIF_SUPPORT_LEVEL_UNKNOWN = 0,

	(*! This tag is not allowed in the given IFD *)
	EXIF_SUPPORT_LEVEL_NOT_RECORDED,

	(*! This tag is mandatory in the given IFD *)
	EXIF_SUPPORT_LEVEL_MANDATORY,

	(*! This tag is optional in the given IFD *)
	EXIF_SUPPORT_LEVEL_OPTIONAL
  );

(*! Return the tag ID given its unique textual name.
 *
 * \param[in] name tag name
 * \return tag ID, or 0 if tag not found
 * \note The tag not found value cannot be distinguished from a legitimate
 *   tag number 0.
 *)
function exif_tag_from_name(const name: pchar): ExifTag; cdecl; external LIB_LIBEXIF;

(*! Return a textual name of the given tag when found in the given IFD. The
 * name is a short, unique, non-localized text string containing only
 * US-ASCII alphanumeric characters.
 *
 * \param[in] tag EXIF tag
 * \param[in] ifd IFD
 * \return textual name of the tag, or NULL if the tag is unknown
 *)
function exif_tag_get_name_in_ifd(tag: ExifTag; ifd: ExifIfd): pchar; cdecl; external LIB_LIBEXIF;

(*! Return a textual title of the given tag when found in the given IFD.
 * The title is a short, localized description of the tag.
 *
 * \param[in] tag EXIF tag
 * \param[in] ifd IFD
 * \return textual title of the tag, or NULL if the tag is unknown
 *)
function exif_tag_get_title_in_ifd(tag: ExifTag; ifd: ExifIfd): pchar; cdecl; external LIB_LIBEXIF;

(*! Return a verbose textual description of the given tag when found in the
 * given IFD. The description is a verbose, localized description of the tag.
 *
 * \param[in] tag EXIF tag
 * \param[in] ifd IFD
 * \return textual description of the tag, or NULL if the tag is unknown
 *)
function exif_tag_get_description_in_ifd(tag: ExifTag; ifd: ExifIfd): pchar; cdecl; external LIB_LIBEXIF;

(*! Return whether the given tag is mandatory or not in the given IFD and
 * data type according to the EXIF specification. If the IFD given is
 * EXIF_IFD_COUNT, the result is EXIF_SUPPORT_LEVEL_UNKNOWN. If the data
 * type is EXIF_DATA_TYPE_UNKNOWN, the result is
 * EXIF_SUPPORT_LEVEL_UNKNOWN unless the support level is the same for
 * all data types.
 *
 * \param[in] tag EXIF tag
 * \param[in] ifd IFD or EXIF_IFD_COUNT
 * \param[in] t data type or EXIF_DATA_TYPE_UNKNOWN
 * \return the level of support for this tag
 *)
function exif_tag_get_support_level_in_ifd(tag: ExifTag; ifd: ExifIfd; t: ExifDataType): ExifSupportLevel; cdecl; external LIB_LIBEXIF;

(* Don't use these functions. They are here for compatibility only. *)

(*! \deprecated Use #exif_tag_get_name_in_ifd instead *)
function exif_tag_get_name(tag: ExifTag): pchar; cdecl; external LIB_LIBEXIF;

(*! \deprecated Use #exif_tag_get_title_in_ifd instead *)
function exif_tag_get_title(tag: ExifTag): pchar; cdecl; external LIB_LIBEXIF;

(*! \deprecated Use #exif_tag_get_description_in_ifd instead *)
function exif_tag_get_description(tag: ExifTag): pchar; cdecl; external LIB_LIBEXIF;


(* For now, do not use these functions. *)

(*! \internal *)
function exif_tag_table_get_tag(n: cuint): ExifTag; cdecl; external LIB_LIBEXIF;

(*! \internal *)
function exif_tag_table_get_name(n: cuint): pchar; cdecl; external LIB_LIBEXIF;

(*! \internal *)
function exif_tag_table_count(): cuint; cdecl; external LIB_LIBEXIF;


(* Don't use these definitions. They are here for compatibility only. *)

const
(*! \deprecated Use EXIF_TAG_PRINT_IMAGE_MATCHING instead. *)
  EXIF_TAG_UNKNOWN_C4A5 = EXIF_TAG_PRINT_IMAGE_MATCHING deprecated;

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_TAG_H__ *)
