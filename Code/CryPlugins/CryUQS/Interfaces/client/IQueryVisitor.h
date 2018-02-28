// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

// *INDENT-OFF* - <hard to read code and declarations due to inconsistent indentation>

namespace UQS
{
	namespace Client
	{

		//===================================================================================
		//
		// IQueryVisitor - allows for visiting all currently running queries in the Core::IQueryManager
		//
		//===================================================================================

		struct IQueryVisitor
		{
			struct SQueryInfo
			{
				explicit        SQueryInfo(const Core::CQueryID& _queryID, const Core::CQueryID& _parentQueryID, const char* _szQuerierName, const char* _szQueryBlueprintName, int _numGeneratedItems, int _numRemainingItemsToInspect, const CTimeValue& _queryCreatedTimestamp, int _numElapsedFramesSoFar, const CTimeValue& _timeConsumedSoFar);

				Core::CQueryID  queryID;
				Core::CQueryID  parentQueryID;
				const char*     szQuerierName;
				const char*     szQueryBlueprintName;
				int             numGeneratedItems;
				int             numRemainingItemsToInspect;
				CTimeValue      queryCreatedTimestamp;
				int             numElapsedFramesSoFar;
				CTimeValue      timeConsumedSoFar;
			};

			virtual void        OnQueryVisited(const SQueryInfo& queryInfo) = 0;

		protected:

			~IQueryVisitor() {}		// protected non-virtual dtor since deletion through base-class pointers is not intended
		};

		inline IQueryVisitor::SQueryInfo::SQueryInfo(const Core::CQueryID& _queryID, const Core::CQueryID& _parentQueryID, const char* _szQuerierName, const char* _szQueryBlueprintName, int _numGeneratedItems, int _numRemainingItemsToInspect, const CTimeValue& _queryCreatedTimestamp, int _numElapsedFramesSoFar, const CTimeValue& _timeConsumedSoFar)
			: queryID(_queryID)
			, parentQueryID(_parentQueryID)
			, szQuerierName(_szQuerierName)
			, szQueryBlueprintName(_szQueryBlueprintName)
			, numGeneratedItems(_numGeneratedItems)
			, numRemainingItemsToInspect(_numRemainingItemsToInspect)
			, queryCreatedTimestamp(_queryCreatedTimestamp)
			, numElapsedFramesSoFar(_numElapsedFramesSoFar)
			, timeConsumedSoFar(_timeConsumedSoFar)
		{}

	}
}