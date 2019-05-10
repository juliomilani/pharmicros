static void init_lcd();
static void cursor_lcd(char,char);
static void print_lcd(char*);
static char key_detect();
static void escrita_dado_lcd(char);

#define usr_digits 6
#define senha_digits 6
int i;


void usr_in(int *usr_id){
	int usr_digits_in;
	init_lcd();
	cursor_lcd(0, 3);
	print_lcd("Pharmicros");
	cursor_lcd(1, 0);
	print_lcd("Usr: ");
	usr_digits_in = 0;
	while(usr_digits_in<usr_digits){
		char key = key_detect();
		if(key != 0){
			escrita_dado_lcd(key);
			usr_id[usr_digits_in] = key;
			usr_digits_in++;
		}
	}
}

void senha_in(int *usr_id, int *senha){
	int senha_digits_in;
	init_lcd();
	cursor_lcd(0, 0);
	print_lcd("Senha de ");
	for(i=0;i<usr_digits;i++){
		escrita_dado_lcd(usr_id[i]);
	}
	cursor_lcd(1, 3);
	senha_digits_in = 0;
	while(senha_digits_in<senha_digits){
		char key = key_detect();
		if(key != 0){
			escrita_dado_lcd('*');
			senha[senha_digits_in] = key;
			senha_digits_in++;
		}
	}
}


void main()
{
	int usr_id [usr_digits]; 
	int senha [senha_digits];
	usr_in(usr_id);
	senha_in(usr_id,senha);
	
	init_lcd();
	cursor_lcd(0, 0);
	print_lcd("usr:");
	for(i=0;i<usr_digits;i++){
		escrita_dado_lcd(usr_id[i]);
	}
	cursor_lcd(1, 0);
	print_lcd("senha:");
	for(i=0;i<senha_digits;i++){
		escrita_dado_lcd(senha[i]);
	}
	
	while(1){
		char key = key_detect();
		if(key == '#'){
			main();
		}
	}
	
}
