#include "ControlledTrafficLightFacadeFactory.h"

Assignment::ControlledTrafficLightFacadeFactory::ControlledTrafficLightFacadeFactory() 
{
}

Assignment::ControlledTrafficLightFacadeFactory::~ControlledTrafficLightFacadeFactory()
{
}

Common::Facade* Assignment::ControlledTrafficLightFacadeFactory::create(std::string sname, osg::Node* pAsset, osg::Matrixf m, bool bVisible) 
{
	return new Assignment::ControlledTrafficLightFacade(sname, pAsset, m, bVisible);
}
