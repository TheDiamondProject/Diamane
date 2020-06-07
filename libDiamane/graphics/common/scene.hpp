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

#if !defined(DIAMANE_SCENE_HPP)
#define DIAMANE_SCENE_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include "libDiamane/graphics/common/sprite.hpp"
#include "libDiamane/graphics/common/texture.hpp"
#include "libDiamane/application/events/keyboard.hpp"
#include "libDiamane/application/events/mouse.hpp"

namespace diamane { namespace graphics {

    class scene
    {
    protected:
        std::string m_name;
        std::map<std::string, std::shared_ptr<graphics::sprite>> m_sprites;
        std::map<std::string, std::shared_ptr<graphics::texture>> m_textures;
        std::function<auto()->void> m_update_handler;
        std::function<auto(event::mouse)->void> m_mouse_event;
        std::function<auto(event::key)->void> m_key_event;

    public:
        scene();
        scene(const std::string& name);

        virtual auto render() -> void;
        virtual auto update() -> void;

        virtual auto spawn_sprite(const std::string& name, const math::point& origin, const math::size& sz) -> std::weak_ptr<graphics::sprite>;
        virtual auto sprite(const std::string& name) -> std::weak_ptr<graphics::sprite>;

        virtual auto create_texture(const std::string& name, const math::size& sz) -> std::weak_ptr<graphics::texture>;
        virtual auto create_texture(const std::string& name, const math::size& sz, std::vector<uint32_t> data) -> std::weak_ptr<graphics::texture> { return {}; };
        virtual auto texture(const std::string& name) -> std::weak_ptr<graphics::texture>;

        virtual auto update_handler(std::function<auto()->void> handler) -> void;

        virtual auto handle_mouse(std::function<auto(event::mouse)->void> handler) -> void;
        auto send_event(const event::mouse& event) const -> void;

        virtual auto handle_key(std::function<auto(event::key)->void> handler) -> void;
        auto send_event(const event::key& event) const -> void;

    };

}};

#endif //DIAMANE_SCENE_HPP
