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

#include "libDiamane/application/events/mouse.hpp"

// MARK: - Construction

diamane::event::mouse::mouse(const int &x, const int &y, const enum mouse::action action, const enum mouse::button button)
    : m_x(x), m_y(y), m_button(button), m_action(action)
{

}

diamane::event::mouse::mouse(enum mouse::action action, enum mouse::button button)
    : m_x(-1), m_y(-1), m_button(button), m_action(action)
{

};

// MARK: - Accessors

auto diamane::event::mouse::x() const -> int
{
    return m_x;
}

auto diamane::event::mouse::y() const -> int
{
    return m_y;
}

auto diamane::event::mouse::action() const -> enum mouse::action
{
    return m_action;
};

auto diamane::event::mouse::button() const -> enum mouse::button
{
    return m_button;
}
