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

#if !defined(DIAMANE_OPENGL_SPRITE_RENDERER_HPP)
#define DIAMANE_OPENGL_SPRITE_RENDERER_HPP

#include <memory>
#include "libDiamane/graphics/opengl/opengl_headers.hpp"
#include "libDiamane/graphics/opengl/opengl_shader.hpp"
#include "libDiamane/graphics/common/sprite.hpp"

namespace diamane { namespace graphics { namespace opengl {

    class sprite_renderer
    {
    private:
        GLuint m_vao;
        GLuint m_vbo;
        std::shared_ptr<opengl::shader> m_shader;

    public:
        sprite_renderer(std::weak_ptr<opengl::shader> shader);
        ~sprite_renderer();

        auto draw(std::shared_ptr<graphics::sprite> sprite) const -> void;

    };

}}};

#endif //DIAMANE_OPENGL_SPRITE_RENDERER_HPP
