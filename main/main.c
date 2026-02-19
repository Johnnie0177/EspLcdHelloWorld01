
#include <string.h>
#include "esp_log.h"
#include "lcd1602_i2c.h"

/*
void i2c_init( void );
void scan_i2c( void );
void lcd_init( void );
void lcd_ser_curser( u_int8_t y, u_int8_t x );
void lcd_send_buf( const char *ch, size_t size );
*/

static const char *TAG = "Lcd";

void InitLcd( void )
	{
	ESP_LOGI( TAG, "InitLcd() calling lcd_init()" );
	lcd_init( );
	ESP_LOGI( TAG, "InitLcd() done" );
	}

void InitI2cBus( void )
	{
	ESP_LOGI( TAG, "InitI2cBus() calling i2c_init()" );
	i2c_init( );
	ESP_LOGI( TAG, "InitI2cBus() calling scan_i2c()" );
	scan_i2c( );
	ESP_LOGI( TAG, "InitI2cBus() done" );
	}

void app_main( void )
	{
	ESP_LOGI( TAG, "main() calling InitI2cBus()" );
	InitI2cBus( );
	ESP_LOGI( TAG, "main() calling InitLcd()" );
	InitLcd( );

	ESP_LOGI( TAG, "main() sending hello message" );
	char *msgStr = "Hello World";
	int msgLen = strlen( msgStr );
	lcd_send_buf( msgStr, msgLen );
	lcd_ser_curser( 1, 0 );
	ESP_LOGI( TAG, "main() done" );
	}

