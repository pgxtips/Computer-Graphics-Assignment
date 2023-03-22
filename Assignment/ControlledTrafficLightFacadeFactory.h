#pragma once

#include "Common/FacadeFactoryA.h"
#include "ControlledTrafficLightFacade.h"

namespace Assignment 
{
	class ControlledTrafficLightFacadeFactory : public Common::FacadeFactoryA
	{
	public:
		ControlledTrafficLightFacadeFactory();
		virtual ~ControlledTrafficLightFacadeFactory();
		virtual Common::Facade* create(std::string sname, osg::Node* pAsset, osg::Matrixf m, bool bVisible) override;
	};
	
}