#include "Geometry.h"

Assignment::Geometry::Geometry()
{
	m_vV0 = osg::Vec3f(-50.0f, 0.0f, 0.0f);
	m_vV1 = osg::Vec3f(50.0f, 0.0f, 0.0f);
	m_vV2 = osg::Vec3f(0.0f, 0.0f, 50.0f);

	osg::Vec3f a, b;

	a = m_vV0 - m_vV1;
	b = m_vV2 - m_vV1;

	m_vN = b ^ a;
	m_vN.normalize();
}

Assignment::Geometry::~Geometry()
{
}

void Assignment::Geometry::drawImplementation(osg::RenderInfo&) const
{
	glBegin(GL_TRIANGLES);
	glNormal3fv(m_vN.ptr());
	glVertex3fv(m_vV0.ptr());
	glVertex3fv(m_vV1.ptr());
	glVertex3fv(m_vV2.ptr());
	glEnd();
}