(*! \file exif-content.h
 *  \brief Handling EXIF IFDs
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

// #ifndef __EXIF_CONTENT_H__
// #define __EXIF_CONTENT_H__

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

(* Lifecycle *)
function exif_content_new(): PExifContent; cdecl; external LIB_LIBEXIF;
function exif_content_new_mem(data: PExifMem): PExifContent; cdecl; external LIB_LIBEXIF;
procedure exif_content_ref(content: PExifContent); cdecl; external LIB_LIBEXIF;
procedure exif_content_unref(content: PExifContent); cdecl; external LIB_LIBEXIF;
procedure exif_content_free(content: PExifContent); cdecl; external LIB_LIBEXIF;

(*! Add an EXIF tag to an IFD.
 * If this tag already exists in the IFD, this function does nothing.
 * \pre The "tag" member of the entry must be set on entry.
 *
 * \param[out] c IFD
 * \param[in] entry EXIF entry to add
 *)
procedure exif_content_add_entry(content: PExifContent; entry: PExifEntry); cdecl; external LIB_LIBEXIF;

(*! Remove an EXIF tag from an IFD.
 * If this tag does not exist in the IFD, this function does nothing.
 *
 * \param[out] c IFD
 * \param[in] e EXIF entry to remove
 *)
procedure exif_content_remove_entry(content: PExifContent; entry: PExifEntry); cdecl; external LIB_LIBEXIF;

(*! Return the #ExifEntry in this IFD corresponding to the given tag.
 * This is a pointer into a member of the #ExifContent array and must NOT be
 * freed or unrefed by the caller.
 *
 * \param[in] content EXIF content for an IFD
 * \param[in] tag EXIF tag to return
 * \return #ExifEntry of the tag, or NULL on error
 *)
function exif_content_get_entry(content: PExifContent; tag: ExifTag): PExifEntry; cdecl; external LIB_LIBEXIF;

(*! Fix the IFD to bring it into specification. Call #exif_entry_fix on
 * each entry in this IFD to fix existing entries, create any new entries
 * that are mandatory in this IFD but do not yet exist, and remove any
 * entries that are not allowed in this IFD.
 *
 * \param[in,out] c EXIF content for an IFD
 *)
procedure exif_content_fix(content: PExifContent); cdecl; external LIB_LIBEXIF;

type
  ExifContentForeachEntryFunc = procedure (entry: PExifEntry; user_data: pointer); cdecl;

(*! Executes function on each EXIF tag in this IFD in turn.
 * The tags will not necessarily be visited in numerical order.
 *
 * \param[in,out] content IFD over which to iterate
 * \param[in] func function to call for each entry
 * \param[in] user_data data to pass into func on each call
 *)
procedure exif_content_foreach_entry(content: PExifContent; func: ExifContentForeachEntryFunc; user_data: pointer); cdecl; external LIB_LIBEXIF;

(*! Return the IFD number in which the given #ExifContent is found.
 *
 * \param[in] c an #ExifContent*
 * \return IFD number, or #EXIF_IFD_COUNT on error
 *)
function exif_content_get_ifd(content: PExifContent): ExifIfd; cdecl; external LIB_LIBEXIF;

(*! Return a textual representation of the EXIF data for a tag.
 *
 * \param[in] c #ExifContent* for an IFD
 * \param[in] t #ExifTag to return
 * \param[out] v char* buffer in which to store value
 * \param[in] m unsigned int length of the buffer v
 * \return the v pointer, or NULL on error
 *)
//TODO #define exif_content_get_value(c,t,v,m)					\
//TODO 	(exif_content_get_entry (c,t) ?					\
//TODO 	 exif_entry_get_value (exif_content_get_entry (c,t),v,m) : NULL)

(*! Dump contents of the IFD to stdout.
 * This is intended for diagnostic purposes only.
 *
 * \param[in] content IFD data
 * \param[in] indent how many levels deep to indent the data
 *)
procedure exif_content_dump(content: PExifContent; indent: cuint); cdecl; external LIB_LIBEXIF;

(*! Set the log message object for this IFD.
 *
 * \param[in] content IFD
 * \param[in] log #ExifLog*
 *)
procedure exif_content_log(content: PExifContent; log: PExifLog); cdecl; external LIB_LIBEXIF;

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_CONTENT_H__ *)
