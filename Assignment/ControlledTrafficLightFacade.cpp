#include "ControlledTrafficLightFacade.h"
#include <osg/Geode>
#include <osg/Material>
#include <Common/NodeFinderT.h>


osg::Material* Assignment::ControlledTrafficLightFacade::sm_pRedOn = 0;
osg::Material* Assignment::ControlledTrafficLightFacade::sm_pRedOff = 0;

osg::Material* Assignment::ControlledTrafficLightFacade::sm_pGreenOn = 0;
osg::Material* Assignment::ControlledTrafficLightFacade::sm_pGreenOff = 0;

osg::Material* Assignment::ControlledTrafficLightFacade::sm_pAmberOn = 0;
osg::Material* Assignment::ControlledTrafficLightFacade::sm_pAmberOff = 0;

Assignment::ControlledTrafficLightFacade::ControlledTrafficLightFacade(std::string sname, osg::Node* pAsset, osg::Matrixf m, bool bVisible) : TrafficLightFacade(sname, pAsset, m, bVisible), m_pRed(0), m_pAmber(0), m_pGreen(0)
{
	m_pRoot->ref();

	// find traffic light lamp geometry nodes
	Common::NodeFinderT<osg::Geode> amberLampFinder("trafficLight::AmberLamp-GEODE");
	Common::NodeFinderT<osg::Geode> redLampFinder("trafficLight::RedLamp-GEODE");
	Common::NodeFinderT<osg::Geode> greenLampFinder("trafficLight::GreenLamp-GEODE");

	if (m_pAsset)
	{
		if (m_pAmber = amberLampFinder.find(m_pRoot)) m_pAmber->ref();
		if (m_pRed = redLampFinder.find(m_pRoot)) m_pRed->ref();
		if (m_pGreen = greenLampFinder.find(m_pRoot)) m_pGreen->ref();
	}

	// if not initialised, define material for traffic light lamp geometry nodes

	if (!sm_pRedOn)
	{
		sm_pRedOn = new osg::Material();
		sm_pRedOn->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.2f, 0.0f, 0.0f, 1.0f));
		sm_pRedOn->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.7f, 0.0f, 0.0f, 1.0f));
		sm_pRedOn->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.6f, 0.0f, 0.0f, 1.0f));
	}

	if (!sm_pRedOff)
	{
		sm_pRedOff = new osg::Material();
		sm_pRedOff->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.2f, 0.0f, 0.0f, 1.0f));
		sm_pRedOff->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.2f, 0.0f, 0.0f, 1.0f));
		sm_pRedOff->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.6f, 0.0f, 0.0f, 1.0f));
	}

	if (!sm_pGreenOn)
	{
		sm_pGreenOn = new osg::Material();
		sm_pGreenOn->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.0f, 0.2f, 0.0f, 1.0f));
		sm_pGreenOn->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.0f, 0.7f, 0.0f, 1.0f));
		sm_pGreenOn->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.0f, 0.6f, 0.0f, 1.0f));
	}

	if (!sm_pGreenOff)
	{
		sm_pGreenOff = new osg::Material();
		sm_pGreenOff->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.0f, 0.2f, 0.0f, 1.0f));
		sm_pGreenOff->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.0f, 0.2f, 0.0f, 1.0f));
		sm_pGreenOff->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.0f, 0.6f, 0.0f, 1.0f));
	}

	if (!sm_pAmberOn)
	{
		sm_pAmberOn = new osg::Material();
		sm_pAmberOn->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.2f, 0.2f, 0.0f, 1.0f));
		sm_pAmberOn->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.7f, 0.55f, 0.0f, 1.0f));
		sm_pAmberOn->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.6f, 0.6f, 0.0f, 1.0f));
	}

	if (!sm_pAmberOff)
	{
		sm_pAmberOff = new osg::Material();
		sm_pAmberOff->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.2f, 0.2f, 0.0f, 1.0f));
		sm_pAmberOff->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.2f, 0.2f, 0.0f, 1.0f));
		sm_pAmberOff->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(0.6f, 0.6f, 0.0f, 1.0f));
	}
	
	sm_pRedOn->ref();
	sm_pRedOff->ref();
	
	sm_pGreenOn->ref();
	sm_pGreenOff->ref();

	sm_pAmberOn->ref();
	sm_pAmberOff->ref();
}

void Assignment::ControlledTrafficLightFacade::SetState(LightState state) 
{
	
	switch (state)
	{
	case GO:
		m_pGreen->getOrCreateStateSet()->setAttributeAndModes(sm_pGreenOn);
		m_pRed->getOrCreateStateSet()->setAttributeAndModes(sm_pRedOff);
		m_pAmber->getOrCreateStateSet()->setAttributeAndModes(sm_pAmberOff);
		break;
	case READY:
		m_pGreen->getOrCreateStateSet()->setAttributeAndModes(sm_pGreenOn);
		m_pRed->getOrCreateStateSet()->setAttributeAndModes(sm_pRedOff);
		m_pAmber->getOrCreateStateSet()->setAttributeAndModes(sm_pAmberOn);
		break;
	case SLOW:
		m_pGreen->getOrCreateStateSet()->setAttributeAndModes(sm_pGreenOff);
		m_pRed->getOrCreateStateSet()->setAttributeAndModes(sm_pRedOff);
		m_pAmber->getOrCreateStateSet()->setAttributeAndModes(sm_pAmberOff);
		break;
	case STOP:
		m_pGreen->getOrCreateStateSet()->setAttributeAndModes(sm_pGreenOff);
		m_pRed->getOrCreateStateSet()->setAttributeAndModes(sm_pRedOn);
		m_pAmber->getOrCreateStateSet()->setAttributeAndModes(sm_pAmberOff);
		break;
	}
}

Assignment::ControlledTrafficLightFacade::~ControlledTrafficLightFacade() 
{
	if (m_pAmber) m_pAmber->unref();
	if (m_pGreen) m_pGreen->unref();
	if (m_pRed) m_pRed->unref();


	if (sm_pRedOn) sm_pRedOn->unref();
	if (sm_pRedOff) sm_pRedOff->unref();

	if (sm_pGreenOn) sm_pGreenOn->unref();
	if (sm_pGreenOff) sm_pGreenOff->unref();

	if (sm_pAmberOn) sm_pAmberOn->unref();
	if (sm_pAmberOff) sm_pAmberOff->unref();
}