#pragma once
#include <string>
#include <cliext/vector>


using namespace System;
using namespace System::Drawing;

public ref class cls_point
{
public:
	String name;
	double x1;
	double y1;
};

public ref class cls_line
{
public:
	String name;
	cls_point start;
	cls_point end;
};

public ref class cls_shape abstract
{
public:
	//cls_shape();
	//virtual ~cls_shape() = 0;

	virtual double area() = 0; //compute area of the shape
	virtual void draw(Graphics^ g) = 0; //draw shape on a graphics context 

	//virtual double height() = 0;
	//virtual double width() = 0;

	//cliext::vector <cls_line> lines;

};

public ref class cls_polygon : public cls_shape {

public:
	cls_polygon();
	~cls_polygon();

	cliext::vector <cls_line> lines;
	double height();
	double width();
	double area() override;

private:
	double _height = 0.0;
	double _width = 0.0;
	
};

cls_polygon::cls_polygon(){

}

double cls_polygon::area()
{
	return _height * _width;
}

double cls_polygon::height()
{
	return _height;
}
double cls_polygon::width()
{
	return _width;
}