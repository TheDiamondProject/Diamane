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

#include "libDiamane/math/size.hpp"

// MARK: - Construction

diamane::math::size::size()
    : m_width(0), m_height(0)
{

}

diamane::math::size::size(const double& width, const double& height)
    : m_width(width), m_height(height)
{

}

diamane::math::size::size(const math::size& sz)
    : m_width(sz.m_width), m_height(sz.m_height)
{

}

auto diamane::math::size::zero() -> math::size
{
    return math::size();
}

// MARK: - Accessors

auto diamane::math::size::width() const -> double
{
    return m_width;
}

auto diamane::math::size::height() const -> double
{
    return m_height;
}

auto diamane::math::size::set_width(const double& width) -> void
{
    m_width = width;
}
auto diamane::math::size::set_height(const double& height) -> void
{
    m_height = height;
}

