#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

// Объявление класса MyWindow как потомка Window
class MyWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH  = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;

protected:
	double _angle; // Угол поворота модели
	double _eye_level; // Высота уровня глаз
	double _val_size   = 1;
	double _heigthHome = _val_size;
	double _widthHome  = _val_size;
	double _lengthHome = _val_size;
	bool   _flag_turn  = false;

public:

	// Конструктор класса MyWindow
	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

	// Деструктор класса MyWindow
	virtual ~MyWindow() = default;

	// Метод начальной настройки окна
	virtual void setup() override;

	// Метод отрисовки окна
	virtual void render() override;

	virtual void handle_keys(const Uint8 * keys) override;

	// Метод обработки логики
	virtual void handle_logic() override;
};




#endif /* MYWINDOW_H_ */
