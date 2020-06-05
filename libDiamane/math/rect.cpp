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

#include "libDiamane/math/rect.hpp"

// MARK: - Construction

diamane::math::rect::rect()
    : m_point(math::point::zero()), m_size(math::size::zero())
{

}

diamane::math::rect::rect(const double& x, const double& y, const double& width, const double& height)
    : m_point(x, y), m_size(width, height)
{

}

diamane::math::rect::rect(const math::point& p, const math::size& sz)
    : m_point(p), m_size(sz)
{

}

diamane::math::rect::rect(const math::rect& r)
    : m_point(r.m_point), m_size(r.m_size)
{

}

auto diamane::math::rect::zero() -> math::rect
{
    return math::rect();
}

// MARK: - Accessors

auto diamane::math::rect::x() const -> double
{
    return m_point.x();
}

auto diamane::math::rect::y() const -> double
{
    return m_point.y();
}

auto diamane::math::rect::max_x() const -> double
{
    return m_point.x() + m_size.width();
}

auto diamane::math::rect::max_y() const -> double
{
    return m_point.y() + m_size.height();
}

auto diamane::math::rect::width() const -> double
{
    return m_size.width();
}

auto diamane::math::rect::height() const -> double
{
    return m_size.height();
}

auto diamane::math::rect::set_x(const double& x) -> void
{
    m_point.set_x(x);
}
auto diamane::math::rect::set_y(const double& y) -> void
{
    m_point.set_y(y);
}

auto diamane::math::rect::set_max_x(const double& max_x) -> void
{
    set_width(max_x - width());
}
auto diamane::math::rect::set_max_y(const double& max_y) -> void
{
    set_height(max_y - height());
}

auto diamane::math::rect::set_width(const double& width) -> void
{
    m_size.set_width(width);
}
auto diamane::math::rect::set_height(const double& height) -> void
{
    m_size.set_height(height);
}

// MARK: - Checks

auto diamane::math::rect::contains(const math::point &p) const -> bool
{
    return (p.x() >= x() && p.x() <= max_x()) && (p.y() >= y() && p.y() <= max_y());
}
