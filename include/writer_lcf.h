/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG.
//
// EasyRPG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

#ifndef EASYRPG_WRITER_LCF_H
#define EASYRPG_WRITER_LCF_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <iosfwd>
#include <cstring>
#include <cstdio>
#include <cassert>
#include "reader_types.h"
#include "reader_options.h"
#include "reader_util.h"

////////////////////////////////////////////////////////////
/// LcfWriter class.
////////////////////////////////////////////////////////////
class LcfWriter {
public:
	////////////////////////////////////////////////////////
	/// Constructs a new File Writer.
	/// @param filename : File to open.
	////////////////////////////////////////////////////////
	LcfWriter(const char* filename, std::string encoding = "");

	////////////////////////////////////////////////////////
	/// Constructs a new File Writer.
	/// @param filename : File to open.
	////////////////////////////////////////////////////////
	LcfWriter(const std::string& filename, std::string encoding = "");

	////////////////////////////////////////////////////////
	/// Destructor. Closes the opened file.
	////////////////////////////////////////////////////////
	~LcfWriter();

	////////////////////////////////////////////////////////
	/// Closes the opened file.
	////////////////////////////////////////////////////////
	void Close();

	////////////////////////////////////////////////////////
	/// Writes raw data to the stream (fwrite() wrapper)
	/// @param ptr : pointer to buffer
	/// @param size : size of each element
	/// @param nmemb : number of elements
	////////////////////////////////////////////////////////
	void Write(const void *ptr, size_t size, size_t nmemb);

	////////////////////////////////////////////////////////
	/// Write a primitive value to the stream.
	/// @param val : the value
	////////////////////////////////////////////////////////
	template <class T>
	void Write(T val);

	////////////////////////////////////////////////////////
	/// Writes a string to the stream.
	/// @param str : The string
	/// note: the string is converted to the native encoding
	////////////////////////////////////////////////////////
	void Write(const std::string& str);

	////////////////////////////////////////////////////////
	/// Writes a compressed integer to the stream.
	/// @param val : The integer
	////////////////////////////////////////////////////////
	void WriteInt(int val);

	////////////////////////////////////////////////////////
	/// Write a vector of primitive values to the stream.
	/// @param buffer : Vector to write
	////////////////////////////////////////////////////////
	template <class T>
	void Write(const std::vector<T>& buffer);

	////////////////////////////////////////////////////////
	/// Checks if the file is writable and if no error
	/// occured.
	/// @return If the stream is okay
	////////////////////////////////////////////////////////
	bool IsOk() const;

	////////////////////////////////////////////////////////
	/// Decodes a string from Utf8 to the set encoding
	/// in the Writer constructor.
	/// @param str_to_encode : UTF-8 string to encode
	/// @return native version of string
	////////////////////////////////////////////////////////
	std::string Decode(const std::string& str_to_encode);

private:
	/// Name of the file that is associated with the stream
	std::string filename;
	/// Name of the encoding
	std::string encoding;
	/// File-stream managed by this Writer
	FILE* stream;

#ifdef READER_BIG_ENDIAN
	////////////////////////////////////////////////////////
	/// Utility function for Big Endian Systems.
	/// Convert a 16bit integer from little to big endian.
	/// @param us : Integer to convert
	////////////////////////////////////////////////////////
	static void SwapByteOrder(uint16_t &us);

	////////////////////////////////////////////////////////
	/// Utility function for Big Endian Systems.
	/// Convert a 32bit integer from little to big endian.
	/// @param us : Integer to convert
	////////////////////////////////////////////////////////
	static void SwapByteOrder(uint32_t &ui);
#endif
};

#endif