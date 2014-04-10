/* packet-dcerpc-spoolss.h
 * Routines for SMB \PIPE\spoolss packet disassembly
 * Copyright 2001, Tim Potter <tpot@samba.org>
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __PACKET_DCERPC_SPOOLSS_H
#define __PACKET_DCERPC_SPOOLSS_H

/* Functions available on the SPOOLSS pipe.  From Samba,
   include/rpc_spoolss.h */

#define SPOOLSS_ENUMPRINTERS				0x00
#define SPOOLSS_OPENPRINTER				0x01
#define SPOOLSS_SETJOB					0x02
#define SPOOLSS_GETJOB					0x03
#define SPOOLSS_ENUMJOBS				0x04
#define SPOOLSS_ADDPRINTER				0x05
#define SPOOLSS_DELETEPRINTER				0x06
#define SPOOLSS_SETPRINTER				0x07
#define SPOOLSS_GETPRINTER				0x08
#define SPOOLSS_ADDPRINTERDRIVER			0x09
#define SPOOLSS_ENUMPRINTERDRIVERS			0x0a
#define SPOOLSS_GETPRINTERDRIVER			0x0b
#define SPOOLSS_GETPRINTERDRIVERDIRECTORY		0x0c
#define SPOOLSS_DELETEPRINTERDRIVER			0x0d
#define SPOOLSS_ADDPRINTPROCESSOR			0x0e
#define SPOOLSS_ENUMPRINTPROCESSORS			0x0f
#define SPOOLSS_GETPRINTPROCESSORDIRECTORY		0x10
#define SPOOLSS_STARTDOCPRINTER				0x11
#define SPOOLSS_STARTPAGEPRINTER			0x12
#define SPOOLSS_WRITEPRINTER				0x13
#define SPOOLSS_ENDPAGEPRINTER				0x14
#define SPOOLSS_ABORTPRINTER				0x15
#define SPOOLSS_READPRINTER				0x16
#define SPOOLSS_ENDDOCPRINTER				0x17
#define SPOOLSS_ADDJOB					0x18
#define SPOOLSS_SCHEDULEJOB				0x19
#define SPOOLSS_GETPRINTERDATA				0x1a
#define SPOOLSS_SETPRINTERDATA				0x1b
#define SPOOLSS_WAITFORPRINTERCHANGE			0x1c
#define SPOOLSS_CLOSEPRINTER				0x1d
#define SPOOLSS_ADDFORM					0x1e
#define SPOOLSS_DELETEFORM				0x1f
#define SPOOLSS_GETFORM					0x20
#define SPOOLSS_SETFORM					0x21
#define SPOOLSS_ENUMFORMS				0x22
#define SPOOLSS_ENUMPORTS				0x23
#define SPOOLSS_ENUMMONITORS				0x24
#define SPOOLSS_ADDPORT					0x25
#define SPOOLSS_CONFIGUREPORT				0x26
#define SPOOLSS_DELETEPORT				0x27
#define SPOOLSS_CREATEPRINTERIC				0x28
#define SPOOLSS_PLAYGDISCRIPTONPRINTERIC		0x29
#define SPOOLSS_DELETEPRINTERIC				0x2a
#define SPOOLSS_ADDPRINTERCONNECTION			0x2b
#define SPOOLSS_DELETEPRINTERCONNECTION			0x2c
#define SPOOLSS_PRINTERMESSAGEBOX			0x2d
#define SPOOLSS_ADDMONITOR				0x2e
#define SPOOLSS_DELETEMONITOR				0x2f
#define SPOOLSS_DELETEPRINTPROCESSOR			0x30
#define SPOOLSS_ADDPRINTPROVIDER			0x31
#define SPOOLSS_DELETEPRINTPROVIDER			0x32
#define SPOOLSS_ENUMPRINTPROCDATATYPES			0x33
#define SPOOLSS_RESETPRINTER				0x34
#define SPOOLSS_GETPRINTERDRIVER2			0x35
#define SPOOLSS_FINDFIRSTPRINTERCHANGENOTIFICATION	0x36
#define SPOOLSS_FINDNEXTPRINTERCHANGENOTIFICATION	0x37
#define SPOOLSS_FCPN					0x38
#define SPOOLSS_ROUTERFINDFIRSTPRINTERNOTIFICATIONOLD	0x39
#define SPOOLSS_REPLYOPENPRINTER			0x3a
#define SPOOLSS_ROUTERREPLYPRINTER			0x3b
#define SPOOLSS_REPLYCLOSEPRINTER			0x3c
#define SPOOLSS_ADDPORTEX				0x3d
#define SPOOLSS_REMOTEFINDFIRSTPRINTERCHANGENOTIFICATION 0x3e
#define SPOOLSS_SPOOLERINIT				0x3f
#define SPOOLSS_RESETPRINTEREX				0x40
#define SPOOLSS_RFFPCNEX				0x41
#define SPOOLSS_RRPCN					0x42
#define SPOOLSS_RFNPCNEX				0x43
#define SPOOLSS_OPENPRINTEREX				0x45
#define SPOOLSS_ADDPRINTEREX				0x46
#define SPOOLSS_ENUMPRINTERDATA				0x48
#define SPOOLSS_DELETEPRINTERDATA			0x49
#define SPOOLSS_SETPRINTERDATAEX			0x4d
#define SPOOLSS_GETPRINTERDATAEX			0x4e
#define SPOOLSS_ENUMPRINTERDATAEX			0x4f
#define SPOOLSS_ENUMPRINTERKEY				0x50
#define SPOOLSS_DELETEPRINTERDATAEX			0x51
#define SPOOLSS_DELETEPRINTERDRIVEREX			0x54
#define SPOOLSS_ADDPRINTERDRIVEREX			0x59

/* Form types */

#define SPOOLSS_FORM_USER    0
#define SPOOLSS_FORM_BUILTIN 1
#define SPOOLSS_FORM_PRINTER 2

/* Printer change notification flags */

#define SPOOLSS_PRINTER_CHANGE_ADD_PRINTER			0x00000001
#define SPOOLSS_PRINTER_CHANGE_SET_PRINTER			0x00000002
#define SPOOLSS_PRINTER_CHANGE_DELETE_PRINTER			0x00000004
#define SPOOLSS_PRINTER_CHANGE_FAILED_CONNECTION_PRINTER	0x00000008
#define SPOOLSS_PRINTER_CHANGE_PRINTER	(SPOOLSS_PRINTER_CHANGE_ADD_PRINTER | \
				 SPOOLSS_PRINTER_CHANGE_SET_PRINTER | \
				 SPOOLSS_PRINTER_CHANGE_DELETE_PRINTER | \
				 SPOOLSS_PRINTER_CHANGE_FAILED_CONNECTION_PRINTER )
#define SPOOLSS_PRINTER_CHANGE_ADD_JOB				0x00000100
#define SPOOLSS_PRINTER_CHANGE_SET_JOB				0x00000200
#define SPOOLSS_PRINTER_CHANGE_DELETE_JOB			0x00000400
#define SPOOLSS_PRINTER_CHANGE_WRITE_JOB			0x00000800
#define SPOOLSS_PRINTER_CHANGE_JOB	(SPOOLSS_PRINTER_CHANGE_ADD_JOB | \
				 SPOOLSS_PRINTER_CHANGE_SET_JOB | \
				 SPOOLSS_PRINTER_CHANGE_DELETE_JOB | \
				 SPOOLSS_PRINTER_CHANGE_WRITE_JOB )
#define SPOOLSS_PRINTER_CHANGE_ADD_FORM				0x00010000
#define SPOOLSS_PRINTER_CHANGE_SET_FORM				0x00020000
#define SPOOLSS_PRINTER_CHANGE_DELETE_FORM			0x00040000
#define SPOOLSS_PRINTER_CHANGE_FORM	(SPOOLSS_PRINTER_CHANGE_ADD_FORM | \
				 SPOOLSS_PRINTER_CHANGE_SET_FORM | \
				 SPOOLSS_PRINTER_CHANGE_DELETE_FORM )

#define SPOOLSS_PRINTER_CHANGE_ADD_PORT				0x00100000
#define SPOOLSS_PRINTER_CHANGE_CONFIGURE_PORT			0x00200000
#define SPOOLSS_PRINTER_CHANGE_DELETE_PORT			0x00400000
#define SPOOLSS_PRINTER_CHANGE_PORT	(SPOOLSS_PRINTER_CHANGE_ADD_PORT | \
				 SPOOLSS_PRINTER_CHANGE_CONFIGURE_PORT | \
				 SPOOLSS_PRINTER_CHANGE_DELETE_PORT )

#define SPOOLSS_PRINTER_CHANGE_ADD_PRINT_PROCESSOR		0x01000000
#define SPOOLSS_PRINTER_CHANGE_DELETE_PRINT_PROCESSOR		0x04000000
#define SPOOLSS_PRINTER_CHANGE_PRINT_PROCESSOR	(SPOOLSS_PRINTER_CHANGE_ADD_PRINT_PROCESSOR | \
					 SPOOLSS_PRINTER_CHANGE_DELETE_PRINT_PROCESSOR )

#define SPOOLSS_PRINTER_CHANGE_ADD_PRINTER_DRIVER		0x10000000
#define SPOOLSS_PRINTER_CHANGE_SET_PRINTER_DRIVER		0x20000000
#define SPOOLSS_PRINTER_CHANGE_DELETE_PRINTER_DRIVER		0x40000000
#define SPOOLSS_PRINTER_CHANGE_PRINTER_DRIVER	(SPOOLSS_PRINTER_CHANGE_ADD_PRINTER_DRIVER | \
					 SPOOLSS_PRINTER_CHANGE_SET_PRINTER_DRIVER | \
					 SPOOLSS_PRINTER_CHANGE_DELETE_PRINTER_DRIVER )

#define SPOOLSS_PRINTER_CHANGE_TIMEOUT				0x80000000
#define SPOOLSS_PRINTER_CHANGE_ALL	(SPOOLSS_PRINTER_CHANGE_JOB | \
				 SPOOLSS_PRINTER_CHANGE_FORM | \
				 SPOOLSS_PRINTER_CHANGE_PORT | \
				 SPOOLSS_PRINTER_CHANGE_PRINT_PROCESSOR | \
				 SPOOLSS_PRINTER_CHANGE_PRINTER_DRIVER )

/* Printer notify option types */

#define PRINTER_NOTIFY_TYPE 0x00
#define JOB_NOTIFY_TYPE     0x01

/* Printer notify option flags */

#define PRINTER_NOTIFY_OPTIONS_REFRESH  	0x01

/* Printer notify options */

#define PRINTER_NOTIFY_SERVER_NAME		0x00
#define PRINTER_NOTIFY_PRINTER_NAME		0x01
#define PRINTER_NOTIFY_SHARE_NAME		0x02
#define PRINTER_NOTIFY_PORT_NAME		0x03
#define PRINTER_NOTIFY_DRIVER_NAME		0x04
#define PRINTER_NOTIFY_COMMENT			0x05
#define PRINTER_NOTIFY_LOCATION			0x06
#define PRINTER_NOTIFY_DEVMODE			0x07
#define PRINTER_NOTIFY_SEPFILE			0x08
#define PRINTER_NOTIFY_PRINT_PROCESSOR		0x09
#define PRINTER_NOTIFY_PARAMETERS		0x0A
#define PRINTER_NOTIFY_DATATYPE			0x0B
#define PRINTER_NOTIFY_SECURITY_DESCRIPTOR	0x0C
#define PRINTER_NOTIFY_ATTRIBUTES		0x0D
#define PRINTER_NOTIFY_PRIORITY			0x0E
#define PRINTER_NOTIFY_DEFAULT_PRIORITY		0x0F
#define PRINTER_NOTIFY_START_TIME		0x10
#define PRINTER_NOTIFY_UNTIL_TIME		0x11
#define PRINTER_NOTIFY_STATUS			0x12
#define PRINTER_NOTIFY_STATUS_STRING		0x13
#define PRINTER_NOTIFY_CJOBS			0x14
#define PRINTER_NOTIFY_AVERAGE_PPM		0x15
#define PRINTER_NOTIFY_TOTAL_PAGES		0x16
#define PRINTER_NOTIFY_PAGES_PRINTED		0x17
#define PRINTER_NOTIFY_TOTAL_BYTES		0x18
#define PRINTER_NOTIFY_BYTES_PRINTED		0x19

/* Job notify options */

#define JOB_NOTIFY_PRINTER_NAME			0x00
#define JOB_NOTIFY_MACHINE_NAME			0x01
#define JOB_NOTIFY_PORT_NAME			0x02
#define JOB_NOTIFY_USER_NAME			0x03
#define JOB_NOTIFY_NOTIFY_NAME			0x04
#define JOB_NOTIFY_DATATYPE			0x05
#define JOB_NOTIFY_PRINT_PROCESSOR		0x06
#define JOB_NOTIFY_PARAMETERS			0x07
#define JOB_NOTIFY_DRIVER_NAME			0x08
#define JOB_NOTIFY_DEVMODE			0x09
#define JOB_NOTIFY_STATUS			0x0A
#define JOB_NOTIFY_STATUS_STRING		0x0B
#define JOB_NOTIFY_SECURITY_DESCRIPTOR		0x0C
#define JOB_NOTIFY_DOCUMENT			0x0D
#define JOB_NOTIFY_PRIORITY			0x0E
#define JOB_NOTIFY_POSITION			0x0F
#define JOB_NOTIFY_SUBMITTED			0x10
#define JOB_NOTIFY_START_TIME			0x11
#define JOB_NOTIFY_UNTIL_TIME			0x12
#define JOB_NOTIFY_TIME				0x13
#define JOB_NOTIFY_TOTAL_PAGES			0x14
#define JOB_NOTIFY_PAGES_PRINTED		0x15
#define JOB_NOTIFY_TOTAL_BYTES			0x16
#define JOB_NOTIFY_BYTES_PRINTED		0x17

/* Printer status codes */

#define PRINTER_STATUS_OK               0x00000000
#define PRINTER_STATUS_PAUSED		0x00000001
#define PRINTER_STATUS_ERROR		0x00000002
#define PRINTER_STATUS_PENDING_DELETION	0x00000004
#define PRINTER_STATUS_PAPER_JAM	0x00000008
#define PRINTER_STATUS_PAPER_OUT	0x00000010
#define PRINTER_STATUS_MANUAL_FEED	0x00000020
#define PRINTER_STATUS_PAPER_PROBLEM	0x00000040
#define PRINTER_STATUS_OFFLINE		0x00000080
#define PRINTER_STATUS_IO_ACTIVE	0x00000100
#define PRINTER_STATUS_BUSY		0x00000200
#define PRINTER_STATUS_PRINTING		0x00000400
#define PRINTER_STATUS_OUTPUT_BIN_FULL	0x00000800
#define PRINTER_STATUS_NOT_AVAILABLE	0x00001000
#define PRINTER_STATUS_WAITING		0x00002000
#define PRINTER_STATUS_PROCESSING	0x00004000
#define PRINTER_STATUS_INITIALIZING	0x00008000
#define PRINTER_STATUS_WARMING_UP	0x00010000
#define PRINTER_STATUS_TONER_LOW	0x00020000
#define PRINTER_STATUS_NO_TONER		0x00040000
#define PRINTER_STATUS_PAGE_PUNT	0x00080000
#define PRINTER_STATUS_USER_INTERVENTION 0x00100000
#define PRINTER_STATUS_OUT_OF_MEMORY	0x00200000
#define PRINTER_STATUS_DOOR_OPEN	0x00400000
#define PRINTER_STATUS_SERVER_UNKNOWN	0x00800000
#define PRINTER_STATUS_POWER_SAVE	0x01000000

/* Job status codes */

#define JOB_STATUS_PAUSED		0x00000001
#define JOB_STATUS_ERROR		0x00000002
#define JOB_STATUS_DELETING		0x00000004
#define JOB_STATUS_SPOOLING		0x00000008
#define JOB_STATUS_PRINTING		0x00000010
#define JOB_STATUS_OFFLINE		0x00000020
#define JOB_STATUS_PAPEROUT		0x00000040
#define JOB_STATUS_PRINTED		0x00000080
#define JOB_STATUS_DELETED		0x00000100
#define JOB_STATUS_BLOCKED		0x00000200
#define JOB_STATUS_USER_INTERVENTION	0x00000400

/* Printer attributes */

#define PRINTER_ATTRIBUTE_QUEUED		0x00000001
#define PRINTER_ATTRIBUTE_DIRECT		0x00000002
#define PRINTER_ATTRIBUTE_DEFAULT		0x00000004
#define PRINTER_ATTRIBUTE_SHARED		0x00000008
#define PRINTER_ATTRIBUTE_NETWORK		0x00000010
#define PRINTER_ATTRIBUTE_HIDDEN		0x00000020
#define PRINTER_ATTRIBUTE_LOCAL			0x00000040
#define PRINTER_ATTRIBUTE_ENABLE_DEVQ		0x00000080
#define PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS	0x00000100
#define PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST	0x00000200
#define PRINTER_ATTRIBUTE_WORK_OFFLINE		0x00000400
#define PRINTER_ATTRIBUTE_ENABLE_BIDI		0x00000800
#define PRINTER_ATTRIBUTE_RAW_ONLY		0x00001000
#define PRINTER_ATTRIBUTE_PUBLISHED             0x00002000

/* Setprinter control commands */

#define SPOOLSS_PRINTER_CONTROL_UNPAUSE		0x00000000
#define SPOOLSS_PRINTER_CONTROL_PAUSE		0x00000001
#define SPOOLSS_PRINTER_CONTROL_RESUME		0x00000002
#define SPOOLSS_PRINTER_CONTROL_PURGE		0x00000003
#define SPOOLSS_PRINTER_CONTROL_SET_STATUS	0x00000004

/* Specific access rights */

#define SERVER_ACCESS_ADMINISTER	0x00000001
#define SERVER_ACCESS_ENUMERATE		0x00000002
#define PRINTER_ACCESS_ADMINISTER	0x00000004
#define PRINTER_ACCESS_USE		0x00000008
#define JOB_ACCESS_ADMINISTER		0x00000010

/* Enumprinters flags */

#define PRINTER_ENUM_DEFAULT		0x00000001
#define PRINTER_ENUM_LOCAL		0x00000002
#define PRINTER_ENUM_CONNECTIONS	0x00000004
#define PRINTER_ENUM_FAVORITE		0x00000004
#define PRINTER_ENUM_NAME		0x00000008
#define PRINTER_ENUM_REMOTE		0x00000010
#define PRINTER_ENUM_SHARED		0x00000020
#define PRINTER_ENUM_NETWORK		0x00000040

/* Devicemode field flags */

#define DEVMODE_ORIENTATION		0x00000001
#define DEVMODE_PAPERSIZE		0x00000002
#define DEVMODE_PAPERLENGTH		0x00000004
#define DEVMODE_PAPERWIDTH		0x00000008
#define DEVMODE_SCALE			0x00000010
#define DEVMODE_POSITION		0x00000020
#define DEVMODE_NUP			0x00000040
#define DEVMODE_COPIES			0x00000100
#define DEVMODE_DEFAULTSOURCE		0x00000200
#define DEVMODE_PRINTQUALITY		0x00000400
#define DEVMODE_COLOR			0x00000800
#define DEVMODE_DUPLEX			0x00001000
#define DEVMODE_YRESOLUTION		0x00002000
#define DEVMODE_TTOPTION		0x00004000
#define DEVMODE_COLLATE			0x00008000
#define DEVMODE_FORMNAME		0x00010000
#define DEVMODE_LOGPIXELS		0x00020000
#define DEVMODE_BITSPERPEL		0x00040000
#define DEVMODE_PELSWIDTH		0x00080000
#define DEVMODE_PELSHEIGHT		0x00100000
#define DEVMODE_DISPLAYFLAGS		0x00200000
#define DEVMODE_DISPLAYFREQUENCY	0x00400000
#define DEVMODE_ICMMETHOD		0x00800000
#define DEVMODE_ICMINTENT		0x01000000
#define DEVMODE_MEDIATYPE		0x02000000
#define DEVMODE_DITHERTYPE		0x04000000
#define DEVMODE_PANNINGWIDTH		0x08000000
#define DEVMODE_PANNINGHEIGHT		0x10000000

/* Devicemode paper orientation */

#define DEVMODE_ORIENTATION_PORTRAIT    1
#define DEVMODE_ORIENTATION_LANDSCAPE   2

/* Devicemode paper size */

#define DEVMODE_PAPERSIZE_LETTER                 1
#define DEVMODE_PAPERSIZE_LETTERSMALL            2
#define DEVMODE_PAPERSIZE_TABLOID                3
#define DEVMODE_PAPERSIZE_LEDGER		 4
#define DEVMODE_PAPERSIZE_LEGAL		         5
#define DEVMODE_PAPERSIZE_STATEMENT	         6
#define DEVMODE_PAPERSIZE_EXECUTIVE		 7
#define DEVMODE_PAPERSIZE_A3			 8
#define DEVMODE_PAPERSIZE_A4			 9
#define DEVMODE_PAPERSIZE_A4SMALL		10
#define DEVMODE_PAPERSIZE_A5			11
#define DEVMODE_PAPERSIZE_B4			12
#define DEVMODE_PAPERSIZE_B5			13
#define DEVMODE_PAPERSIZE_FOLIO			14
#define DEVMODE_PAPERSIZE_QUARTO		15
#define DEVMODE_PAPERSIZE_10X14			16
#define DEVMODE_PAPERSIZE_11X17			17
#define DEVMODE_PAPERSIZE_NOTE			18
#define DEVMODE_PAPERSIZE_ENV9			19
#define DEVMODE_PAPERSIZE_ENV10			20
#define DEVMODE_PAPERSIZE_ENV11			21
#define DEVMODE_PAPERSIZE_ENV12			22
#define DEVMODE_PAPERSIZE_ENV14			23
#define DEVMODE_PAPERSIZE_CSHEET		24
#define DEVMODE_PAPERSIZE_DSHEET		25
#define DEVMODE_PAPERSIZE_ESHEET		26
#define DEVMODE_PAPERSIZE_ENVDL			27
#define DEVMODE_PAPERSIZE_ENVC5			28
#define DEVMODE_PAPERSIZE_ENVC3			29
#define DEVMODE_PAPERSIZE_ENVC4			30
#define DEVMODE_PAPERSIZE_ENVC6			31
#define DEVMODE_PAPERSIZE_ENVC65		32
#define DEVMODE_PAPERSIZE_ENVB4			33
#define DEVMODE_PAPERSIZE_ENVB5			34
#define DEVMODE_PAPERSIZE_ENVB6			35
#define DEVMODE_PAPERSIZE_ENVITALY		36
#define DEVMODE_PAPERSIZE_ENVMONARCH		37
#define DEVMODE_PAPERSIZE_ENVPERSONAL		38
#define DEVMODE_PAPERSIZE_FANFOLDUS		39
#define DEVMODE_PAPERSIZE_FANFOLDSTDGERMAN	40
#define DEVMODE_PAPERSIZE_FANFOLDLGLGERMAN	41
#define DEVMODE_PAPERSIZE_ISOB4			42
#define DEVMODE_PAPERSIZE_JAPANESEPOSTCARD	43
#define DEVMODE_PAPERSIZE_9X11			44
#define DEVMODE_PAPERSIZE_10X11			45
#define DEVMODE_PAPERSIZE_15X11			46
#define DEVMODE_PAPERSIZE_ENVINVITE		47
#define DEVMODE_PAPERSIZE_RESERVED48		48
#define DEVMODE_PAPERSIZE_RESERVED49		49
#define DEVMODE_PAPERSIZE_LETTEREXTRA		50
#define DEVMODE_PAPERSIZE_LEGALEXTRA		51
#define DEVMODE_PAPERSIZE_TABLOIDEXTRA		52
#define DEVMODE_PAPERSIZE_A4EXTRA		53
#define DEVMODE_PAPERSIZE_LETTERTRANS		54
#define DEVMODE_PAPERSIZE_A4TRANS		55
#define DEVMODE_PAPERSIZE_LETTEREXTRATRANS	56
#define DEVMODE_PAPERSIZE_APLUS			57
#define DEVMODE_PAPERSIZE_BPLUS			58
#define DEVMODE_PAPERSIZE_LETTERPLUS            59
#define DEVMODE_PAPERSIZE_A4PLUS                60
#define DEVMODE_PAPERSIZE_A5TRANS		61
#define DEVMODE_PAPERSIZE_B5TRANS		62
#define DEVMODE_PAPERSIZE_A3EXTRA		63
#define DEVMODE_PAPERSIZE_A5EXTRA		64
#define DEVMODE_PAPERSIZE_B5EXTRA		65
#define DEVMODE_PAPERSIZE_A2			66
#define DEVMODE_PAPERSIZE_A3TRANS		67
#define DEVMODE_PAPERSIZE_A3EXTRATRANS		68
#define DEVMODE_PAPERSIZE_DBLJAPANESEPOSTCARD	69
#define DEVMODE_PAPERSIZE_A6			70
#define DEVMODE_PAPERSIZE_JENVKAKU2		71
#define DEVMODE_PAPERSIZE_JENVKAKU3		72
#define DEVMODE_PAPERSIZE_JENVCHOU3		73
#define DEVMODE_PAPERSIZE_JENVCHOU4		74
#define DEVMODE_PAPERSIZE_LETTERROT		75
#define DEVMODE_PAPERSIZE_A3ROT			76
#define DEVMODE_PAPERSIZE_A4ROT			77
#define DEVMODE_PAPERSIZE_A5ROT			78
#define DEVMODE_PAPERSIZE_B4JISROT		79
#define DEVMODE_PAPERSIZE_B5JISROT		80
#define DEVMODE_PAPERSIZE_JAPANESEPOSTCARDROT	81
#define DEVMODE_PAPERSIZE_DBLJAPANESEPOSTCARDROT82 82
#define DEVMODE_PAPERSIZE_A6ROT			83
#define DEVMODE_PAPERSIZE_JENVKAKU2ROT		84
#define DEVMODE_PAPERSIZE_JENVKAKU3ROT		85
#define DEVMODE_PAPERSIZE_JENVCHOU3ROT		86
#define DEVMODE_PAPERSIZE_JENVCHOU4ROT		87
#define DEVMODE_PAPERSIZE_B6JIS			88
#define DEVMODE_PAPERSIZE_B6JISROT		89
#define DEVMODE_PAPERSIZE_12X11			90
#define DEVMODE_PAPERSIZE_JENVYOU4		91
#define DEVMODE_PAPERSIZE_JENVYOU4ROT		92
#define DEVMODE_PAPERSIZE_P16K			93
#define DEVMODE_PAPERSIZE_P32K			94
#define DEVMODE_PAPERSIZE_P32KBIG		95
#define DEVMODE_PAPERSIZE_PENV1			96
#define DEVMODE_PAPERSIZE_PENV2			97
#define DEVMODE_PAPERSIZE_PENV3			98
#define DEVMODE_PAPERSIZE_PENV4			99
#define DEVMODE_PAPERSIZE_PENV5			100
#define DEVMODE_PAPERSIZE_PENV6			101
#define DEVMODE_PAPERSIZE_PENV7			102
#define DEVMODE_PAPERSIZE_PENV8			103
#define DEVMODE_PAPERSIZE_PENV9			104
#define DEVMODE_PAPERSIZE_PENV10		105
#define DEVMODE_PAPERSIZE_P16KROT		106
#define DEVMODE_PAPERSIZE_P32KROT		107
#define DEVMODE_PAPERSIZE_P32KBIGROT		108
#define DEVMODE_PAPERSIZE_PENV1ROT		109
#define DEVMODE_PAPERSIZE_PENV2ROT		110
#define DEVMODE_PAPERSIZE_PENV3ROT		111
#define DEVMODE_PAPERSIZE_PENV4ROT		112
#define DEVMODE_PAPERSIZE_PENV5ROT		113
#define DEVMODE_PAPERSIZE_PENV6ROT		114
#define DEVMODE_PAPERSIZE_PENV7ROT		115
#define DEVMODE_PAPERSIZE_PENV8ROT		116
#define DEVMODE_PAPERSIZE_PENV9ROT		117
#define DEVMODE_PAPERSIZE_PENV10ROT		118

/* Devicemode paper source */

#define DEVMODE_PAPERSOURCE_UPPER               1
#define DEVMODE_PAPERSOURCE_LOWER               2
#define DEVMODE_PAPERSOURCE_MIDDLE              3
#define DEVMODE_PAPERSOURCE_MANUAL              4
#define DEVMODE_PAPERSOURCE_ENV                 5
#define DEVMODE_PAPERSOURCE_ENVMANUAL           6
#define DEVMODE_PAPERSOURCE_AUTO                7
#define DEVMODE_PAPERSOURCE_TRACTOR             8
#define DEVMODE_PAPERSOURCE_SMALLFMT            9
#define DEVMODE_PAPERSOURCE_LARGEFMAT           10
#define DEVMODE_PAPERSOURCE_LARGECAP            11
#define DEVMODE_PAPERSOURCE_CASSETTE            12
#define DEVMODE_PAPERSOURCE_FORMSRC             13

/* Devicemode print quality */

#define DEVMODE_PRINTQUALITY_HIGH               -1
#define DEVMODE_PRINTQUALITY_MEDIUM             -2
#define DEVMODE_PRINTQUALITY_LOW                -3
#define DEVMODE_PRINTQUALITY_DRAFT              -4

/* Colour settings */

#define DEVMODE_COLOUR_MONO   1
#define DEVMODE_COLOUR_COLOUR 2

/* TrueType options */

#define DEVMODE_TTOPTION_BITMAP              1
#define DEVMODE_TTOPTION_DOWNLOAD            2
#define DEVMODE_TTOPTION_SUBDEV              3
#define DEVMODE_TTOPTION_DOWNLOAD_OUTLINE    4

/* Collate info */

#define DEVMODE_COLLATE_FALSE 0
#define DEVMODE_COLLATE_TRUE  1

/* Duplex info */

#define DEVMODE_DUPLEX_SIMPLEX   1
#define DEVMODE_DUPLEX_VERT      2
#define DEVMODE_DUPLEX_HORIZ     3

/* Displayflags */

#define DEVMODE_DISPLAYFLAGS_GRAYSCALE    1
#define DEVMODE_DISPLAYFLAGS_INTERLACED   2

/* ICM method */

#define DEVMODE_ICMMETHOD_NONE      1
#define DEVMODE_ICMMETHOD_SYSTEM    2
#define DEVMODE_ICMMETHOD_DRIVER    3
#define DEVMODE_ICMMETHOD_DEVICE    4

/* ICM intent */

#define DEVMODE_ICMINTENT_SATURATE         1
#define DEVMODE_ICMINTENT_CONTRAST         2
#define DEVMODE_ICMINTENT_COLORIMETRIC     3
#define DEVMODE_ICMINTENT_ABS_COLORIMETRIC 4

/* Media type */

#define DEVMODE_MEDIATYPE_STANDARD     1
#define DEVMODE_MEDIATYPE_TRANSPARENCY 2
#define DEVMODE_MEDIATYPE_GLOSSY       3

/* Dither type */

#define DEVMODE_DITHERTYPE_NONE           1
#define DEVMODE_DITHERTYPE_COARSE         2
#define DEVMODE_DITHERTYPE_LINE           3
#define DEVMODE_DITHERTYPE_LINEART        4
#define DEVMODE_DITHERTYPE_ERRORDIFFUSION 5
#define DEVMODE_DITHERTYPE_RESERVED6      6
#define DEVMODE_DITHERTYPE_RESERVED7      7
#define DEVMODE_DITHERTYPE_GRAYSCALE      10

/* Printer info level 7 */

#define DS_PUBLISH   1
#define DS_UPDATE    2
#define DS_UNPUBLISH 3

/* SetJob command values */

#define JOB_CONTROL_PAUSE              1
#define JOB_CONTROL_RESUME             2
#define JOB_CONTROL_CANCEL             3
#define JOB_CONTROL_RESTART            4
#define JOB_CONTROL_DELETE             5

#endif /* packet-dcerpc-spoolss.h */
