#include "RoadTileLightsFacadeFactory.h"

Assignment::RoadTileLightsFacadeFactory::RoadTileLightsFacadeFactory()
{

}

Assignment::RoadTileLightsFacadeFactory::~RoadTileLightsFacadeFactory()
{

}

Common::Facade* Assignment::RoadTileLightsFacadeFactory::create(std::string sname, osg::Node* pAsset, osg::Matrixf m, bool bVisible)
{
	return new RoadTileLightsFacade(sname, pAsset, m, bVisible);	
}