#include "CLCD.h"
#include <ev3api.h>
#include <stdarg.h>

namespace RyujiEv3
{
	bool CLCD::setFont(LCD_Font font)
	{
		auto result = ev3_lcd_set_font(static_cast<lcdfont_t>(font));

		if (result != E_OK)
		{
			return false;
		}

		m_font = font;

		return true;
	}

	CLCD::CLCD()
	{
		setFont(LCD_Font::MEDIUM);
	}

	CLCD::~CLCD()
	{
		ev3_image_free(&m_image);
	}

	LCD_Font CLCD::getFont()const
	{
		return m_font;
	}

	bool CLCD::clear()
	{
		return fillRect(0, 0, LCD_WIDTH, LCD_HEIGHT, LCD_Color::WHITE);
	}

	bool CLCD::fillRect(int32 x, int32 y, int32 width, int32 height, LCD_Color color)
	{
		if(width>LCD_WIDTH || height>LCD_HEIGHT)
		{
			return false;
		}
		
		ev3_lcd_fill_rect(x, y, width, height, static_cast<lcdcolor_t>(color));

		return true;
	}

	bool CLCD::drawString(int32 x,int32 y,const char* format,...)
	{
		va_list args;
		char buf[256];

		va_start(args, format);
		vsprintf(buf,format, args);
		va_end(args);
		
		if(E_OK != ev3_lcd_draw_string(buf,x,y))
		{
			return false;
		}

		return true;
	}

	bool CLCD::drawBitmap(int32 x,int32 y,const char* filename)
	{
		memfile_t file;

		ev3_image_free(&m_image);

		if(E_OK != ev3_memfile_load(filename,&file))
		{
			return false;
		}

		if(E_OK != ev3_image_load(&file,&m_image))
		{
			return false;
		}

		if(E_OK != ev3_lcd_draw_image(&m_image,x,y))
		{
			return false;
		}

		if(E_OK != ev3_memfile_free(&file))
		{
			return false;
		}

		return true;
	}
}
