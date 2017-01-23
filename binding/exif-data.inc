(*! \file exif-data.h
 * \brief Defines the ExifData type and the associated functions.
 *)
(*
 * \author Lutz Mueller <lutz@users.sourceforge.net>
 * \date 2001-2005
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

// #ifndef __EXIF_DATA_H__
// #define __EXIF_DATA_H__

// #ifdef __cplusplus
// extern "C" {
// #endif (* __cplusplus *)

// #include <libexif/exif-byte-order.h>
// #include <libexif/exif-data-type.h>
// #include <libexif/exif-ifd.h>
// #include <libexif/exif-log.h>
// #include <libexif/exif-tag.h>

// #include <libexif/exif-content.h>
// #include <libexif/exif-mnote-data.h>
// #include <libexif/exif-mem.h>

(*! Allocate a new #ExifData. The #ExifData contains an empty
 * #ExifContent for each IFD and the default set of options,
 * which has #EXIF_DATA_OPTION_IGNORE_UNKNOWN_TAGS
 * and #EXIF_DATA_OPTION_FOLLOW_SPECIFICATION set.
 *
 * \return allocated #ExifData, or NULL on error
 *)
function exif_data_new(): PExifData; cdecl; external LIB_LIBEXIF;

(*! Allocate a new #ExifData using the given memory allocator.
 * The #ExifData contains an empty #ExifContent for each IFD and the default
 * set of options, which has #EXIF_DATA_OPTION_IGNORE_UNKNOWN_TAGS and
 * #EXIF_DATA_OPTION_FOLLOW_SPECIFICATION set.
 *
 * \return allocated #ExifData, or NULL on error
 *)
function exif_data_new_mem(mem: PExifMem): PExifData; cdecl; external LIB_LIBEXIF;

(*! Allocate a new #ExifData and load EXIF data from a JPEG file.
 * Uses an #ExifLoader internally to do the loading.
 *
 * \param[in] path filename including path
 * \return allocated #ExifData, or NULL on error
 *)
function exif_data_new_from_file(const path: pchar): PExifData; cdecl; external LIB_LIBEXIF;

(*! Allocate a new #ExifData and load EXIF data from a memory buffer.
 *
 * \param[in] data pointer to raw JPEG or EXIF data
 * \param[in] size number of bytes of data at data
 * \return allocated #ExifData, or NULL on error
 *)
function exif_data_new_from_data(const data: pcuchar; size: cuint): PExifData; cdecl; external LIB_LIBEXIF;

(*! Load the #ExifData structure from the raw JPEG or EXIF data in the given
 * memory buffer. If the EXIF data contains a recognized MakerNote, it is
 * loaded and stored as well for later retrieval by #exif_data_get_mnote_data.
 * If the #EXIF_DATA_OPTION_FOLLOW_SPECIFICATION option has been set on this
 * #ExifData, then the tags are automatically fixed after loading (by calling
 * #exif_data_fix).
 *
 * \param[in,out] data EXIF data
 * \param[in] d pointer to raw JPEG or EXIF data
 * \param[in] size number of bytes of data at d
 *)
procedure exif_data_load_data(data: PExifData; const d: pcuchar; size: cuint); cdecl; external LIB_LIBEXIF;

(*! Store raw EXIF data representing the #ExifData structure into a memory
 * buffer. The buffer is allocated by this function and must subsequently be
 * freed by the caller using the matching free function as used by the #ExifMem
 * in use by this #ExifData.
 *
 * \param[in] data EXIF data
 * \param[out] d pointer to buffer pointer containing raw EXIF data on return
 * \param[out] ds pointer to variable to hold the number of bytes of
 *   data at d, or set to 0 on error
 *)
procedure exif_data_save_data(data: PExifData; d: ppcuchar; ds: pcuint); cdecl; external LIB_LIBEXIF;

procedure exif_data_ref(data: PExifData); cdecl; external LIB_LIBEXIF;
procedure exif_data_unref(data: PExifData); cdecl; external LIB_LIBEXIF;
procedure exif_data_free(data: PExifData); cdecl; external LIB_LIBEXIF;

(*! Return the byte order in use by this EXIF structure.
 *
 * \param[in] data EXIF data
 * \return byte order
 *)
function exif_data_get_byte_order(data: PExifData): ExifByteOrder; cdecl; external LIB_LIBEXIF;

(*! Set the byte order to use for this EXIF data. If any tags already exist
 * (including MakerNote tags) they are are converted to the specified byte
 * order.
 *
 * \param[in,out] data EXIF data
 * \param[in] order byte order
 *)
procedure exif_data_set_byte_order(data: PExifData; order: ExifByteOrder); cdecl; external LIB_LIBEXIF;

(*! Return the MakerNote data out of the EXIF data.  Only certain
 * MakerNote formats that are recognized by libexif are supported.
 * The pointer references a member of the #ExifData structure and must NOT be
 * freed by the caller.
 *
 * \param[in] d EXIF data
 * \return MakerNote data, or NULL if not found or not supported
 *)
function exif_data_get_mnote_data(data: PExifData): PExifMnoteData; cdecl; external LIB_LIBEXIF;

(*! Fix the EXIF data to bring it into specification. Call #exif_content_fix
 * on each IFD to fix existing entries, create any new entries that are
 * mandatory but do not yet exist, and remove any entries that are not
 * allowed.
 *
 * \param[in,out] d EXIF data
 *)
procedure exif_data_fix(data: ExifData); cdecl; external LIB_LIBEXIF;

type
  ExifDataForeachContentFunc = procedure (content: PExifContent; user_data: pointer); cdecl;

(*! Execute a function on each IFD in turn.
 *
 * \param[in] data EXIF data over which to iterate
 * \param[in] func function to call for each entry
 * \param[in] user_data data to pass into func on each call
 *)
procedure exif_data_foreach_content(data: PExifData; func: ExifDataForeachContentFunc; user_data: pointer); cdecl; external LIB_LIBEXIF;

(*! Options to configure the behaviour of #ExifData *)
type
  ExifDataOption = (
	(*! Act as though unknown tags are not present *)
	EXIF_DATA_OPTION_IGNORE_UNKNOWN_TAGS = 1 shl 0,

	(*! Fix the EXIF tags to follow the spec *)
	EXIF_DATA_OPTION_FOLLOW_SPECIFICATION = 1 shl 1,

	(*! Leave the MakerNote alone, which could cause it to be corrupted *)
	EXIF_DATA_OPTION_DONT_CHANGE_MAKER_NOTE = 1 shl 2
  );

(*! Return a short textual description of the given #ExifDataOption.
 *
 * \param[in] o option
 * \return localized textual description of the option
 *)
function exif_data_option_get_name(option: ExifDataOption): pchar; cdecl; external LIB_LIBEXIF;

(*! Return a verbose textual description of the given #ExifDataOption.
 *
 * \param[in] o option
 * \return verbose localized textual description of the option
 *)
function exif_data_option_get_description(option: ExifDataOption): pchar; cdecl; external LIB_LIBEXIF;

(*! Set the given option on the given #ExifData.
 *
 * \param[in] d EXIF data
 * \param[in] o option
 *)
procedure exif_data_set_option(data: PExifData; option: ExifDataOption); cdecl; external LIB_LIBEXIF;

(*! Clear the given option on the given #ExifData.
 *
 * \param[in] d EXIF data
 * \param[in] o option
 *)
procedure exif_data_unset_option(data: PExifData; option: ExifDataOption); cdecl; external LIB_LIBEXIF;

(*! Set the data type for the given #ExifData.
 *
 * \param[in] d EXIF data
 * \param[in] dt data type
 *)
procedure exif_data_set_data_type(data: PExifData; data_type: ExifDataType); cdecl; external LIB_LIBEXIF;

(*! Return the data type for the given #ExifData.
 *
 * \param[in] d EXIF data
 * \return data type, or #EXIF_DATA_TYPE_UNKNOWN on error
 *)
function exif_data_get_data_type(data: PExifData): ExifDataType; cdecl; external LIB_LIBEXIF;

(*! Dump all EXIF data to stdout.
 * This is intended for diagnostic purposes only.
 *
 * \param[in] data EXIF data
 *)
procedure exif_data_dump(data: PExifData); cdecl; external LIB_LIBEXIF;

(*! Set the log message object for all IFDs.
 *
 * \param[in] data EXIF data
 * \param[in] log #ExifLog
 *)
procedure exif_data_log(data: PExifData; log: PExifLog); cdecl; external LIB_LIBEXIF;

(*! Return an #ExifEntry for the given tag if found in any IFD.
 * Each IFD is searched in turn and the first containing a tag with
 * this number is returned.
 *
 * \param[in] d #ExifData
 * \param[in] t #ExifTag
 * \return #ExifEntry* if found, else NULL if not found
 *)
//TODO #define exif_data_get_entry(d,t)					\
//TODO 	(exif_content_get_entry(d->ifd[EXIF_IFD_0],t) ?			\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_0],t) :			\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_1],t) ?			\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_1],t) :			\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_EXIF],t) ?		\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_EXIF],t) :		\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_GPS],t) ?		\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_GPS],t) :		\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_INTEROPERABILITY],t) ?	\
//TODO 	 exif_content_get_entry(d->ifd[EXIF_IFD_INTEROPERABILITY],t) : NULL)

// #ifdef __cplusplus
// }
// #endif (* __cplusplus *)

// #endif (* __EXIF_DATA_H__ *)
