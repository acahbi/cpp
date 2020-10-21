/*
 * main.cc - РѕС‚СЃСЋРґР° РІСЃС‘ РЅР°С‡РёРЅР°РµС‚СЃСЏ.
 *
 *  Created on: 14 РѕРєС‚. 2020 Рі.
 *      Author: unyuu
 */


#include <iostream>
#include <stdexcept>
#include <locale>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "MyWindow.h"


// РЎР°РјР°СЏ РіР»Р°РІРЅР°СЏ С„СѓРЅРєС†РёСЏ!
int main(int, char**)
{
	// Р�РЅРёС†РёР°Р»РёР·Р°С†РёСЏ SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	try {

		//ExampleWindow w;
		MyWindow w(500, 500);

		w.main_loop();


	} catch (const std::exception &e) {
		// РћР±СЂР°Р±РѕС‚РєР° СЃС‚Р°РЅРґР°СЂС‚РЅС‹С… РёСЃРєР»СЋС‡РµРЅРёР№
		std::cerr <<
				"РџСЂРё РІС‹РїРѕР»РЅРµРЅРёРё РїСЂРѕРіСЂР°РјРјС‹ РІРѕР·РЅРёРєР»Р° "
				"РѕС€РёР±РєР°:" << std::endl <<
				e.what() << std::endl;
		return 1;
	} catch (...) {
		// РћР±СЂР°Р±РѕС‚РєР° РЅРµРёР·РІРµСЃС‚РЅС‹С… РёСЃРєР»СЋС‡РµРЅРёР№
		std::cerr <<
				"РџСЂРё РІС‹РїРѕР»РЅРµРЅРёРё РїСЂРѕРіСЂР°РјРјС‹ РІРѕР·РЅРёРєР»Р° "
				"РЅРµРёР·РІРµСЃС‚РЅР°СЏ РѕС€РёР±РєР°." << std::endl;
		return 1;
	}


	return 0;
}

