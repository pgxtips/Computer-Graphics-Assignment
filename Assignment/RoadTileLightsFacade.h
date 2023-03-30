#include <TrafficSystem/RoadFacade.h>
#include "ControlledTrafficLightFacade.h"
#pragma once

namespace Assignment
{

	typedef std::list<ControlledTrafficLightFacade*> Lights;

	class RoadTileLightsFacade: public TrafficSystem::RoadFacade, public osg::Callback
	{
	public:

		RoadTileLightsFacade(std::string sName, osg::Node* pAsset, osg::Matrixf m, bool bVisible);
		virtual ~RoadTileLightsFacade();
		void addLight(ControlledTrafficLightFacade* pCTLF);
		virtual bool run(osg::Object* object, osg::Object* data);

	protected:
		Lights m_lLights;
		
		Lights::iterator m_itCurrentLight;
		unsigned int m_uiCount;
	};

}
