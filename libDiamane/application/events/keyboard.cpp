// Copyright (c) 2020 Tom Hancocks
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "libDiamane/application/events/keyboard.hpp"

// MARK: - Construction

diamane::event::key::key(const enum key::code& code, const int& scancode, const enum key::state& state)
    : m_keycode(code), m_scancode(scancode), m_state(state)
{

}

// MARK: - Accessors

auto diamane::event::key::code() const -> enum key::code
{
    return m_keycode;
};

auto diamane::event::key::modifiers() const -> enum key::modifier
{
    return m_modifiers;
};

auto diamane::event::key::state() const -> enum key::state
{
    return m_state;
};

auto diamane::event::key::scancode() const -> int
{
    return m_scancode;
}
