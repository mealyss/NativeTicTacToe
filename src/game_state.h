#pragma once

namespace stg
{
	class GameState
	{
	public:
		virtual void initialize() = 0;

		virtual void handleInput() = 0;
		virtual void update(float dt) = 0;
		virtual void draw(float dt) = 0;

		virtual void pause() {}
		virtual void resume() {}

	};
}
