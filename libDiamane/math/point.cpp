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

#include "libDiamane/math/point.hpp"

// MARK: - Construction

diamane::math::point::point()
    : m_x(0), m_y(0)
{

}

diamane::math::point::point(const double& x, const double& y)
    : m_x(x), m_y(y)
{

}

diamane::math::point::point(const math::point& p)
    : m_x(p.m_x), m_y(p.m_y)
{

}

auto diamane::math::point::zero() -> math::point
{
    return math::point();
}

// MARK: - Accessors

auto diamane::math::point::x() const -> double
{
    return m_x;
}

auto diamane::math::point::y() const -> double
{
    return m_y;
}

auto diamane::math::point::set_x(const double& x) -> void
{
    m_x = x;
}
auto diamane::math::point::set_y(const double& y) -> void
{
    m_y = y;
}
