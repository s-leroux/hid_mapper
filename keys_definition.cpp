/*
 * This file is part of hid_mapper.
 * 
 * hid_mapper is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * hid_mapper is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hid_mapper. If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author: Thibault Kummer <bob@coldsource.net>
 */

#include <keys_definition.h>

#include <linux/input.h>

const char *keys_char[] = {
#ifdef KEY_0
	"KEY_0",
#endif
#ifdef KEY_1
	"KEY_1",
#endif
#ifdef KEY_102ND
	"KEY_102ND",
#endif
#ifdef KEY_2
	"KEY_2",
#endif
#ifdef KEY_3
	"KEY_3",
#endif
#ifdef KEY_4
	"KEY_4",
#endif
#ifdef KEY_5
	"KEY_5",
#endif
#ifdef KEY_6
	"KEY_6",
#endif
#ifdef KEY_7
	"KEY_7",
#endif
#ifdef KEY_8
	"KEY_8",
#endif
#ifdef KEY_9
	"KEY_9",
#endif
#ifdef KEY_A
	"KEY_A",
#endif
#ifdef KEY_AB
	"KEY_AB",
#endif
#ifdef KEY_ADDRESSBOOK
	"KEY_ADDRESSBOOK",
#endif
#ifdef KEY_AGAIN
	"KEY_AGAIN",
#endif
#ifdef KEY_ALTERASE
	"KEY_ALTERASE",
#endif
#ifdef KEY_ANGLE
	"KEY_ANGLE",
#endif
#ifdef KEY_APOSTROPHE
	"KEY_APOSTROPHE",
#endif
#ifdef KEY_ARCHIVE
	"KEY_ARCHIVE",
#endif
#ifdef KEY_AUDIO
	"KEY_AUDIO",
#endif
#ifdef KEY_AUX
	"KEY_AUX",
#endif
#ifdef KEY_B
	"KEY_B",
#endif
#ifdef KEY_BACK
	"KEY_BACK",
#endif
#ifdef KEY_BACKSLASH
	"KEY_BACKSLASH",
#endif
#ifdef KEY_BACKSPACE
	"KEY_BACKSPACE",
#endif
#ifdef KEY_BASSBOOST
	"KEY_BASSBOOST",
#endif
#ifdef KEY_BATTERY
	"KEY_BATTERY",
#endif
#ifdef KEY_BLUE
	"KEY_BLUE",
#endif
#ifdef KEY_BLUETOOTH
	"KEY_BLUETOOTH",
#endif
#ifdef KEY_BOOKMARKS
	"KEY_BOOKMARKS",
#endif
#ifdef KEY_BREAK
	"KEY_BREAK",
#endif
#ifdef KEY_BRIGHTNESS_CYCLE
	"KEY_BRIGHTNESS_CYCLE",
#endif
#ifdef KEY_BRIGHTNESSDOWN
	"KEY_BRIGHTNESSDOWN",
#endif
#ifdef KEY_BRIGHTNESSUP
	"KEY_BRIGHTNESSUP",
#endif
#ifdef KEY_BRIGHTNESS_ZERO
	"KEY_BRIGHTNESS_ZERO",
#endif
#ifdef KEY_BRL_DOT1
	"KEY_BRL_DOT1",
#endif
#ifdef KEY_BRL_DOT10
	"KEY_BRL_DOT10",
#endif
#ifdef KEY_BRL_DOT2
	"KEY_BRL_DOT2",
#endif
#ifdef KEY_BRL_DOT3
	"KEY_BRL_DOT3",
#endif
#ifdef KEY_BRL_DOT4
	"KEY_BRL_DOT4",
#endif
#ifdef KEY_BRL_DOT5
	"KEY_BRL_DOT5",
#endif
#ifdef KEY_BRL_DOT6
	"KEY_BRL_DOT6",
#endif
#ifdef KEY_BRL_DOT7
	"KEY_BRL_DOT7",
#endif
#ifdef KEY_BRL_DOT8
	"KEY_BRL_DOT8",
#endif
#ifdef KEY_BRL_DOT9
	"KEY_BRL_DOT9",
#endif
#ifdef KEY_C
	"KEY_C",
#endif
#ifdef KEY_CALC
	"KEY_CALC",
#endif
#ifdef KEY_CALENDAR
	"KEY_CALENDAR",
#endif
#ifdef KEY_CAMERA
	"KEY_CAMERA",
#endif
#ifdef KEY_CAMERA_FOCUS
	"KEY_CAMERA_FOCUS",
#endif
#ifdef KEY_CANCEL
	"KEY_CANCEL",
#endif
#ifdef KEY_CAPSLOCK
	"KEY_CAPSLOCK",
#endif
#ifdef KEY_CD
	"KEY_CD",
#endif
#ifdef KEY_CHANNEL
	"KEY_CHANNEL",
#endif
#ifdef KEY_CHANNELDOWN
	"KEY_CHANNELDOWN",
#endif
#ifdef KEY_CHANNELUP
	"KEY_CHANNELUP",
#endif
#ifdef KEY_CHAT
	"KEY_CHAT",
#endif
#ifdef KEY_CLEAR
	"KEY_CLEAR",
#endif
#ifdef KEY_CLOSE
	"KEY_CLOSE",
#endif
#ifdef KEY_CLOSECD
	"KEY_CLOSECD",
#endif
#ifdef KEY_COFFEE
	"KEY_COFFEE",
#endif
#ifdef KEY_COMMA
	"KEY_COMMA",
#endif
#ifdef KEY_COMPOSE
	"KEY_COMPOSE",
#endif
#ifdef KEY_COMPUTER
	"KEY_COMPUTER",
#endif
#ifdef KEY_CONFIG
	"KEY_CONFIG",
#endif
#ifdef KEY_CONNECT
	"KEY_CONNECT",
#endif
#ifdef KEY_CONTEXT_MENU
	"KEY_CONTEXT_MENU",
#endif
#ifdef KEY_COPY
	"KEY_COPY",
#endif
#ifdef KEY_CUT
	"KEY_CUT",
#endif
#ifdef KEY_CYCLEWINDOWS
	"KEY_CYCLEWINDOWS",
#endif
#ifdef KEY_D
	"KEY_D",
#endif
#ifdef KEY_DASHBOARD
	"KEY_DASHBOARD",
#endif
#ifdef KEY_DATABASE
	"KEY_DATABASE",
#endif
#ifdef KEY_DEL_EOL
	"KEY_DEL_EOL",
#endif
#ifdef KEY_DEL_EOS
	"KEY_DEL_EOS",
#endif
#ifdef KEY_DELETE
	"KEY_DELETE",
#endif
#ifdef KEY_DELETEFILE
	"KEY_DELETEFILE",
#endif
#ifdef KEY_DEL_LINE
	"KEY_DEL_LINE",
#endif
#ifdef KEY_DIGITS
	"KEY_DIGITS",
#endif
#ifdef KEY_DIRECTION
	"KEY_DIRECTION",
#endif
#ifdef KEY_DIRECTORY
	"KEY_DIRECTORY",
#endif
#ifdef KEY_DISPLAY_OFF
	"KEY_DISPLAY_OFF",
#endif
#ifdef KEY_DISPLAYTOGGLE
	"KEY_DISPLAYTOGGLE",
#endif
#ifdef KEY_DOCUMENTS
	"KEY_DOCUMENTS",
#endif
#ifdef KEY_DOLLAR
	"KEY_DOLLAR",
#endif
#ifdef KEY_DOT
	"KEY_DOT",
#endif
#ifdef KEY_DOWN
	"KEY_DOWN",
#endif
#ifdef KEY_DVD
	"KEY_DVD",
#endif
#ifdef KEY_E
	"KEY_E",
#endif
#ifdef KEY_EDIT
	"KEY_EDIT",
#endif
#ifdef KEY_EDITOR
	"KEY_EDITOR",
#endif
#ifdef KEY_EJECTCD
	"KEY_EJECTCD",
#endif
#ifdef KEY_EJECTCLOSECD
	"KEY_EJECTCLOSECD",
#endif
#ifdef KEY_EMAIL
	"KEY_EMAIL",
#endif
#ifdef KEY_END
	"KEY_END",
#endif
#ifdef KEY_ENTER
	"KEY_ENTER",
#endif
#ifdef KEY_EPG
	"KEY_EPG",
#endif
#ifdef KEY_EQUAL
	"KEY_EQUAL",
#endif
#ifdef KEY_ESC
	"KEY_ESC",
#endif
#ifdef KEY_EURO
	"KEY_EURO",
#endif
#ifdef KEY_EXIT
	"KEY_EXIT",
#endif
#ifdef KEY_F
	"KEY_F",
#endif
#ifdef KEY_F1
	"KEY_F1",
#endif
#ifdef KEY_F10
	"KEY_F10",
#endif
#ifdef KEY_F11
	"KEY_F11",
#endif
#ifdef KEY_F12
	"KEY_F12",
#endif
#ifdef KEY_F13
	"KEY_F13",
#endif
#ifdef KEY_F14
	"KEY_F14",
#endif
#ifdef KEY_F15
	"KEY_F15",
#endif
#ifdef KEY_F16
	"KEY_F16",
#endif
#ifdef KEY_F17
	"KEY_F17",
#endif
#ifdef KEY_F18
	"KEY_F18",
#endif
#ifdef KEY_F19
	"KEY_F19",
#endif
#ifdef KEY_F2
	"KEY_F2",
#endif
#ifdef KEY_F20
	"KEY_F20",
#endif
#ifdef KEY_F21
	"KEY_F21",
#endif
#ifdef KEY_F22
	"KEY_F22",
#endif
#ifdef KEY_F23
	"KEY_F23",
#endif
#ifdef KEY_F24
	"KEY_F24",
#endif
#ifdef KEY_F3
	"KEY_F3",
#endif
#ifdef KEY_F4
	"KEY_F4",
#endif
#ifdef KEY_F5
	"KEY_F5",
#endif
#ifdef KEY_F6
	"KEY_F6",
#endif
#ifdef KEY_F7
	"KEY_F7",
#endif
#ifdef KEY_F8
	"KEY_F8",
#endif
#ifdef KEY_F9
	"KEY_F9",
#endif
#ifdef KEY_FASTFORWARD
	"KEY_FASTFORWARD",
#endif
#ifdef KEY_FAVORITES
	"KEY_FAVORITES",
#endif
#ifdef KEY_FILE
	"KEY_FILE",
#endif
#ifdef KEY_FINANCE
	"KEY_FINANCE",
#endif
#ifdef KEY_FIND
	"KEY_FIND",
#endif
#ifdef KEY_FIRST
	"KEY_FIRST",
#endif
#ifdef KEY_FN
	"KEY_FN",
#endif
#ifdef KEY_FN_1
	"KEY_FN_1",
#endif
#ifdef KEY_FN_2
	"KEY_FN_2",
#endif
#ifdef KEY_FN_B
	"KEY_FN_B",
#endif
#ifdef KEY_FN_D
	"KEY_FN_D",
#endif
#ifdef KEY_FN_E
	"KEY_FN_E",
#endif
#ifdef KEY_FN_ESC
	"KEY_FN_ESC",
#endif
#ifdef KEY_FN_F
	"KEY_FN_F",
#endif
#ifdef KEY_FN_F1
	"KEY_FN_F1",
#endif
#ifdef KEY_FN_F10
	"KEY_FN_F10",
#endif
#ifdef KEY_FN_F11
	"KEY_FN_F11",
#endif
#ifdef KEY_FN_F12
	"KEY_FN_F12",
#endif
#ifdef KEY_FN_F2
	"KEY_FN_F2",
#endif
#ifdef KEY_FN_F3
	"KEY_FN_F3",
#endif
#ifdef KEY_FN_F4
	"KEY_FN_F4",
#endif
#ifdef KEY_FN_F5
	"KEY_FN_F5",
#endif
#ifdef KEY_FN_F6
	"KEY_FN_F6",
#endif
#ifdef KEY_FN_F7
	"KEY_FN_F7",
#endif
#ifdef KEY_FN_F8
	"KEY_FN_F8",
#endif
#ifdef KEY_FN_F9
	"KEY_FN_F9",
#endif
#ifdef KEY_FN_S
	"KEY_FN_S",
#endif
#ifdef KEY_FORWARD
	"KEY_FORWARD",
#endif
#ifdef KEY_FORWARDMAIL
	"KEY_FORWARDMAIL",
#endif
#ifdef KEY_FRAMEBACK
	"KEY_FRAMEBACK",
#endif
#ifdef KEY_FRAMEFORWARD
	"KEY_FRAMEFORWARD",
#endif
#ifdef KEY_FRONT
	"KEY_FRONT",
#endif
#ifdef KEY_G
	"KEY_G",
#endif
#ifdef KEY_GAMES
	"KEY_GAMES",
#endif
#ifdef KEY_GOTO
	"KEY_GOTO",
#endif
#ifdef KEY_GRAPHICSEDITOR
	"KEY_GRAPHICSEDITOR",
#endif
#ifdef KEY_GRAVE
	"KEY_GRAVE",
#endif
#ifdef KEY_GREEN
	"KEY_GREEN",
#endif
#ifdef KEY_H
	"KEY_H",
#endif
#ifdef KEY_HANGEUL
	"KEY_HANGEUL",
#endif
#ifdef KEY_HANGUEL
	"KEY_HANGUEL",
#endif
#ifdef KEY_HANJA
	"KEY_HANJA",
#endif
#ifdef KEY_HELP
	"KEY_HELP",
#endif
#ifdef KEY_HENKAN
	"KEY_HENKAN",
#endif
#ifdef KEY_HIRAGANA
	"KEY_HIRAGANA",
#endif
#ifdef KEY_HOME
	"KEY_HOME",
#endif
#ifdef KEY_HOMEPAGE
	"KEY_HOMEPAGE",
#endif
#ifdef KEY_HP
	"KEY_HP",
#endif
#ifdef KEY_I
	"KEY_I",
#endif
#ifdef KEY_INFO
	"KEY_INFO",
#endif
#ifdef KEY_INSERT
	"KEY_INSERT",
#endif
#ifdef KEY_INS_LINE
	"KEY_INS_LINE",
#endif
#ifdef KEY_ISO
	"KEY_ISO",
#endif
#ifdef KEY_J
	"KEY_J",
#endif
#ifdef KEY_K
	"KEY_K",
#endif
#ifdef KEY_KATAKANA
	"KEY_KATAKANA",
#endif
#ifdef KEY_KATAKANAHIRAGANA
	"KEY_KATAKANAHIRAGANA",
#endif
#ifdef KEY_KBDILLUMDOWN
	"KEY_KBDILLUMDOWN",
#endif
#ifdef KEY_KBDILLUMTOGGLE
	"KEY_KBDILLUMTOGGLE",
#endif
#ifdef KEY_KBDILLUMUP
	"KEY_KBDILLUMUP",
#endif
#ifdef KEY_KEYBOARD
	"KEY_KEYBOARD",
#endif
#ifdef KEY_KP0
	"KEY_KP0",
#endif
#ifdef KEY_KP1
	"KEY_KP1",
#endif
#ifdef KEY_KP2
	"KEY_KP2",
#endif
#ifdef KEY_KP3
	"KEY_KP3",
#endif
#ifdef KEY_KP4
	"KEY_KP4",
#endif
#ifdef KEY_KP5
	"KEY_KP5",
#endif
#ifdef KEY_KP6
	"KEY_KP6",
#endif
#ifdef KEY_KP7
	"KEY_KP7",
#endif
#ifdef KEY_KP8
	"KEY_KP8",
#endif
#ifdef KEY_KP9
	"KEY_KP9",
#endif
#ifdef KEY_KPASTERISK
	"KEY_KPASTERISK",
#endif
#ifdef KEY_KPCOMMA
	"KEY_KPCOMMA",
#endif
#ifdef KEY_KPDOT
	"KEY_KPDOT",
#endif
#ifdef KEY_KPENTER
	"KEY_KPENTER",
#endif
#ifdef KEY_KPEQUAL
	"KEY_KPEQUAL",
#endif
#ifdef KEY_KPJPCOMMA
	"KEY_KPJPCOMMA",
#endif
#ifdef KEY_KPLEFTPAREN
	"KEY_KPLEFTPAREN",
#endif
#ifdef KEY_KPMINUS
	"KEY_KPMINUS",
#endif
#ifdef KEY_KPPLUS
	"KEY_KPPLUS",
#endif
#ifdef KEY_KPPLUSMINUS
	"KEY_KPPLUSMINUS",
#endif
#ifdef KEY_KPRIGHTPAREN
	"KEY_KPRIGHTPAREN",
#endif
#ifdef KEY_KPSLASH
	"KEY_KPSLASH",
#endif
#ifdef KEY_L
	"KEY_L",
#endif
#ifdef KEY_LANGUAGE
	"KEY_LANGUAGE",
#endif
#ifdef KEY_LAST
	"KEY_LAST",
#endif
#ifdef KEY_LEFT
	"KEY_LEFT",
#endif
#ifdef KEY_LEFTALT
	"KEY_LEFTALT",
#endif
#ifdef KEY_LEFTBRACE
	"KEY_LEFTBRACE",
#endif
#ifdef KEY_LEFTCTRL
	"KEY_LEFTCTRL",
#endif
#ifdef KEY_LEFTMETA
	"KEY_LEFTMETA",
#endif
#ifdef KEY_LEFTSHIFT
	"KEY_LEFTSHIFT",
#endif
#ifdef KEY_LINEFEED
	"KEY_LINEFEED",
#endif
#ifdef KEY_LIST
	"KEY_LIST",
#endif
#ifdef KEY_LOGOFF
	"KEY_LOGOFF",
#endif
#ifdef KEY_M
	"KEY_M",
#endif
#ifdef KEY_MACRO
	"KEY_MACRO",
#endif
#ifdef KEY_MAIL
	"KEY_MAIL",
#endif
#ifdef KEY_MEDIA
	"KEY_MEDIA",
#endif
#ifdef KEY_MEDIA_REPEAT
	"KEY_MEDIA_REPEAT",
#endif
#ifdef KEY_MEMO
	"KEY_MEMO",
#endif
#ifdef KEY_MENU
	"KEY_MENU",
#endif
#ifdef KEY_MESSENGER
	"KEY_MESSENGER",
#endif
#ifdef KEY_MHP
	"KEY_MHP",
#endif
#ifdef KEY_MINUS
	"KEY_MINUS",
#endif
#ifdef KEY_MODE
	"KEY_MODE",
#endif
#ifdef KEY_MOVE
	"KEY_MOVE",
#endif
#ifdef KEY_MP3
	"KEY_MP3",
#endif
#ifdef KEY_MSDOS
	"KEY_MSDOS",
#endif
#ifdef KEY_MUHENKAN
	"KEY_MUHENKAN",
#endif
#ifdef KEY_MUTE
	"KEY_MUTE",
#endif
#ifdef KEY_N
	"KEY_N",
#endif
#ifdef KEY_NEW
	"KEY_NEW",
#endif
#ifdef KEY_NEWS
	"KEY_NEWS",
#endif
#ifdef KEY_NEXT
	"KEY_NEXT",
#endif
#ifdef KEY_NEXTSONG
	"KEY_NEXTSONG",
#endif
#ifdef KEY_NUMERIC_0
	"KEY_NUMERIC_0",
#endif
#ifdef KEY_NUMERIC_1
	"KEY_NUMERIC_1",
#endif
#ifdef KEY_NUMERIC_2
	"KEY_NUMERIC_2",
#endif
#ifdef KEY_NUMERIC_3
	"KEY_NUMERIC_3",
#endif
#ifdef KEY_NUMERIC_4
	"KEY_NUMERIC_4",
#endif
#ifdef KEY_NUMERIC_5
	"KEY_NUMERIC_5",
#endif
#ifdef KEY_NUMERIC_6
	"KEY_NUMERIC_6",
#endif
#ifdef KEY_NUMERIC_7
	"KEY_NUMERIC_7",
#endif
#ifdef KEY_NUMERIC_8
	"KEY_NUMERIC_8",
#endif
#ifdef KEY_NUMERIC_9
	"KEY_NUMERIC_9",
#endif
#ifdef KEY_NUMERIC_POUND
	"KEY_NUMERIC_POUND",
#endif
#ifdef KEY_NUMERIC_STAR
	"KEY_NUMERIC_STAR",
#endif
#ifdef KEY_NUMLOCK
	"KEY_NUMLOCK",
#endif
#ifdef KEY_O
	"KEY_O",
#endif
#ifdef KEY_OK
	"KEY_OK",
#endif
#ifdef KEY_OPEN
	"KEY_OPEN",
#endif
#ifdef KEY_OPTION
	"KEY_OPTION",
#endif
#ifdef KEY_P
	"KEY_P",
#endif
#ifdef KEY_PAGEDOWN
	"KEY_PAGEDOWN",
#endif
#ifdef KEY_PAGEUP
	"KEY_PAGEUP",
#endif
#ifdef KEY_PASTE
	"KEY_PASTE",
#endif
#ifdef KEY_PAUSE
	"KEY_PAUSE",
#endif
#ifdef KEY_PAUSECD
	"KEY_PAUSECD",
#endif
#ifdef KEY_PC
	"KEY_PC",
#endif
#ifdef KEY_PHONE
	"KEY_PHONE",
#endif
#ifdef KEY_PLAY
	"KEY_PLAY",
#endif
#ifdef KEY_PLAYCD
	"KEY_PLAYCD",
#endif
#ifdef KEY_PLAYER
	"KEY_PLAYER",
#endif
#ifdef KEY_PLAYPAUSE
	"KEY_PLAYPAUSE",
#endif
#ifdef KEY_POWER
	"KEY_POWER",
#endif
#ifdef KEY_POWER2
	"KEY_POWER2",
#endif
#ifdef KEY_PRESENTATION
	"KEY_PRESENTATION",
#endif
#ifdef KEY_PREVIOUS
	"KEY_PREVIOUS",
#endif
#ifdef KEY_PREVIOUSSONG
	"KEY_PREVIOUSSONG",
#endif
#ifdef KEY_PRINT
	"KEY_PRINT",
#endif
#ifdef KEY_PROG1
	"KEY_PROG1",
#endif
#ifdef KEY_PROG2
	"KEY_PROG2",
#endif
#ifdef KEY_PROG3
	"KEY_PROG3",
#endif
#ifdef KEY_PROG4
	"KEY_PROG4",
#endif
#ifdef KEY_PROGRAM
	"KEY_PROGRAM",
#endif
#ifdef KEY_PROPS
	"KEY_PROPS",
#endif
#ifdef KEY_PVR
	"KEY_PVR",
#endif
#ifdef KEY_Q
	"KEY_Q",
#endif
#ifdef KEY_QUESTION
	"KEY_QUESTION",
#endif
#ifdef KEY_R
	"KEY_R",
#endif
#ifdef KEY_RADIO
	"KEY_RADIO",
#endif
#ifdef KEY_RECORD
	"KEY_RECORD",
#endif
#ifdef KEY_RED
	"KEY_RED",
#endif
#ifdef KEY_REDO
	"KEY_REDO",
#endif
#ifdef KEY_REFRESH
	"KEY_REFRESH",
#endif
#ifdef KEY_REPLY
	"KEY_REPLY",
#endif
#ifdef KEY_RESERVED
	"KEY_RESERVED",
#endif
#ifdef KEY_RESTART
	"KEY_RESTART",
#endif
#ifdef KEY_REWIND
	"KEY_REWIND",
#endif
#ifdef KEY_RFKILL
	"KEY_RFKILL",
#endif
#ifdef KEY_RIGHT
	"KEY_RIGHT",
#endif
#ifdef KEY_RIGHTALT
	"KEY_RIGHTALT",
#endif
#ifdef KEY_RIGHTBRACE
	"KEY_RIGHTBRACE",
#endif
#ifdef KEY_RIGHTCTRL
	"KEY_RIGHTCTRL",
#endif
#ifdef KEY_RIGHTMETA
	"KEY_RIGHTMETA",
#endif
#ifdef KEY_RIGHTSHIFT
	"KEY_RIGHTSHIFT",
#endif
#ifdef KEY_RO
	"KEY_RO",
#endif
#ifdef KEY_S
	"KEY_S",
#endif
#ifdef KEY_SAT
	"KEY_SAT",
#endif
#ifdef KEY_SAT2
	"KEY_SAT2",
#endif
#ifdef KEY_SAVE
	"KEY_SAVE",
#endif
#ifdef KEY_SCALE
	"KEY_SCALE",
#endif
#ifdef KEY_SCREEN
	"KEY_SCREEN",
#endif
#ifdef KEY_SCREENLOCK
	"KEY_SCREENLOCK",
#endif
#ifdef KEY_SCROLLDOWN
	"KEY_SCROLLDOWN",
#endif
#ifdef KEY_SCROLLLOCK
	"KEY_SCROLLLOCK",
#endif
#ifdef KEY_SCROLLUP
	"KEY_SCROLLUP",
#endif
#ifdef KEY_SEARCH
	"KEY_SEARCH",
#endif
#ifdef KEY_SELECT
	"KEY_SELECT",
#endif
#ifdef KEY_SEMICOLON
	"KEY_SEMICOLON",
#endif
#ifdef KEY_SEND
	"KEY_SEND",
#endif
#ifdef KEY_SENDFILE
	"KEY_SENDFILE",
#endif
#ifdef KEY_SETUP
	"KEY_SETUP",
#endif
#ifdef KEY_SHOP
	"KEY_SHOP",
#endif
#ifdef KEY_SHUFFLE
	"KEY_SHUFFLE",
#endif
#ifdef KEY_SLASH
	"KEY_SLASH",
#endif
#ifdef KEY_SLEEP
	"KEY_SLEEP",
#endif
#ifdef KEY_SLOW
	"KEY_SLOW",
#endif
#ifdef KEY_SOUND
	"KEY_SOUND",
#endif
#ifdef KEY_SPACE
	"KEY_SPACE",
#endif
#ifdef KEY_SPELLCHECK
	"KEY_SPELLCHECK",
#endif
#ifdef KEY_SPORT
	"KEY_SPORT",
#endif
#ifdef KEY_SPREADSHEET
	"KEY_SPREADSHEET",
#endif
#ifdef KEY_STOP
	"KEY_STOP",
#endif
#ifdef KEY_STOPCD
	"KEY_STOPCD",
#endif
#ifdef KEY_SUBTITLE
	"KEY_SUBTITLE",
#endif
#ifdef KEY_SUSPEND
	"KEY_SUSPEND",
#endif
#ifdef KEY_SWITCHVIDEOMODE
	"KEY_SWITCHVIDEOMODE",
#endif
#ifdef KEY_SYSRQ
	"KEY_SYSRQ",
#endif
#ifdef KEY_T
	"KEY_T",
#endif
#ifdef KEY_TAB
	"KEY_TAB",
#endif
#ifdef KEY_TAPE
	"KEY_TAPE",
#endif
#ifdef KEY_TEEN
	"KEY_TEEN",
#endif
#ifdef KEY_TEXT
	"KEY_TEXT",
#endif
#ifdef KEY_TIME
	"KEY_TIME",
#endif
#ifdef KEY_TITLE
	"KEY_TITLE",
#endif
#ifdef KEY_TUNER
	"KEY_TUNER",
#endif
#ifdef KEY_TV
	"KEY_TV",
#endif
#ifdef KEY_TV2
	"KEY_TV2",
#endif
#ifdef KEY_TWEN
	"KEY_TWEN",
#endif
#ifdef KEY_U
	"KEY_U",
#endif
#ifdef KEY_UNDO
	"KEY_UNDO",
#endif
#ifdef KEY_UNKNOWN
	"KEY_UNKNOWN",
#endif
#ifdef KEY_UP
	"KEY_UP",
#endif
#ifdef KEY_UWB
	"KEY_UWB",
#endif
#ifdef KEY_V
	"KEY_V",
#endif
#ifdef KEY_VCR
	"KEY_VCR",
#endif
#ifdef KEY_VCR2
	"KEY_VCR2",
#endif
#ifdef KEY_VENDOR
	"KEY_VENDOR",
#endif
#ifdef KEY_VIDEO
	"KEY_VIDEO",
#endif
#ifdef KEY_VIDEO_NEXT
	"KEY_VIDEO_NEXT",
#endif
#ifdef KEY_VIDEOPHONE
	"KEY_VIDEOPHONE",
#endif
#ifdef KEY_VIDEO_PREV
	"KEY_VIDEO_PREV",
#endif
#ifdef KEY_VOICEMAIL
	"KEY_VOICEMAIL",
#endif
#ifdef KEY_VOLUMEDOWN
	"KEY_VOLUMEDOWN",
#endif
#ifdef KEY_VOLUMEUP
	"KEY_VOLUMEUP",
#endif
#ifdef KEY_W
	"KEY_W",
#endif
#ifdef KEY_WAKEUP
	"KEY_WAKEUP",
#endif
#ifdef KEY_WIMAX
	"KEY_WIMAX",
#endif
#ifdef KEY_WLAN
	"KEY_WLAN",
#endif
#ifdef KEY_WORDPROCESSOR
	"KEY_WORDPROCESSOR",
#endif
#ifdef KEY_WPS_BUTTON
	"KEY_WPS_BUTTON",
#endif
#ifdef KEY_WWW
	"KEY_WWW",
#endif
#ifdef KEY_X
	"KEY_X",
#endif
#ifdef KEY_XFER
	"KEY_XFER",
#endif
#ifdef KEY_Y
	"KEY_Y",
#endif
#ifdef KEY_YELLOW
	"KEY_YELLOW",
#endif
#ifdef KEY_YEN
	"KEY_YEN",
#endif
#ifdef KEY_Z
	"KEY_Z",
#endif
#ifdef KEY_ZENKAKUHANKAKU
	"KEY_ZENKAKUHANKAKU",
#endif
#ifdef KEY_ZOOM
	"KEY_ZOOM",
#endif
#ifdef KEY_ZOOMIN
	"KEY_ZOOMIN",
#endif
#ifdef KEY_ZOOMOUT
	"KEY_ZOOMOUT",
#endif
#ifdef KEY_ZOOMRESET
	"KEY_ZOOMRESET"
#endif
};

const int keys_int[] = {
#ifdef KEY_0
	KEY_0,
#endif
#ifdef KEY_1
	KEY_1,
#endif
#ifdef KEY_102ND
	KEY_102ND,
#endif
#ifdef KEY_2
	KEY_2,
#endif
#ifdef KEY_3
	KEY_3,
#endif
#ifdef KEY_4
	KEY_4,
#endif
#ifdef KEY_5
	KEY_5,
#endif
#ifdef KEY_6
	KEY_6,
#endif
#ifdef KEY_7
	KEY_7,
#endif
#ifdef KEY_8
	KEY_8,
#endif
#ifdef KEY_9
	KEY_9,
#endif
#ifdef KEY_A
	KEY_A,
#endif
#ifdef KEY_AB
	KEY_AB,
#endif
#ifdef KEY_ADDRESSBOOK
	KEY_ADDRESSBOOK,
#endif
#ifdef KEY_AGAIN
	KEY_AGAIN,
#endif
#ifdef KEY_ALTERASE
	KEY_ALTERASE,
#endif
#ifdef KEY_ANGLE
	KEY_ANGLE,
#endif
#ifdef KEY_APOSTROPHE
	KEY_APOSTROPHE,
#endif
#ifdef KEY_ARCHIVE
	KEY_ARCHIVE,
#endif
#ifdef KEY_AUDIO
	KEY_AUDIO,
#endif
#ifdef KEY_AUX
	KEY_AUX,
#endif
#ifdef KEY_B
	KEY_B,
#endif
#ifdef KEY_BACK
	KEY_BACK,
#endif
#ifdef KEY_BACKSLASH
	KEY_BACKSLASH,
#endif
#ifdef KEY_BACKSPACE
	KEY_BACKSPACE,
#endif
#ifdef KEY_BASSBOOST
	KEY_BASSBOOST,
#endif
#ifdef KEY_BATTERY
	KEY_BATTERY,
#endif
#ifdef KEY_BLUE
	KEY_BLUE,
#endif
#ifdef KEY_BLUETOOTH
	KEY_BLUETOOTH,
#endif
#ifdef KEY_BOOKMARKS
	KEY_BOOKMARKS,
#endif
#ifdef KEY_BREAK
	KEY_BREAK,
#endif
#ifdef KEY_BRIGHTNESS_CYCLE
	KEY_BRIGHTNESS_CYCLE,
#endif
#ifdef KEY_BRIGHTNESSDOWN
	KEY_BRIGHTNESSDOWN,
#endif
#ifdef KEY_BRIGHTNESSUP
	KEY_BRIGHTNESSUP,
#endif
#ifdef KEY_BRIGHTNESS_ZERO
	KEY_BRIGHTNESS_ZERO,
#endif
#ifdef KEY_BRL_DOT1
	KEY_BRL_DOT1,
#endif
#ifdef KEY_BRL_DOT10
	KEY_BRL_DOT10,
#endif
#ifdef KEY_BRL_DOT2
	KEY_BRL_DOT2,
#endif
#ifdef KEY_BRL_DOT3
	KEY_BRL_DOT3,
#endif
#ifdef KEY_BRL_DOT4
	KEY_BRL_DOT4,
#endif
#ifdef KEY_BRL_DOT5
	KEY_BRL_DOT5,
#endif
#ifdef KEY_BRL_DOT6
	KEY_BRL_DOT6,
#endif
#ifdef KEY_BRL_DOT7
	KEY_BRL_DOT7,
#endif
#ifdef KEY_BRL_DOT8
	KEY_BRL_DOT8,
#endif
#ifdef KEY_BRL_DOT9
	KEY_BRL_DOT9,
#endif
#ifdef KEY_C
	KEY_C,
#endif
#ifdef KEY_CALC
	KEY_CALC,
#endif
#ifdef KEY_CALENDAR
	KEY_CALENDAR,
#endif
#ifdef KEY_CAMERA
	KEY_CAMERA,
#endif
#ifdef KEY_CAMERA_FOCUS
	KEY_CAMERA_FOCUS,
#endif
#ifdef KEY_CANCEL
	KEY_CANCEL,
#endif
#ifdef KEY_CAPSLOCK
	KEY_CAPSLOCK,
#endif
#ifdef KEY_CD
	KEY_CD,
#endif
#ifdef KEY_CHANNEL
	KEY_CHANNEL,
#endif
#ifdef KEY_CHANNELDOWN
	KEY_CHANNELDOWN,
#endif
#ifdef KEY_CHANNELUP
	KEY_CHANNELUP,
#endif
#ifdef KEY_CHAT
	KEY_CHAT,
#endif
#ifdef KEY_CLEAR
	KEY_CLEAR,
#endif
#ifdef KEY_CLOSE
	KEY_CLOSE,
#endif
#ifdef KEY_CLOSECD
	KEY_CLOSECD,
#endif
#ifdef KEY_COFFEE
	KEY_COFFEE,
#endif
#ifdef KEY_COMMA
	KEY_COMMA,
#endif
#ifdef KEY_COMPOSE
	KEY_COMPOSE,
#endif
#ifdef KEY_COMPUTER
	KEY_COMPUTER,
#endif
#ifdef KEY_CONFIG
	KEY_CONFIG,
#endif
#ifdef KEY_CONNECT
	KEY_CONNECT,
#endif
#ifdef KEY_CONTEXT_MENU
	KEY_CONTEXT_MENU,
#endif
#ifdef KEY_COPY
	KEY_COPY,
#endif
#ifdef KEY_CUT
	KEY_CUT,
#endif
#ifdef KEY_CYCLEWINDOWS
	KEY_CYCLEWINDOWS,
#endif
#ifdef KEY_D
	KEY_D,
#endif
#ifdef KEY_DASHBOARD
	KEY_DASHBOARD,
#endif
#ifdef KEY_DATABASE
	KEY_DATABASE,
#endif
#ifdef KEY_DEL_EOL
	KEY_DEL_EOL,
#endif
#ifdef KEY_DEL_EOS
	KEY_DEL_EOS,
#endif
#ifdef KEY_DELETE
	KEY_DELETE,
#endif
#ifdef KEY_DELETEFILE
	KEY_DELETEFILE,
#endif
#ifdef KEY_DEL_LINE
	KEY_DEL_LINE,
#endif
#ifdef KEY_DIGITS
	KEY_DIGITS,
#endif
#ifdef KEY_DIRECTION
	KEY_DIRECTION,
#endif
#ifdef KEY_DIRECTORY
	KEY_DIRECTORY,
#endif
#ifdef KEY_DISPLAY_OFF
	KEY_DISPLAY_OFF,
#endif
#ifdef KEY_DISPLAYTOGGLE
	KEY_DISPLAYTOGGLE,
#endif
#ifdef KEY_DOCUMENTS
	KEY_DOCUMENTS,
#endif
#ifdef KEY_DOLLAR
	KEY_DOLLAR,
#endif
#ifdef KEY_DOT
	KEY_DOT,
#endif
#ifdef KEY_DOWN
	KEY_DOWN,
#endif
#ifdef KEY_DVD
	KEY_DVD,
#endif
#ifdef KEY_E
	KEY_E,
#endif
#ifdef KEY_EDIT
	KEY_EDIT,
#endif
#ifdef KEY_EDITOR
	KEY_EDITOR,
#endif
#ifdef KEY_EJECTCD
	KEY_EJECTCD,
#endif
#ifdef KEY_EJECTCLOSECD
	KEY_EJECTCLOSECD,
#endif
#ifdef KEY_EMAIL
	KEY_EMAIL,
#endif
#ifdef KEY_END
	KEY_END,
#endif
#ifdef KEY_ENTER
	KEY_ENTER,
#endif
#ifdef KEY_EPG
	KEY_EPG,
#endif
#ifdef KEY_EQUAL
	KEY_EQUAL,
#endif
#ifdef KEY_ESC
	KEY_ESC,
#endif
#ifdef KEY_EURO
	KEY_EURO,
#endif
#ifdef KEY_EXIT
	KEY_EXIT,
#endif
#ifdef KEY_F
	KEY_F,
#endif
#ifdef KEY_F1
	KEY_F1,
#endif
#ifdef KEY_F10
	KEY_F10,
#endif
#ifdef KEY_F11
	KEY_F11,
#endif
#ifdef KEY_F12
	KEY_F12,
#endif
#ifdef KEY_F13
	KEY_F13,
#endif
#ifdef KEY_F14
	KEY_F14,
#endif
#ifdef KEY_F15
	KEY_F15,
#endif
#ifdef KEY_F16
	KEY_F16,
#endif
#ifdef KEY_F17
	KEY_F17,
#endif
#ifdef KEY_F18
	KEY_F18,
#endif
#ifdef KEY_F19
	KEY_F19,
#endif
#ifdef KEY_F2
	KEY_F2,
#endif
#ifdef KEY_F20
	KEY_F20,
#endif
#ifdef KEY_F21
	KEY_F21,
#endif
#ifdef KEY_F22
	KEY_F22,
#endif
#ifdef KEY_F23
	KEY_F23,
#endif
#ifdef KEY_F24
	KEY_F24,
#endif
#ifdef KEY_F3
	KEY_F3,
#endif
#ifdef KEY_F4
	KEY_F4,
#endif
#ifdef KEY_F5
	KEY_F5,
#endif
#ifdef KEY_F6
	KEY_F6,
#endif
#ifdef KEY_F7
	KEY_F7,
#endif
#ifdef KEY_F8
	KEY_F8,
#endif
#ifdef KEY_F9
	KEY_F9,
#endif
#ifdef KEY_FASTFORWARD
	KEY_FASTFORWARD,
#endif
#ifdef KEY_FAVORITES
	KEY_FAVORITES,
#endif
#ifdef KEY_FILE
	KEY_FILE,
#endif
#ifdef KEY_FINANCE
	KEY_FINANCE,
#endif
#ifdef KEY_FIND
	KEY_FIND,
#endif
#ifdef KEY_FIRST
	KEY_FIRST,
#endif
#ifdef KEY_FN
	KEY_FN,
#endif
#ifdef KEY_FN_1
	KEY_FN_1,
#endif
#ifdef KEY_FN_2
	KEY_FN_2,
#endif
#ifdef KEY_FN_B
	KEY_FN_B,
#endif
#ifdef KEY_FN_D
	KEY_FN_D,
#endif
#ifdef KEY_FN_E
	KEY_FN_E,
#endif
#ifdef KEY_FN_ESC
	KEY_FN_ESC,
#endif
#ifdef KEY_FN_F
	KEY_FN_F,
#endif
#ifdef KEY_FN_F1
	KEY_FN_F1,
#endif
#ifdef KEY_FN_F10
	KEY_FN_F10,
#endif
#ifdef KEY_FN_F11
	KEY_FN_F11,
#endif
#ifdef KEY_FN_F12
	KEY_FN_F12,
#endif
#ifdef KEY_FN_F2
	KEY_FN_F2,
#endif
#ifdef KEY_FN_F3
	KEY_FN_F3,
#endif
#ifdef KEY_FN_F4
	KEY_FN_F4,
#endif
#ifdef KEY_FN_F5
	KEY_FN_F5,
#endif
#ifdef KEY_FN_F6
	KEY_FN_F6,
#endif
#ifdef KEY_FN_F7
	KEY_FN_F7,
#endif
#ifdef KEY_FN_F8
	KEY_FN_F8,
#endif
#ifdef KEY_FN_F9
	KEY_FN_F9,
#endif
#ifdef KEY_FN_S
	KEY_FN_S,
#endif
#ifdef KEY_FORWARD
	KEY_FORWARD,
#endif
#ifdef KEY_FORWARDMAIL
	KEY_FORWARDMAIL,
#endif
#ifdef KEY_FRAMEBACK
	KEY_FRAMEBACK,
#endif
#ifdef KEY_FRAMEFORWARD
	KEY_FRAMEFORWARD,
#endif
#ifdef KEY_FRONT
	KEY_FRONT,
#endif
#ifdef KEY_G
	KEY_G,
#endif
#ifdef KEY_GAMES
	KEY_GAMES,
#endif
#ifdef KEY_GOTO
	KEY_GOTO,
#endif
#ifdef KEY_GRAPHICSEDITOR
	KEY_GRAPHICSEDITOR,
#endif
#ifdef KEY_GRAVE
	KEY_GRAVE,
#endif
#ifdef KEY_GREEN
	KEY_GREEN,
#endif
#ifdef KEY_H
	KEY_H,
#endif
#ifdef KEY_HANGEUL
	KEY_HANGEUL,
#endif
#ifdef KEY_HANGUEL
	KEY_HANGUEL,
#endif
#ifdef KEY_HANJA
	KEY_HANJA,
#endif
#ifdef KEY_HELP
	KEY_HELP,
#endif
#ifdef KEY_HENKAN
	KEY_HENKAN,
#endif
#ifdef KEY_HIRAGANA
	KEY_HIRAGANA,
#endif
#ifdef KEY_HOME
	KEY_HOME,
#endif
#ifdef KEY_HOMEPAGE
	KEY_HOMEPAGE,
#endif
#ifdef KEY_HP
	KEY_HP,
#endif
#ifdef KEY_I
	KEY_I,
#endif
#ifdef KEY_INFO
	KEY_INFO,
#endif
#ifdef KEY_INSERT
	KEY_INSERT,
#endif
#ifdef KEY_INS_LINE
	KEY_INS_LINE,
#endif
#ifdef KEY_ISO
	KEY_ISO,
#endif
#ifdef KEY_J
	KEY_J,
#endif
#ifdef KEY_K
	KEY_K,
#endif
#ifdef KEY_KATAKANA
	KEY_KATAKANA,
#endif
#ifdef KEY_KATAKANAHIRAGANA
	KEY_KATAKANAHIRAGANA,
#endif
#ifdef KEY_KBDILLUMDOWN
	KEY_KBDILLUMDOWN,
#endif
#ifdef KEY_KBDILLUMTOGGLE
	KEY_KBDILLUMTOGGLE,
#endif
#ifdef KEY_KBDILLUMUP
	KEY_KBDILLUMUP,
#endif
#ifdef KEY_KEYBOARD
	KEY_KEYBOARD,
#endif
#ifdef KEY_KP0
	KEY_KP0,
#endif
#ifdef KEY_KP1
	KEY_KP1,
#endif
#ifdef KEY_KP2
	KEY_KP2,
#endif
#ifdef KEY_KP3
	KEY_KP3,
#endif
#ifdef KEY_KP4
	KEY_KP4,
#endif
#ifdef KEY_KP5
	KEY_KP5,
#endif
#ifdef KEY_KP6
	KEY_KP6,
#endif
#ifdef KEY_KP7
	KEY_KP7,
#endif
#ifdef KEY_KP8
	KEY_KP8,
#endif
#ifdef KEY_KP9
	KEY_KP9,
#endif
#ifdef KEY_KPASTERISK
	KEY_KPASTERISK,
#endif
#ifdef KEY_KPCOMMA
	KEY_KPCOMMA,
#endif
#ifdef KEY_KPDOT
	KEY_KPDOT,
#endif
#ifdef KEY_KPENTER
	KEY_KPENTER,
#endif
#ifdef KEY_KPEQUAL
	KEY_KPEQUAL,
#endif
#ifdef KEY_KPJPCOMMA
	KEY_KPJPCOMMA,
#endif
#ifdef KEY_KPLEFTPAREN
	KEY_KPLEFTPAREN,
#endif
#ifdef KEY_KPMINUS
	KEY_KPMINUS,
#endif
#ifdef KEY_KPPLUS
	KEY_KPPLUS,
#endif
#ifdef KEY_KPPLUSMINUS
	KEY_KPPLUSMINUS,
#endif
#ifdef KEY_KPRIGHTPAREN
	KEY_KPRIGHTPAREN,
#endif
#ifdef KEY_KPSLASH
	KEY_KPSLASH,
#endif
#ifdef KEY_L
	KEY_L,
#endif
#ifdef KEY_LANGUAGE
	KEY_LANGUAGE,
#endif
#ifdef KEY_LAST
	KEY_LAST,
#endif
#ifdef KEY_LEFT
	KEY_LEFT,
#endif
#ifdef KEY_LEFTALT
	KEY_LEFTALT,
#endif
#ifdef KEY_LEFTBRACE
	KEY_LEFTBRACE,
#endif
#ifdef KEY_LEFTCTRL
	KEY_LEFTCTRL,
#endif
#ifdef KEY_LEFTMETA
	KEY_LEFTMETA,
#endif
#ifdef KEY_LEFTSHIFT
	KEY_LEFTSHIFT,
#endif
#ifdef KEY_LINEFEED
	KEY_LINEFEED,
#endif
#ifdef KEY_LIST
	KEY_LIST,
#endif
#ifdef KEY_LOGOFF
	KEY_LOGOFF,
#endif
#ifdef KEY_M
	KEY_M,
#endif
#ifdef KEY_MACRO
	KEY_MACRO,
#endif
#ifdef KEY_MAIL
	KEY_MAIL,
#endif
#ifdef KEY_MEDIA
	KEY_MEDIA,
#endif
#ifdef KEY_MEDIA_REPEAT
	KEY_MEDIA_REPEAT,
#endif
#ifdef KEY_MEMO
	KEY_MEMO,
#endif
#ifdef KEY_MENU
	KEY_MENU,
#endif
#ifdef KEY_MESSENGER
	KEY_MESSENGER,
#endif
#ifdef KEY_MHP
	KEY_MHP,
#endif
#ifdef KEY_MINUS
	KEY_MINUS,
#endif
#ifdef KEY_MODE
	KEY_MODE,
#endif
#ifdef KEY_MOVE
	KEY_MOVE,
#endif
#ifdef KEY_MP3
	KEY_MP3,
#endif
#ifdef KEY_MSDOS
	KEY_MSDOS,
#endif
#ifdef KEY_MUHENKAN
	KEY_MUHENKAN,
#endif
#ifdef KEY_MUTE
	KEY_MUTE,
#endif
#ifdef KEY_N
	KEY_N,
#endif
#ifdef KEY_NEW
	KEY_NEW,
#endif
#ifdef KEY_NEWS
	KEY_NEWS,
#endif
#ifdef KEY_NEXT
	KEY_NEXT,
#endif
#ifdef KEY_NEXTSONG
	KEY_NEXTSONG,
#endif
#ifdef KEY_NUMERIC_0
	KEY_NUMERIC_0,
#endif
#ifdef KEY_NUMERIC_1
	KEY_NUMERIC_1,
#endif
#ifdef KEY_NUMERIC_2
	KEY_NUMERIC_2,
#endif
#ifdef KEY_NUMERIC_3
	KEY_NUMERIC_3,
#endif
#ifdef KEY_NUMERIC_4
	KEY_NUMERIC_4,
#endif
#ifdef KEY_NUMERIC_5
	KEY_NUMERIC_5,
#endif
#ifdef KEY_NUMERIC_6
	KEY_NUMERIC_6,
#endif
#ifdef KEY_NUMERIC_7
	KEY_NUMERIC_7,
#endif
#ifdef KEY_NUMERIC_8
	KEY_NUMERIC_8,
#endif
#ifdef KEY_NUMERIC_9
	KEY_NUMERIC_9,
#endif
#ifdef KEY_NUMERIC_POUND
	KEY_NUMERIC_POUND,
#endif
#ifdef KEY_NUMERIC_STAR
	KEY_NUMERIC_STAR,
#endif
#ifdef KEY_NUMLOCK
	KEY_NUMLOCK,
#endif
#ifdef KEY_O
	KEY_O,
#endif
#ifdef KEY_OK
	KEY_OK,
#endif
#ifdef KEY_OPEN
	KEY_OPEN,
#endif
#ifdef KEY_OPTION
	KEY_OPTION,
#endif
#ifdef KEY_P
	KEY_P,
#endif
#ifdef KEY_PAGEDOWN
	KEY_PAGEDOWN,
#endif
#ifdef KEY_PAGEUP
	KEY_PAGEUP,
#endif
#ifdef KEY_PASTE
	KEY_PASTE,
#endif
#ifdef KEY_PAUSE
	KEY_PAUSE,
#endif
#ifdef KEY_PAUSECD
	KEY_PAUSECD,
#endif
#ifdef KEY_PC
	KEY_PC,
#endif
#ifdef KEY_PHONE
	KEY_PHONE,
#endif
#ifdef KEY_PLAY
	KEY_PLAY,
#endif
#ifdef KEY_PLAYCD
	KEY_PLAYCD,
#endif
#ifdef KEY_PLAYER
	KEY_PLAYER,
#endif
#ifdef KEY_PLAYPAUSE
	KEY_PLAYPAUSE,
#endif
#ifdef KEY_POWER
	KEY_POWER,
#endif
#ifdef KEY_POWER2
	KEY_POWER2,
#endif
#ifdef KEY_PRESENTATION
	KEY_PRESENTATION,
#endif
#ifdef KEY_PREVIOUS
	KEY_PREVIOUS,
#endif
#ifdef KEY_PREVIOUSSONG
	KEY_PREVIOUSSONG,
#endif
#ifdef KEY_PRINT
	KEY_PRINT,
#endif
#ifdef KEY_PROG1
	KEY_PROG1,
#endif
#ifdef KEY_PROG2
	KEY_PROG2,
#endif
#ifdef KEY_PROG3
	KEY_PROG3,
#endif
#ifdef KEY_PROG4
	KEY_PROG4,
#endif
#ifdef KEY_PROGRAM
	KEY_PROGRAM,
#endif
#ifdef KEY_PROPS
	KEY_PROPS,
#endif
#ifdef KEY_PVR
	KEY_PVR,
#endif
#ifdef KEY_Q
	KEY_Q,
#endif
#ifdef KEY_QUESTION
	KEY_QUESTION,
#endif
#ifdef KEY_R
	KEY_R,
#endif
#ifdef KEY_RADIO
	KEY_RADIO,
#endif
#ifdef KEY_RECORD
	KEY_RECORD,
#endif
#ifdef KEY_RED
	KEY_RED,
#endif
#ifdef KEY_REDO
	KEY_REDO,
#endif
#ifdef KEY_REFRESH
	KEY_REFRESH,
#endif
#ifdef KEY_REPLY
	KEY_REPLY,
#endif
#ifdef KEY_RESERVED
	KEY_RESERVED,
#endif
#ifdef KEY_RESTART
	KEY_RESTART,
#endif
#ifdef KEY_REWIND
	KEY_REWIND,
#endif
#ifdef KEY_RFKILL
	KEY_RFKILL,
#endif
#ifdef KEY_RIGHT
	KEY_RIGHT,
#endif
#ifdef KEY_RIGHTALT
	KEY_RIGHTALT,
#endif
#ifdef KEY_RIGHTBRACE
	KEY_RIGHTBRACE,
#endif
#ifdef KEY_RIGHTCTRL
	KEY_RIGHTCTRL,
#endif
#ifdef KEY_RIGHTMETA
	KEY_RIGHTMETA,
#endif
#ifdef KEY_RIGHTSHIFT
	KEY_RIGHTSHIFT,
#endif
#ifdef KEY_RO
	KEY_RO,
#endif
#ifdef KEY_S
	KEY_S,
#endif
#ifdef KEY_SAT
	KEY_SAT,
#endif
#ifdef KEY_SAT2
	KEY_SAT2,
#endif
#ifdef KEY_SAVE
	KEY_SAVE,
#endif
#ifdef KEY_SCALE
	KEY_SCALE,
#endif
#ifdef KEY_SCREEN
	KEY_SCREEN,
#endif
#ifdef KEY_SCREENLOCK
	KEY_SCREENLOCK,
#endif
#ifdef KEY_SCROLLDOWN
	KEY_SCROLLDOWN,
#endif
#ifdef KEY_SCROLLLOCK
	KEY_SCROLLLOCK,
#endif
#ifdef KEY_SCROLLUP
	KEY_SCROLLUP,
#endif
#ifdef KEY_SEARCH
	KEY_SEARCH,
#endif
#ifdef KEY_SELECT
	KEY_SELECT,
#endif
#ifdef KEY_SEMICOLON
	KEY_SEMICOLON,
#endif
#ifdef KEY_SEND
	KEY_SEND,
#endif
#ifdef KEY_SENDFILE
	KEY_SENDFILE,
#endif
#ifdef KEY_SETUP
	KEY_SETUP,
#endif
#ifdef KEY_SHOP
	KEY_SHOP,
#endif
#ifdef KEY_SHUFFLE
	KEY_SHUFFLE,
#endif
#ifdef KEY_SLASH
	KEY_SLASH,
#endif
#ifdef KEY_SLEEP
	KEY_SLEEP,
#endif
#ifdef KEY_SLOW
	KEY_SLOW,
#endif
#ifdef KEY_SOUND
	KEY_SOUND,
#endif
#ifdef KEY_SPACE
	KEY_SPACE,
#endif
#ifdef KEY_SPELLCHECK
	KEY_SPELLCHECK,
#endif
#ifdef KEY_SPORT
	KEY_SPORT,
#endif
#ifdef KEY_SPREADSHEET
	KEY_SPREADSHEET,
#endif
#ifdef KEY_STOP
	KEY_STOP,
#endif
#ifdef KEY_STOPCD
	KEY_STOPCD,
#endif
#ifdef KEY_SUBTITLE
	KEY_SUBTITLE,
#endif
#ifdef KEY_SUSPEND
	KEY_SUSPEND,
#endif
#ifdef KEY_SWITCHVIDEOMODE
	KEY_SWITCHVIDEOMODE,
#endif
#ifdef KEY_SYSRQ
	KEY_SYSRQ,
#endif
#ifdef KEY_T
	KEY_T,
#endif
#ifdef KEY_TAB
	KEY_TAB,
#endif
#ifdef KEY_TAPE
	KEY_TAPE,
#endif
#ifdef KEY_TEEN
	KEY_TEEN,
#endif
#ifdef KEY_TEXT
	KEY_TEXT,
#endif
#ifdef KEY_TIME
	KEY_TIME,
#endif
#ifdef KEY_TITLE
	KEY_TITLE,
#endif
#ifdef KEY_TUNER
	KEY_TUNER,
#endif
#ifdef KEY_TV
	KEY_TV,
#endif
#ifdef KEY_TV2
	KEY_TV2,
#endif
#ifdef KEY_TWEN
	KEY_TWEN,
#endif
#ifdef KEY_U
	KEY_U,
#endif
#ifdef KEY_UNDO
	KEY_UNDO,
#endif
#ifdef KEY_UNKNOWN
	KEY_UNKNOWN,
#endif
#ifdef KEY_UP
	KEY_UP,
#endif
#ifdef KEY_UWB
	KEY_UWB,
#endif
#ifdef KEY_V
	KEY_V,
#endif
#ifdef KEY_VCR
	KEY_VCR,
#endif
#ifdef KEY_VCR2
	KEY_VCR2,
#endif
#ifdef KEY_VENDOR
	KEY_VENDOR,
#endif
#ifdef KEY_VIDEO
	KEY_VIDEO,
#endif
#ifdef KEY_VIDEO_NEXT
	KEY_VIDEO_NEXT,
#endif
#ifdef KEY_VIDEOPHONE
	KEY_VIDEOPHONE,
#endif
#ifdef KEY_VIDEO_PREV
	KEY_VIDEO_PREV,
#endif
#ifdef KEY_VOICEMAIL
	KEY_VOICEMAIL,
#endif
#ifdef KEY_VOLUMEDOWN
	KEY_VOLUMEDOWN,
#endif
#ifdef KEY_VOLUMEUP
	KEY_VOLUMEUP,
#endif
#ifdef KEY_W
	KEY_W,
#endif
#ifdef KEY_WAKEUP
	KEY_WAKEUP,
#endif
#ifdef KEY_WIMAX
	KEY_WIMAX,
#endif
#ifdef KEY_WLAN
	KEY_WLAN,
#endif
#ifdef KEY_WORDPROCESSOR
	KEY_WORDPROCESSOR,
#endif
#ifdef KEY_WPS_BUTTON
	KEY_WPS_BUTTON,
#endif
#ifdef KEY_WWW
	KEY_WWW,
#endif
#ifdef KEY_X
	KEY_X,
#endif
#ifdef KEY_XFER
	KEY_XFER,
#endif
#ifdef KEY_Y
	KEY_Y,
#endif
#ifdef KEY_YELLOW
	KEY_YELLOW,
#endif
#ifdef KEY_YEN
	KEY_YEN,
#endif
#ifdef KEY_Z
	KEY_Z,
#endif
#ifdef KEY_ZENKAKUHANKAKU
	KEY_ZENKAKUHANKAKU,
#endif
#ifdef KEY_ZOOM
	KEY_ZOOM,
#endif
#ifdef KEY_ZOOMIN
	KEY_ZOOMIN,
#endif
#ifdef KEY_ZOOMOUT
	KEY_ZOOMOUT,
#endif
#ifdef KEY_ZOOMRESET
	KEY_ZOOMRESET
#endif
};

const unsigned int keys_array_size = sizeof(keys_char)/sizeof(keys_char[0]);
