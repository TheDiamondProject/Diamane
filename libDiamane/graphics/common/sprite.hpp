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

#if !defined(DIAMANE_SPRITE_HPP)
#define DIAMANE_SPRITE_HPP

#include <memory>
#include "libDiamane/math/point.hpp"
#include "libDiamane/math/size.hpp"
#include "libDiamane/graphics/common/texture.hpp"

namespace diamane { namespace graphics {

    class sprite: public std::enable_shared_from_this<graphics::sprite>
    {
    private:
        math::size m_size;
        math::point m_origin;
        std::shared_ptr<graphics::texture> m_texture;

    public:
        sprite();
        sprite(const math::size& sz);
        sprite(const math::point& origin, const math::size& sz);

        auto set_size(const math::size& sz) -> void;
        auto size() const -> math::size;

        auto set_origin(const math::point& origin) -> void;
        auto origin() const -> math::point;

        auto set_texture(std::weak_ptr<graphics::texture> texture) -> void;
        auto set_texture(std::shared_ptr<graphics::texture> texture) -> void;
        auto texture() const -> std::shared_ptr<graphics::texture>;

    };

}}

#endif //DIAMANE_SPRITE_HPP
