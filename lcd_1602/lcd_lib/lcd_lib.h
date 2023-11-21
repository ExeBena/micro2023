#ifndef LCD_LIB
#define LCD_LIB



// Modes for lcd_send_byte
#define LCD_CHARACTER  1
#define LCD_COMMAND    0

#define MAX_LINES      2
#define MAX_CHARS      16

/* Quick helper function for single byte transfers */
void i2c_write_byte(unsigned short val) ;

void lcd_toggle_enable(unsigned short val) ;

// The display is sent a byte as two separate nibble transfers
void lcd_send_byte(unsigned short val, int mode);

void lcd_clear(void) ;

// go to location on LCD
void lcd_set_cursor(int line, int position);

static void inline lcd_char(char val);

void lcd_string(const char *s);

void lcd_init();

#endif