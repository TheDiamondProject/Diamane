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

            scene->update_handler([sprite, scene] {

                if (scene->key(diamane::event::keycode::d, diamane::event::key_state::pressed)) {
                    auto pos = sprite.lock()->origin();
                    pos.set_x(pos.x() + 1);
                    sprite.lock()->set_origin(pos);
                }

            });
		}

	});
}