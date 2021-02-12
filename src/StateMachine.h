#pragma once

#include <memory>
#include <stack>

#include "GameState.h"

namespace stg
{
	typedef std::unique_ptr<GameState> GameStateRef;

	class StateMachine
	{
	public:
		StateMachine();
		~StateMachine();

		void addState(GameStateRef newState, bool isReplacing = true);
		void removeState();

		void processStateChanges();

		GameStateRef& getActiveState();
	private:
		std::stack<GameStateRef> _states;
		GameStateRef _newState;

		bool _isAdding;
		bool _isReplacing;
		bool _isRemoving;
	};

}
