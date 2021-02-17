#include "state_machine.h"


namespace stg
{

StateMachine::StateMachine()
{
	m_isAdding = false;
	m_isRemoving = false;
	m_isReplacing = false;
}

void StateMachine::addState(GameStateRef newState, bool isReplacing)
{
	m_isAdding = true;
	m_isReplacing = isReplacing;
	m_newState = std::move(newState);
}

void StateMachine::removeState()
{
	m_isRemoving = true;
}

void StateMachine::processStateChanges()
{
	if (m_isRemoving && m_states.empty())
	{
		m_states.pop();
		if (m_states.empty() == false)
		m_states.top()->resume();
		m_isRemoving = false;
	}

	if (m_isAdding)
	{
		if (!m_states.empty())
		{
			if (m_isReplacing)
				m_states.pop();
			else
				m_states.top()->pause();
		}
		m_states.push(std::move(m_newState));
		m_states.top()->initialize();
		m_isAdding = false;

	}

}

GameStateRef& StateMachine::getActiveState()
{
	return m_states.top();
}

}

