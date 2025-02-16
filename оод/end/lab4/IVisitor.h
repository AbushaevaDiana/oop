#pragma once
#include "CShapeDecorator.h"

class IVisitor
{
public:
	virtual void VisitShape(CShapeDecorator* shape) = 0;
};