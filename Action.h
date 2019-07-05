/** @file *//********************************************************************************************************

                                                     Action.h

						                    Copyright 2008, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: $

	$NoKeywords: $

*********************************************************************************************************************/

#pragma once


#include "Planner.h"
#include <string>


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

class ActionTemplate
{
public:

	//! @param	preconditions	Conditions necessary to do this action
	//! @param	effects			Changes to the state as a result of this action
	//! @param	name			Name of the action
	ActionTemplate( Planner::State const & preconditions, Planner::State const & effects, std::string const & name )
		: m_Preconditions( preconditions )
		, m_Effects( effects )
		, m_Name( name )
	{
	}

	//! Creates an action based on this archetype
	//!
	//! @note	This function is pure virtual and must be implemented by derived classes.
	virtual Action * CreateAction( Goal const * pGoal, Planner::State & remainingConditions, void * pContext ) = 0;

	Planner::State	m_Preconditions;
	Planner::State	m_Effects;
	std::string		m_Name;
};


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

class Action
{
public:

	Action( ActionTemplate const & templateParameters, Goal const * pGoal, Planner::State & remainingConditions, void * pContext );
	virtual ~Action() {}

	// Copy constructor and assignment operator
	Action( Action const & src );
	Action const & operator =( Action const & rhs );

	//! @brief	Creates a copy of this action
	//!
	//! @note	This function is pure virtual and must be implemented by derived classes.
	Action * Clone() = 0;

	//! @brief	Returns the cost of this action
	//!
	//! @note	This function is pure virtual and must be implemented by derived classes.
	int GetCost() const = 0;

protected:

private:
};
