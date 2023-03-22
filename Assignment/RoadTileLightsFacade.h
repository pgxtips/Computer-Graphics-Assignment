#include <TrafficSystem/RoadFacade.h>
#include "ControlledTrafficLightFacade.h"
#pragma once

namespace Assignment
{

	typedef std::list<ControlledTrafficLightFacade*> Lights;

	class RoadTileLightsFacade: public TrafficSystem::RoadFacade
	{
	public:

		RoadTileLightsFacade(std::string sName, osg::Node* pAsset, osg::Matrixf m, bool bVisible);
		virtual ~RoadTileLightsFacade();
		void addLight(ControlledTrafficLightFacade* pCTLF);

	protected:
		Lights m_lLights;
	};

}
