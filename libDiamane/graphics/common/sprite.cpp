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

#include "libDiamane/graphics/common/sprite.hpp"

// MARK: - Construction

diamane::graphics::sprite::sprite()
    : m_origin(), m_size()
{

}

diamane::graphics::sprite::sprite(const diamane::math::size &sz)
    : m_origin(0, 0), m_size(sz)
{

}

diamane::graphics::sprite::sprite(const diamane::math::point& origin, const diamane::math::size &sz)
    : m_origin(origin), m_size(sz)
{

}

// MARK: - Accessors

auto diamane::graphics::sprite::set_size(const math::size &sz) -> void
{
    m_size = sz;
}

auto diamane::graphics::sprite::size() const -> math::size
{
    return m_size;
}

auto diamane::graphics::sprite::set_origin(const math::point &origin) -> void
{
    m_origin = origin;
}

auto diamane::graphics::sprite::origin() const -> math::point
{
    return m_origin;
}

auto diamane::graphics::sprite::set_texture(std::weak_ptr<graphics::texture> texture) -> void
{
    if (auto t = texture.lock()) {
        m_texture = t;
    }
    else {
        m_texture = nullptr;
    }
}

auto diamane::graphics::sprite::set_texture(std::shared_ptr<graphics::texture> texture) -> void
{
    m_texture = texture;
}

auto diamane::graphics::sprite::texture() const -> std::shared_ptr<graphics::texture>
{
    return m_texture;
}
