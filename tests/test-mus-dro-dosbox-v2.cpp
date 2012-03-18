/**
 * @file   test-mus-dro-dosbox-v2.cpp
 * @brief  Test code for DOSBox raw OPL capture files.
 *
 * Copyright (C) 2010-2012 Adam Nielsen <malvineous@shikadi.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define INITIAL_TEMPO 1000 // Native DRO tempo (makes ticks match data)
#define INSTRUMENT_TYPE  0 // OPL

#define testdata_noteonoff \
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x0f\x00\x00\x00" "\x10\x00\x00\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x0d" \
	"\x20\x40\x60\x80\xe0" \
	"\x23\x43\x63\x83\xe3\xc0" \
	"\xa0\xb0" \
	"\x00\xae\x01\x7f\x02\xed\x03\xcb\x04\x06" \
	"\x05\xa7\x06\x1f\x07\x65\x08\x43\x09\x02\x0a\x04" \
	"\x0b\x44" \
	"\x0c\x32" "\xff\x0f" \
	"\x0c\x12"

#define HAS_OPL_RHYTHM_INSTRUMENTS

#define testdata_rhythm_hihat \
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x08\x00\x00\x00" "\x10\x00\x00\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x06" \
	"\x31\x51\x71\x91\xf1\xbd" \
	"\x00\xae" \
	"\x01\x7f" \
	"\x02\xed" \
	"\x03\xcb" \
	"\x04\x06" \
	"\x05\x21" "\xff\x0f" \
	"\x05\x20"

#define testdata_rhythm_cymbal \
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x08\x00\x00\x00" "\x10\x00\x00\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x06" \
	"\x35\x55\x75\x95\xf5\xbd" \
	"\x00\xae" \
	"\x01\x7f" \
	"\x02\xed" \
	"\x03\xcb" \
	"\x04\x06" \
	"\x05\x22" "\xff\x0f" \
	"\x05\x20"

#define testdata_rhythm_tom \
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x0b\x00\x00\x00" "\x10\x00\x00\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x09" \
	"\x32\x52\x72\x92\xf2\xc8\xa8\xb8\xbd" \
	"\x00\xae" \
	"\x01\x7f" \
	"\x02\xed" \
	"\x03\xcb" \
	"\x04\x06" \
	\
	"\x05\x09" \
	\
	"\x06\x44" \
	"\x07\x12" \
	"\x08\x24" "\xff\x0f" \
	"\x08\x20"

#define testdata_rhythm_snare \
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x0b\x00\x00\x00" "\x10\x00\x00\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x09" \
	"\x34\x54\x74\x94\xf4\xc7\xa7\xb7\xbd" \
	"\x00\xae" \
	"\x01\x7f" \
	"\x02\xed" \
	"\x03\xcb" \
	"\x04\x06" \
	\
	"\x05\x09" \
	\
	"\x06\x44" \
	"\x07\x12" \
	"\x08\x28" "\xff\x0f" \
	"\x08\x20"

#define testdata_rhythm_bassdrum \
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x10\x00\x00\x00" "\x10\x00\x00\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x0e" \
	"\x30\x50\x70\x90\xf0" \
	"\x33\x53\x73\x93\xf3\xc6" \
	"\xa6\xb6\xbd" \
	"\x00\xae" \
	"\x01\x7f" \
	"\x02\xed" \
	"\x03\xcb" \
	"\x04\x06" \
	\
	"\x05\xae" \
	"\x06\x7f" \
	"\x07\xed" \
	"\x08\xcb" \
	"\x09\x06" \
	\
	"\x0a\x09" \
	\
	"\x0b\x44" \
	"\x0c\x12" \
	"\x0d\x30" "\xff\x0f" \
	"\x0d\x20"

#define MUSIC_CLASS fmt_mus_dro_dosbox_v2
#define MUSIC_TYPE  "dro-dosbox-v2"
#include "test-musictype-read.hpp"
#include "test-musictype-write.hpp"

TEST_BEFORE_AFTER(delay_combining,
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x19\x00\x00\x00" "\x42\x06\x01\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x0d" \
	"\x20\x40\x60\x80\xe0" \
	"\x23\x43\x63\x83\xe3\xc0" \
	"\xa0\xb0" \
	"\x00\xae\x01\x7f\x02\xed\x03\xcb\x04\x06" \
	"\x05\xa7\x06\x1f\x07\x65\x08\x43\x09\x02\x0a\x04" \
	"\x0b\x44\x0c\x32" \
	"\xff\x0f" "\xff\x0f" \
	"\x0c\x12"
	"\xff\x0f" "\xfe\x02" "\xff\x0f"
	"\x0c\x32"
	"\xfe\x80" "\xfe\x81" "\xff\x01"
	"\x0c\x12"
	,
	"DBRAWOPL" "\x02\x00\x00\x00" \
	"\x16\x00\x00\x00" "\x42\x06\x01\x00" \
	"\x00\x00\x00" \
	"\xff\xfe\x0d" \
	"\x20\x40\x60\x80\xe0" \
	"\x23\x43\x63\x83\xe3\xc0" \
	"\xa0\xb0" \
	"\x00\xae\x01\x7f\x02\xed\x03\xcb\x04\x06" \
	"\x05\xa7\x06\x1f\x07\x65\x08\x43\x09\x02\x0a\x04" \
	"\x0b\x44\x0c\x32" \
	"\xff\x1f" \
	"\x0c\x12"
	"\xfe\x02" "\xff\x1f"
	"\x0c\x32"
	"\xfe\xff" "\xfe\x02" "\xff\x01"
	"\x0c\x12"
);

// Test some invalid formats to make sure they're not identified as valid
// files.  Note that they can still be opened though (by 'force'), this
// only checks whether they look like valid files or not.

// The "c00" test has already been performed in test-musicreader.hpp to ensure
// the initial state is correctly identified as a valid file.

// Wrong signature
ISINSTANCE_TEST(c01,
	"DBRAWOPP" "\x00\x00\x02\x00"
	,
	MusicType::DefinitelyNo
);

// Wrong version
ISINSTANCE_TEST(c02,
	"DBRAWOPL" "\x00\x00\x01\x00"
	,
	MusicType::DefinitelyNo
);
