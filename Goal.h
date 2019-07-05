/** @file *//********************************************************************************************************

                                                     Goal.h

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

class Goal
{
public:

	//! @param	conditions	Conditions necessary to achieve this goal
	//! @param	name		Name of the goal

	Goal( Planner::State const & conditions, std::string const & name )
		: m_Conditions( conditions )
		, m_Name( name )
	{
	}

	virtual ~Goal()
	{
	}

	//! @brief	Creates a copy of this goal
	//!
	//! @note	This function is pure virtual and must be implemented by derived classes.

	Goal * Clone() const = 0;

	//! Returns the conditions for the goal
	Planner::State const & GetConditions() const	{ return m_Conditions; }

	//! Returns the name of the goal
	std::string const & GetName() const				{ return m_Name; }

protected:

private:

	Planner::State	m_Conditions;
	std::string		m_Name;
};
