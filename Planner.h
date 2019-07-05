/** @file *//********************************************************************************************************

                                                     Planner.h

						                    Copyright 2008, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: $

	$NoKeywords: $

*********************************************************************************************************************/

#pragma once


#include <bitset>

class Action;
class Goal;


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

class Planner
{
public:

	typedef std::bitset<128>	State;

	//! Constructor
	Planner( std::vector<ActionTemplate const *> const & domain );

	// Destructor
	virtual ~Planner();

	// Copy constructor and assignment operator
	Planner( Planner const & src );
	Planner const & operator =( Planner const & rhs );

	//! Creates a plan

	Plan MakePlan( Goal const & goal, State const & currentState ) const;

protected:

private:

};

class Planner::State
{
}