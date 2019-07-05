/** @file *//********************************************************************************************************

                                                    Plan.cpp

						                    Copyright 2008, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: $

	$NoKeywords: $

*********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Plan.h"

//#include "Misc/Exceptions.h"

/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Plan::Plan()
	: m_pGoal( NULL )
{
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Plan::Plan( Goal const & goal, ActionList const & steps )
	: m_pGoal( goal.Clone() )
{
	m_Steps.reserve( steps.size() );
	for ( ActionList::const_iterator ppAction = steps.begin(); ppAction != steps.end(); ++ppAction )
	{
		Action const * pAction = *ppAction;

		if ( pAction != NULL )
		{
			m_Steps.push_back( pAction->Clone() );
		}
	}
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Plan::~Plan()
{
	delete m_pGoal;

	for ( ActionList::iterator ppAction = m_Steps.begin(); ppAction != m_Steps.end(); ++ppAction )
	{
		delete *ppAction;
	}
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/
Plan( Plan const & src )
{
	m_pGoal = ( src.m_pGoal != NULL ) ? src.m_pGoal->Clone() : NULL;
	m_Steps.reserve( src.m_Steps.size() );
	for ( ActionList::const_iterator ppAction = src.m_Steps.begin(); ppAction != src.m_Steps.end(); ++ppAction )
	{
		Action const * pAction = *ppAction;
		m_Steps.push_back( pAction->Clone() );
	}
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Plan const & operator =( Plan const & rhs )
{
	if ( this != &rhs )
	{
		delete m_pGoal;

		for ( ActionList::iterator ppAction = m_Steps.begin(); ppAction != m_Steps.end(); ++ppAction )
		{
			delete *ppAction;
		}

		m_Steps.clear();

		m_pGoal = ( rhs.m_pGoal != NULL ) ? rhs.m_pGoal->Clone() : NULL;

		m_Steps.reserve( rhs.m_Steps.size() );
		for ( ActionList::const_iterator ppAction = rhs.m_Steps.begin(); ppAction != rhs.m_Steps.end(); ++ppAction )
		{
			Action const * pAction = *ppAction;
			m_Steps.push_back( pAction->Clone() );
		}
	}

	return *this;
}
