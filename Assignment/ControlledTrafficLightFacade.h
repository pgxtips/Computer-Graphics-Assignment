#pragma once
#include <TrafficSystem/TrafficLightFacade.h>
#include <osg/Material>

namespace Assignment 
{
	class ControlledTrafficLightFacade : public TrafficSystem::TrafficLightFacade
	{
	public:

		ControlledTrafficLightFacade(std::string sname, osg::Node* pAsset, osg::Matrixf m, bool bVisible);
		virtual ~ControlledTrafficLightFacade();

		enum LightState 
		{
			GO,
			READY,
			SLOW,
			STOP
		};
		void SetState(LightState state);

	protected:
		osg::Geode* m_pRed;
		osg::Geode* m_pAmber;
		osg::Geode* m_pGreen;

		static osg::Material* sm_pRedOn;
		static osg::Material* sm_pRedOff;

		static osg::Material* sm_pGreenOn;
		static osg::Material* sm_pGreenOff;

		static osg::Material* sm_pAmberOn;
		static osg::Material* sm_pAmberOff;
	};
}
