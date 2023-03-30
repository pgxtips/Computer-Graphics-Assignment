#pragma once

#include <windows.h>
#include <osg/Drawable>

namespace Assignment
{
	class Geometry : public osg::Drawable
	{
	public:
		Geometry();
		virtual ~Geometry();
		virtual void drawImplementation(osg::RenderInfo&) const override;

	protected:
		osg::Vec3f m_vV0;
		osg::Vec3f m_vV1;
		osg::Vec3f m_vV2;
		osg::Vec3f m_vN;
	};
}