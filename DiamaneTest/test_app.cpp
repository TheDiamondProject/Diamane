#include <libDiamane/application/application.hpp>
#include <libDiamane/application/events/keyboard.hpp>
#include <libDiamane/graphics/common/context.hpp>

int main(int argc, char const *argv[])
{
	// Create an app session - this will setup a new graphical context as well.
	return diamane::app().start(argc, argv, [] (std::vector<std::string> arguments) {

		// Acquire the graphical context.
		auto context = diamane::app().current_context();
		context->set_size(1024, 768);
		context->set_title("Diamane");

		// Push a scene into the context.
		if (auto scene = context->begin_scene("SquareScene").lock()) {
            auto sprite = scene->spawn_sprite("square", {100, 100}, {100, 100});
            sprite.lock()->set_texture(scene->create_texture("blank", { 100, 100 }));


            scene->handle_mouse([sprite] (diamane::event::mouse mouse) {
                if (mouse.action() != diamane::event::mouse::action::moved) {
                    sprite.lock()->set_origin({ mouse.x(), mouse.y() });
                }
            });

            scene->handle_key([sprite] (diamane::event::key key) {
                if (key.state() == diamane::event::key::held && key.code() == diamane::event::key::code::equal) {
                    auto sz = sprite.lock()->size();
                    sz.set_width(sz.width() + 1);
                    sz.set_height(sz.height() + 1);
                    sprite.lock()->set_size(sz);
                }
            });
		}

	});
}