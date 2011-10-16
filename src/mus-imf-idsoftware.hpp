/**
 * @file   mus-imf-idsoftware.hpp
 * @brief  Support for id Software's .IMF format.
 *
 * Copyright (C) 2010-2011 Adam Nielsen <malvineous@shikadi.net>
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

#ifndef _CAMOTO_GAMEMUSIC_MUS_IMF_IDSOFTWARE_HPP_
#define _CAMOTO_GAMEMUSIC_MUS_IMF_IDSOFTWARE_HPP_

#include <camoto/gamemusic/musictype.hpp>
#include <camoto/gamemusic/mus-generic-opl.hpp>

namespace camoto {
namespace gamemusic {

/// Common IMF functions for all versions
class MusicType_IMF_Common: virtual public MusicType {

	public:

		virtual SuppFilenames getRequiredSupps(const std::string& filenameMusic) const
			throw ();

	protected:

		/// Shared format checking code between both file variants
		/**
		 * @param psMusic stream to check
		 * @param imfType 0 to check as type-0, 1 to check as type-1
		 * @return @see MusicType::isInstance()
		 */
		virtual MusicType::Certainty genericIsInstance(stream::input_sptr psMusic, int imfType) const
			throw (stream::error);

};

/// MusicType implementation for IMF
class MusicType_IMF_Type0: virtual public MusicType_IMF_Common {

	public:

		virtual std::string getCode() const
			throw ();

		virtual std::string getFriendlyName() const
			throw ();

		virtual std::vector<std::string> getFileExtensions() const
			throw ();

		virtual MusicType::Certainty isInstance(stream::input_sptr psMusic) const
			throw (stream::error);

		virtual MusicWriterPtr create(stream::output_sptr output, SuppData& suppData) const
			throw (stream::error);

		virtual MusicReaderPtr open(stream::input_sptr input, SuppData& suppData) const
			throw (stream::error);

};

/// Extension to make type-1 files appear as a different type
class MusicType_IMF_Type1: virtual public MusicType_IMF_Common {

	public:

		virtual std::string getCode() const
			throw ();

		virtual std::string getFriendlyName() const
			throw ();

		virtual std::vector<std::string> getFileExtensions() const
			throw ();

		virtual MusicType::Certainty isInstance(stream::input_sptr psMusic) const
			throw (stream::error);

		virtual MusicWriterPtr create(stream::output_sptr output, SuppData& suppData) const
			throw (stream::error);

		virtual MusicReaderPtr open(stream::input_sptr input, SuppData& suppData) const
			throw (stream::error);
};

/// 700Hz (Wolf3D) variant
class MusicType_WLF_Type0: virtual public MusicType_IMF_Common {

	public:

		virtual std::string getCode() const
			throw ();

		virtual std::string getFriendlyName() const
			throw ();

		virtual std::vector<std::string> getFileExtensions() const
			throw ();

		virtual MusicType::Certainty isInstance(stream::input_sptr psMusic) const
			throw (stream::error);

		virtual MusicWriterPtr create(stream::output_sptr output, SuppData& suppData) const
			throw (stream::error);

		virtual MusicReaderPtr open(stream::input_sptr input, SuppData& suppData) const
			throw (stream::error);

};

/// 700Hz (Wolf3D) variant
class MusicType_WLF_Type1: virtual public MusicType_IMF_Common {

	public:

		virtual std::string getCode() const
			throw ();

		virtual std::string getFriendlyName() const
			throw ();

		virtual std::vector<std::string> getFileExtensions() const
			throw ();

		virtual MusicType::Certainty isInstance(stream::input_sptr psMusic) const
			throw (stream::error);

		virtual MusicWriterPtr create(stream::output_sptr output, SuppData& suppData) const
			throw (stream::error);

		virtual MusicReaderPtr open(stream::input_sptr input, SuppData& suppData) const
			throw (stream::error);
};

/// 280Hz (DukeII) variant
class MusicType_IMF_Duke2: virtual public MusicType_IMF_Common {

	public:

		virtual std::string getCode() const
			throw ();

		virtual std::string getFriendlyName() const
			throw ();

		virtual std::vector<std::string> getFileExtensions() const
			throw ();

		virtual MusicType::Certainty isInstance(stream::input_sptr psMusic) const
			throw (stream::error);

		virtual MusicWriterPtr create(stream::output_sptr output, SuppData& suppData) const
			throw (stream::error);

		virtual MusicReaderPtr open(stream::input_sptr input, SuppData& suppData) const
			throw (stream::error);

};

/// MusicReader class that understands IMF music files.
class MusicReader_IMF: virtual public MusicReader_GenericOPL {

	protected:
		stream::input_sptr input;  ///< Stream of IMF data to read
		int imfType;         ///< 0 or 1 for IMF variant
		int lenData;         ///< Length of data to read (0 == read until EOF)

	public:

		/// Read an IMF file
		/**
		 * @param input
		 *   Input IMF stream
		 *
		 * @param imfType
		 *   0 or 1 for IMF type-0 or type-1
		 *
		 * @param hzSpeed
		 *   Speed of IMF file in Hertz (280/560/700)
		 */
		MusicReader_IMF(stream::input_sptr input, int imfType, int hzSpeed)
			throw (stream::error);

		virtual ~MusicReader_IMF()
			throw ();

		virtual void rewind()
			throw ();

		virtual bool nextPair(uint32_t *delay, uint8_t *chipIndex, uint8_t *reg, uint8_t *val)
			throw (stream::error);

		// TODO: metadata functions
};

/// MusicWriter class that can produce IMF music files.
class MusicWriter_IMF: virtual public MusicWriter_GenericOPL {

	protected:
		stream::output_sptr output; ///< Stream to write IMF data into
		int imfType;         ///< 0 or 1 for IMF variant
		int usPerTick;       ///< Latest microseconds per tick value (tempo)
		int hzSpeed;         ///< Speed of IMF file in Hertz (280/560/700)

	public:

		/// Write an IMF file
		/**
		 * @param input
		 *   Input IMF stream
		 *
		 * @param imfType
		 *   0 or 1 for IMF type-0 or type-1
		 *
		 * @param hzSpeed
		 *   Speed of IMF file in Hertz (280/560/700)
		 */
		MusicWriter_IMF(stream::output_sptr output, int imfType, int hzSpeed)
			throw ();

		virtual ~MusicWriter_IMF()
			throw ();

		virtual void start()
			throw (stream::error);

		virtual void finish()
			throw (stream::error);

		virtual void changeSpeed(uint32_t usPerTick)
			throw ();

		virtual void nextPair(uint32_t delay, uint8_t chipIndex, uint8_t reg, uint8_t val)
			throw (stream::error);

		// TODO: metadata functions

};

} // namespace gamemusic
} // namespace camoto

#endif // _CAMOTO_GAMEMUSIC_MUS_IMF_IDSOFTWARE_HPP_
