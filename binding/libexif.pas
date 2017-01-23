//
// libexif header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

unit libexif;

{$mode objfpc}{$H+}

interface

uses
  ctypes;

const
  LIB_LIBEXIF = 'libexif-12.dll';


const
  EXIF_IFD_COUNT = 4; (*!< Not a real value, just (max_value + 1). *)

type
  ppcuchar = ^pcuchar;

(*! Possible EXIF Image File Directories *)
  ExifIfd = (
	EXIF_IFD_0 = 0,                (*!< *)
	EXIF_IFD_1,                    (*!< *)
	EXIF_IFD_EXIF,                 (*!< *)
	EXIF_IFD_GPS,                  (*!< *)
	EXIF_IFD_INTEROPERABILITY      (*!< *)
  );

(*! EXIF tags *)
  ExifTag = (
    EXIF_TAG_INTEROPERABILITY_INDEX = $0001,
    EXIF_TAG_INTEROPERABILITY_VERSION = $0002,
    EXIF_TAG_NEW_SUBFILE_TYPE = $00fe,
    EXIF_TAG_IMAGE_WIDTH = $0100,
    EXIF_TAG_IMAGE_LENGTH = $0101,
    EXIF_TAG_BITS_PER_SAMPLE = $0102,
    EXIF_TAG_COMPRESSION = $0103,
    EXIF_TAG_PHOTOMETRIC_INTERPRETATION = $0106,
    EXIF_TAG_FILL_ORDER = $010a,
    EXIF_TAG_DOCUMENT_NAME = $010d,
    EXIF_TAG_IMAGE_DESCRIPTION = $010e,
    EXIF_TAG_MAKE = $010f,
    EXIF_TAG_MODEL = $0110,
    EXIF_TAG_STRIP_OFFSETS = $0111,
    EXIF_TAG_ORIENTATION = $0112,
    EXIF_TAG_SAMPLES_PER_PIXEL = $0115,
    EXIF_TAG_ROWS_PER_STRIP = $0116,
    EXIF_TAG_STRIP_BYTE_COUNTS = $0117,
    EXIF_TAG_X_RESOLUTION = $011a,
    EXIF_TAG_Y_RESOLUTION = $011b,
    EXIF_TAG_PLANAR_CONFIGURATION = $011c,
    EXIF_TAG_RESOLUTION_UNIT = $0128,
    EXIF_TAG_TRANSFER_FUNCTION = $012d,
    EXIF_TAG_SOFTWARE = $0131,
    EXIF_TAG_DATE_TIME = $0132,
    EXIF_TAG_ARTIST = $013b,
    EXIF_TAG_WHITE_POINT = $013e,
    EXIF_TAG_PRIMARY_CHROMATICITIES = $013f,
    EXIF_TAG_SUB_IFDS = $014a,
    EXIF_TAG_TRANSFER_RANGE = $0156,
    EXIF_TAG_JPEG_PROC = $0200,
    EXIF_TAG_JPEG_INTERCHANGE_FORMAT = $0201,
    EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH = $0202,
    EXIF_TAG_YCBCR_COEFFICIENTS = $0211,
    EXIF_TAG_YCBCR_SUB_SAMPLING = $0212,
    EXIF_TAG_YCBCR_POSITIONING = $0213,
    EXIF_TAG_REFERENCE_BLACK_WHITE = $0214,
    EXIF_TAG_XML_PACKET = $02bc,
    EXIF_TAG_RELATED_IMAGE_FILE_FORMAT = $1000,
    EXIF_TAG_RELATED_IMAGE_WIDTH = $1001,
    EXIF_TAG_RELATED_IMAGE_LENGTH = $1002,
    EXIF_TAG_CFA_REPEAT_PATTERN_DIM = $828d,
    EXIF_TAG_CFA_PATTERN = $828e,
    EXIF_TAG_BATTERY_LEVEL = $828f,
    EXIF_TAG_COPYRIGHT = $8298,
    EXIF_TAG_EXPOSURE_TIME = $829a,
    EXIF_TAG_FNUMBER = $829d,
    EXIF_TAG_IPTC_NAA = $83bb,
    EXIF_TAG_IMAGE_RESOURCES = $8649,
    EXIF_TAG_EXIF_IFD_POINTER = $8769,
    EXIF_TAG_INTER_COLOR_PROFILE = $8773,
    EXIF_TAG_EXPOSURE_PROGRAM = $8822,
    EXIF_TAG_SPECTRAL_SENSITIVITY = $8824,
    EXIF_TAG_GPS_INFO_IFD_POINTER = $8825,
    EXIF_TAG_ISO_SPEED_RATINGS = $8827,
    EXIF_TAG_OECF = $8828,
    EXIF_TAG_TIME_ZONE_OFFSET = $882a,
    EXIF_TAG_EXIF_VERSION = $9000,
    EXIF_TAG_DATE_TIME_ORIGINAL = $9003,
    EXIF_TAG_DATE_TIME_DIGITIZED = $9004,
    EXIF_TAG_COMPONENTS_CONFIGURATION = $9101,
    EXIF_TAG_COMPRESSED_BITS_PER_PIXEL = $9102,
    EXIF_TAG_SHUTTER_SPEED_VALUE = $9201,
    EXIF_TAG_APERTURE_VALUE = $9202,
    EXIF_TAG_BRIGHTNESS_VALUE = $9203,
    EXIF_TAG_EXPOSURE_BIAS_VALUE = $9204,
    EXIF_TAG_MAX_APERTURE_VALUE = $9205,
    EXIF_TAG_SUBJECT_DISTANCE = $9206,
    EXIF_TAG_METERING_MODE = $9207,
    EXIF_TAG_LIGHT_SOURCE = $9208,
    EXIF_TAG_FLASH = $9209,
    EXIF_TAG_FOCAL_LENGTH = $920a,
    EXIF_TAG_SUBJECT_AREA = $9214,
    EXIF_TAG_TIFF_EP_STANDARD_ID = $9216,
    EXIF_TAG_MAKER_NOTE = $927c,
    EXIF_TAG_USER_COMMENT = $9286,
    EXIF_TAG_SUB_SEC_TIME = $9290,
    EXIF_TAG_SUB_SEC_TIME_ORIGINAL = $9291,
    EXIF_TAG_SUB_SEC_TIME_DIGITIZED = $9292,
    EXIF_TAG_XP_TITLE = $9c9b,
    EXIF_TAG_XP_COMMENT = $9c9c,
    EXIF_TAG_XP_AUTHOR = $9c9d,
    EXIF_TAG_XP_KEYWORDS = $9c9e,
    EXIF_TAG_XP_SUBJECT = $9c9f,
    EXIF_TAG_FLASH_PIX_VERSION = $a000,
    EXIF_TAG_COLOR_SPACE = $a001,
    EXIF_TAG_PIXEL_X_DIMENSION = $a002,
    EXIF_TAG_PIXEL_Y_DIMENSION = $a003,
    EXIF_TAG_RELATED_SOUND_FILE = $a004,
    EXIF_TAG_INTEROPERABILITY_IFD_POINTER = $a005,
    EXIF_TAG_FLASH_ENERGY = $a20b,
    EXIF_TAG_SPATIAL_FREQUENCY_RESPONSE = $a20c,
    EXIF_TAG_FOCAL_PLANE_X_RESOLUTION = $a20e,
    EXIF_TAG_FOCAL_PLANE_Y_RESOLUTION = $a20f,
    EXIF_TAG_FOCAL_PLANE_RESOLUTION_UNIT = $a210,
    EXIF_TAG_SUBJECT_LOCATION = $a214,
    EXIF_TAG_EXPOSURE_INDEX = $a215,
    EXIF_TAG_SENSING_METHOD = $a217,
    EXIF_TAG_FILE_SOURCE = $a300,
    EXIF_TAG_SCENE_TYPE = $a301,
    EXIF_TAG_NEW_CFA_PATTERN = $a302,
    EXIF_TAG_CUSTOM_RENDERED = $a401,
    EXIF_TAG_EXPOSURE_MODE = $a402,
    EXIF_TAG_WHITE_BALANCE = $a403,
    EXIF_TAG_DIGITAL_ZOOM_RATIO = $a404,
    EXIF_TAG_FOCAL_LENGTH_IN_35MM_FILM = $a405,
    EXIF_TAG_SCENE_CAPTURE_TYPE = $a406,
    EXIF_TAG_GAIN_CONTROL = $a407,
    EXIF_TAG_CONTRAST = $a408,
    EXIF_TAG_SATURATION = $a409,
    EXIF_TAG_SHARPNESS = $a40a,
    EXIF_TAG_DEVICE_SETTING_DESCRIPTION = $a40b,
    EXIF_TAG_SUBJECT_DISTANCE_RANGE = $a40c,
    EXIF_TAG_IMAGE_UNIQUE_ID = $a420,
    EXIF_TAG_GAMMA = $a500,
    EXIF_TAG_PRINT_IMAGE_MATCHING = $c4a5,
    EXIF_TAG_PADDING = $ea1c
  );

(*! EXIF tag data formats *)
  ExifFormat = (
    EXIF_FORMAT_BYTE       =  1,
    EXIF_FORMAT_ASCII      =  2,
    EXIF_FORMAT_SHORT      =  3,
    EXIF_FORMAT_LONG       =  4,
    EXIF_FORMAT_RATIONAL   =  5,
	EXIF_FORMAT_SBYTE      =  6,
    EXIF_FORMAT_UNDEFINED  =  7,
	EXIF_FORMAT_SSHORT     =  8,
    EXIF_FORMAT_SLONG      =  9,
    EXIF_FORMAT_SRATIONAL  = 10,
	EXIF_FORMAT_FLOAT      = 11,
	EXIF_FORMAT_DOUBLE     = 12
  );

(*! Data found in one EXIF tag.
 * The #exif_entry_get_value function can provide access to the
 * formatted contents, or the struct members can be used directly to
 * access the raw contents.
 *)
  PPExifEntry = ^PExifEntry;
  PExifEntry = ^ExifEntry;
  PExifEntryPrivate = ^ExifEntryPrivate;

(*! Represents the entire EXIF data found in an image *)
  PExifData = ^ExifData;
  PExifDataPrivate = ^ExifDataPrivate;

(*! Holds all EXIF tags in a single IFD *)
  PExifContent = ^ExifContent;
  PExifContentPrivate = ^ExifContentPrivate;
  ExifContentPrivate = record
  end;

(*! Represents the entire EXIF data found in an image *)
  ExifData = record
	(*! Data for each IFD *)
	ifd: array[0..EXIF_IFD_COUNT-1] of PExifContent;

	(*! Pointer to thumbnail image, or NULL if not available *)
	data: pcuchar;

	(*! Number of bytes in thumbnail image at \c data *)
	size: cuint;

	priv: PExifDataPrivate;
  end;
  
  ExifDataPrivate = record
  end;

  ExifContent = record
    entries: PPExifEntry;
    count: cuint;

	(*! Data containing this content *)
	parent: PExifData;

	priv: PExifContentPrivate;
  end;

(*! Data found in one EXIF tag *)
  ExifEntry = record
	(*! EXIF tag for this entry *)
    tag: ExifTag;
	
	(*! Type of data in this entry *)
    format: ExifFormat;

	(*! Number of elements in the array, if this is an array entry.
	 * Contains 1 for non-array data types. *)
    components: culong;

	(*! Pointer to the raw EXIF data for this entry. It is allocated
	 * by #exif_entry_initialize and is NULL beforehand. Data contained
	 * here may be manipulated using the functions in exif-utils.h *)
    data: pcuchar;

	(*! Number of bytes in the buffer at \c data. This must be no less
	 * than exif_format_get_size(format)*components *)
    size: cuint;

	(*! #ExifContent containing this entry. 
	 * \see exif_entry_get_ifd *)
	parent: PExifContent;

	(*! Internal data to be used by libexif itself *)
	priv: PExifEntryPrivate;
  end;
  
  ExifEntryPrivate = record
  end;

(*! ExifMem define a memory allocator *)
  PExifMem = ^ExifMem;
  ExifMem = record
  end;

(*! State maintained by the logging interface *)
  PExifLog = ^ExifLog;
  ExifLog = record
  end;

(*! Data found in the MakerNote tag *)
  PExifMnoteData = ^ExifMnoteData;
  ExifMnoteData = record
  end;

(*! Represents the type of image data to which the EXIF data applies.
 * The EXIF tags have different constraints depending on the type of
 * image data.
 *)
  ExifDataType = (
	EXIF_DATA_TYPE_UNCOMPRESSED_CHUNKY = 0,
	EXIF_DATA_TYPE_UNCOMPRESSED_PLANAR,
	EXIF_DATA_TYPE_UNCOMPRESSED_YCC,
	EXIF_DATA_TYPE_COMPRESSED,
	EXIF_DATA_TYPE_COUNT
  );

(*! Data used by the loader interface *)
  PExifLoader = ^ExifLoader;
  ExifLoader = record
  end;


{$include exif-byte-order.inc}
{$include exif-utils.inc}

{$include exif-content.inc}
{$include exif-data.inc}
{$include exif-data-type.inc}
{$include exif-entry.inc}
{$include exif-format.inc}
{$include exif-ifd.inc}
{$include exif-loader.inc}
{$include exif-log.inc}
{$include exif-mem.inc}
{$include exif-mnote-data.inc}
{$include exif-tag.inc}


implementation


end.

