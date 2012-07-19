#include "ThymioIntermediateRepresentation.h"

namespace Aseba
{

	ThymioIRButton::ThymioIRButton(int size, ThymioIRButtonName n, int states) : 
		name(n),
		numStates(states)
	{ 
		buttons.resize(size, false); 
	}

	ThymioIRButton::~ThymioIRButton() 
	{ 
		buttons.clear();
	}	

	void ThymioIRButton::setClicked(int i, int status) 
	{ 
		if( i<size() ) buttons[i] = status; 
	}
	
	int ThymioIRButton::isClicked(int i) 
	{ 
		if( i<size() ) 
			return buttons[i]; 
	}
	
	int ThymioIRButton::getNumStates()
	{
		return numStates;
	}
	
	int ThymioIRButton::size() 
	{ 
		return buttons.size(); 
	}

	void ThymioIRButton::setBasename(wstring n)
	{
		basename = n;
	}

	ThymioIRButtonName ThymioIRButton::getName()
	{ 
		return name; 
	}
	
	wstring ThymioIRButton::getBasename()
	{
		return basename;
	}
	
	bool ThymioIRButton::isEventButton()
	{ 
		return (name < 5 ? true : false); 
	}
	
	bool ThymioIRButton::isSet()
	{
		for(int i=0; i<size(); ++i)
		{
			if( buttons[i] > 0 )
				return true;
		}		
	
		return false;
	}

	void ThymioIRButton::accept(ThymioIRVisitor *visitor) 
	{ 
		visitor->visit(this); 
	}

	ThymioIRButtonSet::ThymioIRButtonSet(ThymioIRButton *event, ThymioIRButton *action) : 
		eventButton(event), 
		actionButton(action) 
	{
	}
		
	void ThymioIRButtonSet::addEventButton(ThymioIRButton *event) 
	{ 
		eventButton = event; 
	}
	
	void ThymioIRButtonSet::addActionButton(ThymioIRButton *action) 
	{
		actionButton = action; 
	}
		
	ThymioIRButton *ThymioIRButtonSet::getEventButton() 
	{ 
		return eventButton; 
	}
	
	ThymioIRButton *ThymioIRButtonSet::getActionButton() 
	{ 
		return actionButton;
	}

	bool ThymioIRButtonSet::hasEventButton() 
	{ 
		return (eventButton == 0 ? false : true); 
	}
	
	bool ThymioIRButtonSet::hasActionButton() 
	{ 
		return (actionButton == 0 ? false : true); 
	}
	
	void ThymioIRButtonSet::accept(ThymioIRVisitor *visitor) 
	{ 
		visitor->visit(this); 
	}

		
}; // Aseba
