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

#include "libDiamane/graphics/common/scene.hpp"

// MARK: - Construction

diamane::graphics::scene::scene()
    : m_name("")
{

}

diamane::graphics::scene::scene(const std::string &name)
    : m_name(name)
{

}

// MARK: - Physics / Update Loop

auto diamane::graphics::scene::update_handler(std::function<auto()->void> handler) -> void
{
    m_update_handler = handler;
}

auto diamane::graphics::scene::update() -> void
{
    m_update_handler();
}

// MARK: - Rendering

auto diamane::graphics::scene::render() -> void
{

}

// MARK: - Sprite Management

auto diamane::graphics::scene::spawn_sprite(const std::string& name, const math::point& origin, const math::size& sz) -> std::weak_ptr<graphics::sprite>
{
    // Check if a sprite with this name already exists.
    if (auto existing = sprite(name).lock()) {
        return existing;
    }

    // It doesn't so create it.
    auto sprite = std::make_shared<graphics::sprite>(origin, sz);
    m_sprites.emplace(name, sprite);
    return sprite;
}

auto diamane::graphics::scene::sprite(const std::string& name) -> std::weak_ptr<graphics::sprite>
{
    if (m_sprites.find(name) == m_sprites.end()) {
        return {};
    }
    return m_sprites.at(name);
}

// MARK: - Texture

auto diamane::graphics::scene::create_texture(const std::string &name, const math::size &sz) -> std::weak_ptr<graphics::texture>
{
    return create_texture(name, sz, std::vector<uint32_t>(static_cast<unsigned int>(sz.width() * sz.height()) , 0xFFFFFFFF));
}

auto diamane::graphics::scene::texture(const std::string& name) -> std::weak_ptr<graphics::texture>
{
    if (m_textures.find(name) == m_textures.end()) {
        return {};
    }
    return m_textures.at(name);
}

// MARK: - Events

auto diamane::graphics::scene::key(event::keycode code, event::key_state state) const -> bool
{
    return false;
}

auto diamane::graphics::scene::handle_mouse(std::function<auto(event::mouse)->void> handler) -> void
{
    m_mouse_event = handler;
}

auto diamane::graphics::scene::send_mouse_event(const diamane::event::mouse &event) const -> void
{
    m_mouse_event(event);
}



