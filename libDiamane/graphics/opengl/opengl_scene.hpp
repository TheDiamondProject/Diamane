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

#if !defined(DIAMANE_OPENGL_SCENE_HPP)
#define DIAMANE_OPENGL_SCENE_HPP

#include <memory>
#include "libDiamane/graphics/common/scene.hpp"
#include "libDiamane/graphics/opengl/opengl_context.hpp"

namespace diamane { namespace graphics { namespace opengl {

    class scene : public graphics::scene
    {
    private:
        opengl::context& m_context;

    public:
        scene(opengl::context& context);
        scene(opengl::context& context, const std::string& name);

        auto update() -> void override;
        auto render() -> void override;

        auto create_texture(const std::string &name, const math::size &sz, std::vector<uint32_t> data) -> std::weak_ptr<graphics::texture> override;

        auto key(event::keycode code, event::key_state state) const -> bool override;
    };

}}};

#endif //DIAMANE_OPENGL_SCENE_HPP
