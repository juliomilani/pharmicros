static void init_lcd();
static void cursor_lcd(char,char);
static void print_lcd(char*);
static char key_detect();
static void escrita_dado_lcd(char);

void main()
{
	init_lcd();
	cursor_lcd(0, 3);
	print_lcd("Pharmicros");
	cursor_lcd(1, 2);
	print_lcd("Teclado: ");
	while(1){
		char key = key_detect();
		if(key != 0){
		escrita_dado_lcd(key);
		}
	}
	while(1);
}
