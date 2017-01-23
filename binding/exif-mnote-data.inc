(*! \file exif-mnote-data.h
 *  \brief Handling EXIF MakerNote tags
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

// #ifndef __EXIF_MNOTE_DATA_H__
// #define __EXIF_MNOTE_DATA_H__

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

// #include <libexif/exif-log.h>

procedure exif_mnote_data_ref(maker_note: PExifMnoteData); cdecl; external LIB_LIBEXIF;
procedure exif_mnote_data_unref(maker_note: PExifMnoteData); cdecl; external LIB_LIBEXIF;

(*! Load the MakerNote data from a memory buffer.
 *
 * \param[in] d MakerNote data
 * \param[in] buf pointer to raw MakerNote tag data
 * \param[in] buf_siz number of bytes of data at buf
 *)
procedure exif_mnote_data_load (d: PExifMnoteData; const buf: pcuchar; buf_siz: cuint); cdecl; external LIB_LIBEXIF;

(*!
 * Save the raw MakerNote data into a memory buffer.  The buffer is
 * allocated by this function and must subsequently be freed by the
 * caller.
 *
 * \param[in,out] d extract the data from this structure 
 * \param[out] buf pointer to buffer pointer containing MakerNote data on return
 * \param[out] buf_siz pointer to the size of the buffer
 *)
procedure exif_mnote_data_save(d: PExifMnoteData; buf: ppcuchar; buf_siz: pcuint); cdecl; external LIB_LIBEXIF;

(*! Return the number of tags in the MakerNote.
 *
 * \param[in] d MakerNote data
 * \return number of tags, or 0 if no MakerNote or the type is not supported
 *)
function exif_mnote_data_count(d: PExifMnoteData): cuint; cdecl; external LIB_LIBEXIF;

(*! Return the MakerNote tag number for the tag at the specified index within
 * the MakerNote.
 *
 * \param[in] d MakerNote data
 * \param[in] n index of the entry within the MakerNote data
 * \return MakerNote tag number
 *)
function exif_mnote_data_get_id(d: PExifMnoteData; n: cuint): cuint; cdecl; external LIB_LIBEXIF;

(*! Returns textual name of the given MakerNote tag. The name is a short,
 * unique (within this type of MakerNote), non-localized text string
 * containing only US-ASCII alphanumeric characters.
 *
 * \param[in] d MakerNote data
 * \param[in] n index of the entry within the MakerNote data
 * \return textual name of the tag
 *)
function exif_mnote_data_get_name(d: PExifMnoteData; n: cuint): pchar; cdecl; external LIB_LIBEXIF;

(*! Returns textual title of the given MakerNote tag.
 * The title is a short, localized textual description of the tag.
 *
 * \param[in] d MakerNote data
 * \param[in] n index of the entry within the MakerNote data
 * \return textual name of the tag
 *)
function exif_mnote_data_get_title(d: PExifMnoteData; n: cuint): pchar; cdecl; external LIB_LIBEXIF;

(*! Returns verbose textual description of the given MakerNote tag.
 *
 * \param[in] d MakerNote data
 * \param[in] n index of the entry within the MakerNote data
 * \return textual description of the tag
 *)
function exif_mnote_data_get_description(d: PExifMnoteData; n: cuint): pchar; cdecl; external LIB_LIBEXIF;

(*! Return a textual representation of the value of the MakerNote entry.
 *
 * \warning The character set of the returned string may be in
 *          the encoding of the current locale or the native encoding
 *          of the camera.
 *
 * \param[in] d MakerNote data
 * \param[in] n index of the entry within the MakerNote data
 * \param[out] val buffer in which to store value
 * \param[in] maxlen length of the buffer val
 * \return val pointer, or NULL on error
 *)
function exif_mnote_data_get_value(d: PExifMnoteData; n: cuint; val: pchar; maxlen: cuint): pchar; cdecl; external LIB_LIBEXIF;

procedure exif_mnote_data_log(d: PExifMnoteData; log: PExifLog); cdecl; external LIB_LIBEXIF;

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_MNOTE_DATA_H__ *)
