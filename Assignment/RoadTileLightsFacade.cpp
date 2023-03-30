#include "RoadTileLightsFacade.h"
#include <TrafficSystem/RoadFacade.h>

Assignment::RoadTileLightsFacade::RoadTileLightsFacade(std::string sName, osg::Node* pAsset, osg::Matrixf m, bool bVisible): TrafficSystem::RoadFacade(sName, pAsset, m, bVisible), m_uiCount(0), m_itCurrentLight(m_lLights.end())
{
	pAsset->setUpdateCallback(this);
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
		pCTLF->SetState(Assignment::ControlledTrafficLightFacade::STOP);
	}
	
}

bool Assignment::RoadTileLightsFacade::run(osg::Object* object, osg::Object* data)	
{
		if (m_uiCount <= 100)
		{
			if (m_itCurrentLight == m_lLights.end()) m_itCurrentLight = m_lLights.begin();

			if(m_uiCount==100)
			{
				m_uiCount = 0;

				if (m_itCurrentLight != m_lLights.end()) (*m_itCurrentLight)->SetState(ControlledTrafficLightFacade::STOP);

				if (m_lLights.size() > 1)
				{
					m_itCurrentLight++;
					if (m_itCurrentLight == m_lLights.end()) m_itCurrentLight = m_lLights.begin();
				}

				if (m_itCurrentLight != m_lLights.end()) (*m_itCurrentLight)->SetState(ControlledTrafficLightFacade::READY);
			}
			else if (m_uiCount == 30) if (m_itCurrentLight != m_lLights.end()) (*m_itCurrentLight)->SetState(ControlledTrafficLightFacade::GO);
			else if (m_uiCount == 70) if (m_itCurrentLight != m_lLights.end()) (*m_itCurrentLight)->SetState(ControlledTrafficLightFacade::SLOW);

			m_uiCount++;
		}
		return true;	
}
