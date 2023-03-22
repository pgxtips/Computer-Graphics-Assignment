#include <Common/FacadeFactoryA.h>
#include "RoadTileLightsFacade.h"
#pragma once

namespace Assignment
{

	class RoadTileLightsFacadeFactory: public Common::FacadeFactoryA
	{
	public:
		RoadTileLightsFacadeFactory();
		virtual ~RoadTileLightsFacadeFactory();
		virtual Common::Facade* create(std::string sname, osg::Node* pAsset, osg::Matrixf m, bool bVisible) override;

	};



}