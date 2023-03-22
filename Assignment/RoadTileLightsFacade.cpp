#include "RoadTileLightsFacade.h"
#include <TrafficSystem/RoadFacade.h>

Assignment::RoadTileLightsFacade::RoadTileLightsFacade(std::string sName, osg::Node* pAsset, osg::Matrixf m, bool bVisible): RoadFacade(sName, pAsset, m, bVisible)
{
 
}

Assignment::RoadTileLightsFacade::~RoadTileLightsFacade()
{

}

void Assignment::RoadTileLightsFacade::addLight(ControlledTrafficLightFacade* pCTLF)
{
	if (pCTLF) 
	{
		// add light to list
		m_lLights.push_back(pCTLF);
		// add light transform to facade transform node tree
		m_pTransformation->addChild(pCTLF->root());
	}
	
}