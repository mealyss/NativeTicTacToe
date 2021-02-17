#pragma once

#include <memory>
#include <stack>

#include "game_state.h"

namespace stg
{
	typedef std::unique_ptr<GameState> GameStateRef;

	class StateMachine
	{
	public:
		StateMachine();
		~StateMachine()	{}

		void addState(GameStateRef newState, bool isReplacing = true);
		void removeState();

		void processStateChanges();

		GameStateRef& getActiveState();
	private:
		std::stack<GameStateRef> m_states;
		GameStateRef m_newState;

		bool m_isAdding;
		bool m_isReplacing;
		bool m_isRemoving;
	};

}
