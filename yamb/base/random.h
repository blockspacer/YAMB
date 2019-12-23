///
//
// LibSourcey
// Copyright (c) 2005, Sourcey <https://sourcey.com>
//
// SPDX-License-Identifier: LGPL-2.1+
//
/// @addtogroup base
/// @{
// This file uses functions from POCO C++ Libraries (license below).
//


#ifndef SCY_Random_H
#define SCY_Random_H


#include "base.h"
#include <cstdint>


namespace scy {


/// Random implements a pseudo random number generator (PRNG).
/// The PRNG is a nonlinear additive feedback random number
/// generator using 256 bytes of state information
/// and a period of up to 2^69.
class Base_API Random
{
public:
    enum Type
    {
        RND_STATE_0 = 8,     /// linear congruential
        RND_STATE_32 = 32,   /// x**7 + x**3 + 1
        RND_STATE_64 = 64,   /// x**15 + x + 1
        RND_STATE_128 = 128, /// x**31 + x**3 + 1
        RND_STATE_256 = 256  /// x**63 + x + 1
    };

    /// Creates and initializes the PRNG.
    /// Specify either a state buffer size
    /// (8 to 256 bytes) or one of the Type values.
    Random(int stateSize = 256);

    /// Destroys the PRNG.
    ~Random();

    /// Seeds the pseudo random generator with the given seed.
    void seed(uint32_t seed);

    /// Seeds the pseudo random generator with a random seed
    /// obtained from a RandomInputStream.
    void seed();

    /// Returns the next 31-bit pseudo random number.
    uint32_t next();

    /// Returns the next 31-bit pseudo random number modulo n.
    uint32_t next(uint32_t n);

    /// Returns the next pseudo random character.
    char nextChar();

    /// Returns the next boolean pseudo random value.
    bool nextBool();

    /// Returns the next float pseudo random number between 0.0 and 1.0.
    float nextFloat();

    /// Returns the next double pseudo random number between 0.0 and 1.0.
    double nextDouble();

    /// Generates a random seed using native OS functions.
    static void getSeed(char* seed, unsigned length);

protected:
    void initState(uint32_t seed, char* arg_state, std::int32_t n);
    static uint32_t goodRand(std::int32_t x);

private:
    enum
    {
        MAX_TYPES = 5,
        NSHUFF = 50
    };

    uint32_t* _fptr;
    uint32_t* _rptr;
    uint32_t* _state;
    int _randType;
    int _randDeg;
    int _randSep;
    uint32_t* _endPtr;
    char* _buffer;
};


} // namespace scy


#endif // SCY_Random_H


/// @\}


//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
