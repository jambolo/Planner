/** @file *//********************************************************************************************************

                                                     Plan.h

						                    Copyright 2008, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: $

	$NoKeywords: $

*********************************************************************************************************************/

#pragma once


#include <vector>


/********************************************************************************************************************/

class Plan
{
public:

	typedef std::vector<Action const *>	ActionList;

	Plan();
	Plan( Goal const & goal, ActionList const & steps );
	virtual ~Plan();

	// Copy constructor and assignment operator
	Plan( Plan const & copy );
	Plan const & operator =( Plan const & rhs );

	//! Returns the goal of the plan
	Goal const * GetGoal() const					{ return m_pGoal; }

	//! Returns the steps in the plan
	ActionList const &	GetSteps() const			{ return m_Steps; }

protected:

private:

	Goal *		m_pGoal;
	ActionList	m_Steps;
};
