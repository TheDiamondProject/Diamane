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

#if !defined(DIAMANE_OPENGL_TEXTURE_HPP)
#define DIAMANE_OPENGL_TEXTURE_HPP

#include "libDiamane/graphics/common/texture.hpp"
#include "libDiamane/graphics/opengl/opengl_headers.hpp"

namespace diamane { namespace graphics { namespace opengl {

    class texture: public graphics::texture
    {
    private:
        GLuint m_id;
        GLuint m_internal_format { GL_RGBA };
        GLuint m_image_format { GL_RGBA };
        GLuint m_wrap_s { GL_REPEAT };
        GLuint m_wrap_t { GL_REPEAT };
        GLuint m_filter_min { GL_NEAREST };
        GLuint m_filter_max { GL_NEAREST };
        GLuint m_env_mode { GL_MODULATE };

    public:
        texture(const double& width, const double& height);
        texture(const math::size& sz);
        texture(const double& width, const double& height, std::vector<uint32_t> data);
        texture(const math::size& sz, std::vector<uint32_t> data);

        ~texture();

        auto generate() const -> void override;
        auto bind() const -> void override;
    };

}}};

#endif //DIAMANE_OPENGL_TEXTURE_HPP
