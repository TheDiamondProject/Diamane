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

#if !defined(DIAMANE_RECT_HPP)
#define DIAMANE_RECT_HPP

#include "libDiamane/math/point.hpp"
#include "libDiamane/math/size.hpp"

namespace diamane { namespace math {

    struct rect
    {
    private:
        math::point m_point;
        math::size m_size;

    public:
        rect();
        rect(const double& x, const double& y, const double& width, const double& height);
        rect(const math::point& p, const math::size& sz);
        rect(const math::rect& r);

        static auto zero() -> math::rect;

        auto x() const -> double;
        auto y() const -> double;
        auto max_x() const -> double;
        auto max_y() const -> double;
        auto width() const -> double;
        auto height() const -> double;

        auto set_x(const double& x) -> void;
        auto set_y(const double& y) -> void;
        auto set_max_x(const double& max_x) -> void;
        auto set_max_y(const double& max_y) -> void;
        auto set_width(const double& width) -> void;
        auto set_height(const double& height) -> void;

        auto contains(const math::point& p) const -> bool;
    };

}};
#endif //DIAMANE_RECT_HPP
