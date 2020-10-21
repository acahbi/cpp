#include <cmath>

static constexpr double Pi = acos(-1.);

#include <iostream>
#include "MyWindow.h"

MyWindow::MyWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
}

static const float s_material_wall[4]    { 0.7f, 0.6f, 0.3f, 0.f};
static const float s_material_roof[4]    { 0.f, 0.6f, 0.f, 0.f};
static const float s_material_ground[4]  { 0.f, 0.f, 0.f, 0.f};

void MyWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);
	glRotated(_angle, 0., 0., 1.);

	glBegin(GL_QUADS);
		glNormal3d(  1.,  0.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_wall);
		glVertex3d(  _lengthHome, -_widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  _widthHome, -_heigthHome);
		glVertex3d(  _lengthHome, -_widthHome, -_heigthHome);

		glNormal3d( -1.,  0.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_wall);
		glVertex3d( -_lengthHome,  _widthHome,  _heigthHome);
		glVertex3d( -_lengthHome, -_widthHome,  _heigthHome);
		glVertex3d( -_lengthHome, -_widthHome, -_heigthHome);
		glVertex3d( -_lengthHome,  _widthHome, -_heigthHome);

		glNormal3d(  0.,  1.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_wall);
		glVertex3d( -_lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  _widthHome, -_heigthHome);
		glVertex3d( -_lengthHome,  _widthHome, -_heigthHome);

		glNormal3d(  0., -1.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_wall);
		glVertex3d(  _lengthHome, -_widthHome,  _heigthHome);
		glVertex3d( -_lengthHome, -_widthHome,  _heigthHome);
		glVertex3d( -_lengthHome, -_widthHome, -_heigthHome);
		glVertex3d(  _lengthHome, -_widthHome, -_heigthHome);

		//  Потолок
		glNormal3d(  0.,  0.,  1.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_wall);
		glVertex3d( -_lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome, -_widthHome,  _heigthHome);
		glVertex3d( -_lengthHome, -_widthHome,  _heigthHome);

		//  Пол
		glNormal3d(  0.,  0., -1.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_ground);
		glVertex3d(  _lengthHome,  _widthHome, -_heigthHome);
		glVertex3d( -_lengthHome,  _widthHome, -_heigthHome);
		glVertex3d( -_lengthHome, -_widthHome, -_heigthHome);
		glVertex3d(  _lengthHome, -_widthHome, -_heigthHome);

		//  Крыша
		glNormal3d(  0.,  1., 0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_roof);
		glVertex3d( -_lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  0		 ,  _val_size + _heigthHome);
		glVertex3d( -_lengthHome,  0		 ,  _val_size + _heigthHome);

		glNormal3d(  0.,  -1., 0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_ground);
		glVertex3d( -_lengthHome, 0			 ,  _val_size + _heigthHome);
		glVertex3d(  _lengthHome, 0			 ,  _val_size + _heigthHome);
		glVertex3d(  _lengthHome, -_widthHome,  _heigthHome);
		glVertex3d( -_lengthHome, -_widthHome,  _heigthHome);

	glEnd();

	glBegin(GL_TRIANGLES);
		glNormal3d(  1.,  0.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_roof);
		glVertex3d(  _lengthHome,  -_widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,   _widthHome,  _heigthHome);
		glVertex3d(  _lengthHome,  0		  ,  _val_size + _heigthHome);

		glNormal3d(  -1.,  0.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_roof);
		glVertex3d(  -_lengthHome,   _widthHome,  _heigthHome);
		glVertex3d(  -_lengthHome,  -_widthHome,  _heigthHome);
		glVertex3d(  -_lengthHome,  0		   ,  _val_size + _heigthHome);

	glEnd();
}

void MyWindow::handle_logic()
{
	if (!_flag_turn)
		_angle += 0.01;

	if (_flag_turn)
		_angle -= 0.01;

	if (_angle >= 360.)
		_angle -= 360.;

	if (_angle < 0.)
		_angle += 360.;

	_eye_level = sin(_angle / 180. * Pi);
}

void MyWindow::handle_keys(const Uint8 * keys){

	double val = 0.001;

	if (keys[SDL_SCANCODE_1])
		_flag_turn = false;

	if (keys[SDL_SCANCODE_0])
		_flag_turn = true;

	if (keys[SDL_SCANCODE_Q])
		_heigthHome += val;

	if (keys[SDL_SCANCODE_W])
		_widthHome += val;

	if (keys[SDL_SCANCODE_E])
		_lengthHome += val;

	if (keys[SDL_SCANCODE_A])
		_heigthHome -= val;

	if (keys[SDL_SCANCODE_S])
		_widthHome -= val;

	if (keys[SDL_SCANCODE_D])
		_lengthHome -= val;

	if (_lengthHome <= 0.)
		_lengthHome = 0.;

	if (_widthHome <= 0.)
		_widthHome = 0.;

	if (_heigthHome <= 0.)
		_heigthHome = 0.;

}
