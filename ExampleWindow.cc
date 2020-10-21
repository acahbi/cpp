/*
 * ExampleWindow.cc
 *
 *  Created on: 19 РѕРєС‚. 2020 Рі.
 *      Author: unyuu
 */

#include <cmath>

static constexpr double Pi = acos(-1.);

#include "ExampleWindow.h"

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
}

//  Задание цвета плоскостей
static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };

void ExampleWindow::setup()
{
	//  Включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	//  Включаем освещение
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//  Установить цвет, который заполнен в буфер очистки цвета
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	//  Применяить матричные операции к стеку "проекции"
	glMatrixMode(GL_PROJECTION);
	//  Установка перспективы
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	//  Применитт матричные операции к стеку "вид модели"
	glMatrixMode(GL_MODELVIEW);
}

void ExampleWindow::render()
{
	//  Очистка экрана
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//  Замена текущей матрицы на единичную.
	glLoadIdentity();
	//  Положение камеры наблюдателя
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);
	//  Поворот объектов
	glRotated(_angle, 0., 0., 1.);
	//  Операторные скобки, начало рисования плоскости по 3 точкам
	glBegin(GL_QUADS);
	//  Определение нормали
	glNormal3d(  1.,  0.,  0.);
	//  Установка свойств материала
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	//  Положение вершин в пространстве
	glVertex3d(  1., -1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_magenta);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);
	//  Операторные скобки
	glEnd();
}

void ExampleWindow::handle_logic()
{
	//  Вращение по горизонтали
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;
	//  Вращение по вертикали
	_eye_level = sin(_angle / 180. * Pi);
}
