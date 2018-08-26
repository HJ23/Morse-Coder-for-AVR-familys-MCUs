//.___  ___.   ______   .______          _______. _______      ______   ______    _______   _______ .______
//|   \/   |  /  __  \  |   _  \        /       ||   ____|    /      | /  __  \  |       \ |   ____||   _  \
//|  \  /  | |  |  |  | |  |_)  |      |   (----`|  |__      |  ,----'|  |  |  | |  .--.  ||  |__   |  |_)  |
//|  |\/|  | |  |  |  | |      /        \   \    |   __|     |  |     |  |  |  | |  |  |  ||   __|  |      /
//|  |  |  | |  `--'  | |  |\  \----.----)   |   |  |____    |  `----.|  `--'  | |  '--'  ||  |____ |  |\  \----.
//|__|  |__|  \______/  | _| `._____|_______/    |_______|    \______| \______/  |_______/ |_______|| _| `._____|
//        _________
//       / ======= \
//      / __________\
//     | ___________ |
//     | | -       | |
//     | |         | |
//     | |_________| |_____Coded By_____________________
//     \=____________/     Kemaleddin Ahmedzade         )
//     / """"""""""" \     (github.com/HJ23)           /
//    / ::::::::::::: \      (26.08.2018)          =D-'
//   (_________________)
//*************************************************************************
//**********CONTACT:www.facebook.com/robert kemaleddin connor**************
//*************************************************************************
// pROJECT cODED aND cREATED bY kEMALEDDIN aHMEDZADE fROM sCRATCH 
// YOU CAN  USE or MODIFY these codes !
#define F_CPU 8000000L
#include<avr/io.h>
#include<util/delay.h>
#define rs 1
#define en 0 
#define s 400
#define start 5
#define out 6
#define dot 1000
#define dash 3000
char array[6][5]={{'A','B','C','D','E'},{'F','G','H','I','J'},{'K','L','M','N','O'},{'P','Q','R','S','T'},{'U','V','W','X','Y'},{'Z'}};
int array2[6][5]={{2100,1112,1212,112,1},{1211,122,1111,11,2221},{212,1121,22,12,222},{1221,2122,121,111,2},{211,2111,221,2112,2212},{1122}};
	int signalarray[31];
	char dataarray[31];
	void lcd_init();
	void command(unsigned char);
	void data(unsigned char);
	void warning();
	void coder();
	void send(int );
	void loading();
	int counter=0;
int main(){
	int i=0;
	DDRA=0xff;
	DDRB=0x00;
	DDRD=0xff;
	DDRC=(1<<0)|(1<<1)|(1<<out);
	lcd_init();
	while(1){
		
		if((PINC)&(1<<start)){
		coder();				
		}
		if(i>5){
		   i=0;}
		PORTA=1<<i;
		i++;
		if(PORTA==1){
		
		   if(PINB==1){
		   data(array[0][0]); 
		   send(array2[0][0]);
		   _delay_ms(s);
		   }
		   else if(PINB==2){
			  data(array[1][0]);
			  send(array2[1][0]);
			  _delay_ms(s);
		   }
		   else if(PINB==4){
			   data(array[2][0]);
			   send(array2[2][0]);
			   _delay_ms(s);
		   }
		   else if(PINB==8){
			   data(array[3][0]);
			   send(array2[3][0]);
			   _delay_ms(s);
		   }
		   else if(PINB==16){
			   data(array[4][0]);
			   send(array2[4][0]);
			   _delay_ms(s);
		   }
		   else if(PINB==32){
			   data(array[5][0]);
			   send(array2[5][0]);
			   _delay_ms(s);
		   }
		
		//---------PORTA==1	
		}
		else if(PORTA==2){
			 if(PINB==1){
			 data(array[0][1]);
			 send(array2[0][1]);
			 _delay_ms(s); }
			 else if(PINB==2){
				 data(array[1][1]);
				 send(array2[1][1]);
				 _delay_ms(s);
			 }
			 else if(PINB==4){
				 data(array[2][1]);
				 send(array2[2][1]);
				 _delay_ms(s);
			 }
			 else if(PINB==8){
				 data(array[3][1]);
				 send(array2[3][1]);
				 _delay_ms(s);
			 }
			 else if(PINB==16){
				 data(array[4][1]);
				 send(array2[4][1]);
				 _delay_ms(s);
			 }
			 else if(PINB==32){
				 data(array[5][1]);
				 send(array2[5][1]);
				 _delay_ms(s);
			 }
			 
			 //---------PORTA==2			
		}
		else if(PORTA==4){
			 if(PINB==1){
			 data(array[0][2]);
			 send(array2[0][2]); 
			 _delay_ms(s);}
			 else if(PINB==2){
				 data(array[1][2]);
				 send(array2[1][2]);
				 _delay_ms(s);
			 }
			 else if(PINB==4){
				 data(array[2][2]);
				 send(array2[2][2]);
				 _delay_ms(s);
			 }
			 else if(PINB==8){
				 data(array[3][2]);
				 send(array2[3][2]);
				 _delay_ms(s);
			 }
			 else if(PINB==16){
				 data(array[4][2]);
				 send(array2[4][2]);
				 _delay_ms(s);
			 }
			 else if(PINB==32){
				 data(array[5][2]);
				 send(array2[5][2]);
				 _delay_ms(s);
			 }
			 
			 //---------PORTA==4
			
		}
		else if(PORTA==8){
			 if(PINB==1){
			 data(array[0][3]); 
			 send(array2[0][3]);
			 _delay_ms(s);}
			 else if(PINB==2){
				 data(array[1][3]);
				 send(array2[1][3]);
				 _delay_ms(s);
			 }
			 else if(PINB==4){
				 data(array[2][3]);
				 send(array2[2][3]);
				 _delay_ms(s);
			 }
			 else if(PINB==8){
				 data(array[3][3]);
				 send(array2[3][3]);
				 _delay_ms(s);
			 }
			 else if(PINB==16){
				data(array[4][3]);
				send(array2[4][3]);
				_delay_ms(s);
			 }
			 else if(PINB==32){
				 data(array[5][3]);
				 send(array2[5][3]);
				 _delay_ms(s);
			 }
			 
			 //---------PORTA==8
			
		}
		else if(PORTA==16){
			 if(PINB==1){
			 data(array[0][4]);
			 send(array2[0][4]);
			 _delay_ms(s); }
			 else if(PINB==2){
				data(array[1][4]);
				send(array2[1][4]);
				_delay_ms(s);
			 }
			 else if(PINB==4){
				data(array[2][4]);
				send(array2[2][4]);
				_delay_ms(s);
			 }
			 else if(PINB==8){
				 data(array[3][4]);
				 send(array2[3][4]);
				 _delay_ms(s);
			 }
			 else if(PINB==16){
				 data(array[4][4]);
				 send(array2[4][4]);
				 _delay_ms(s);
			 }
			 else if(PINB==32){
				 data(array[5][4]);
				 send(array2[5][4]);
				 _delay_ms(s);
			 }
			 
			 //---------PORTA==16
			
		}
		else if(PORTA==32){
			if(PINB==32){
			data(array[5][0]);
			send(array2[5][0]);
			_delay_ms(s);
			}
	//---------PORTA==32
	}
	}

}
void lcd_init(){
	PORTC&=~(1<<en);
	_delay_us(1000);
	command(0x38);
	_delay_us(10);
	command(0x0E);
	_delay_us(10);
	command(0x01);
	_delay_us(2000);
	command(0x06);	
}
void command(unsigned char com){
	PORTD=com;
	PORTC|=(1<<en);
	PORTC&=~(1<<rs);
	_delay_us(100);
	PORTC&=~(1<<en);
	_delay_us(100);
	}
void data(unsigned char da){
	if(counter==16){
	command(0xC0);
	}
	else if(counter==31){
				for(int yuu=0;yuu<=2;yuu++){
					_delay_ms(500);
					warning();
					_delay_ms(500);	
					command(0x01);				
				}
				lcd_init();
				for(int y=0;y<=15;y++){
					PORTD=dataarray[y];
					PORTC|=(1<<rs);
					PORTC|=(1<<en);
					_delay_us(100);
					PORTC&=~(1<<en);
					_delay_us(100);
				}
				command(0xc0);
				for(int y=16;y<=31;y++){
					PORTD=dataarray[y];
					PORTC|=(1<<rs);
					PORTC|=(1<<en);
					_delay_us(100);
					PORTC&=~(1<<en);
					_delay_us(100);
				}
				return;				
			}
	dataarray[counter]=da;
	counter++;
	PORTD=da;
	PORTC|=(1<<rs);
	PORTC|=(1<<en);
	_delay_us(100);
	PORTC&=~(1<<en);
	_delay_us(100);	

}
void warning(){
	char warn[]={'Y','O','U',' ','E','X','C','E','E','D',' ','3','2','C','h','a','r','a','c','t','e','r'};
	lcd_init();
	for(int y=0;y<=12;y++){
		PORTD=warn[y];
		PORTC|=(1<<rs);
		PORTC|=(1<<en);
		_delay_us(100);
		PORTC&=~(1<<en);
		_delay_us(100);
	}
	command(0xC0);
	for(int y=13;y<=21;y++){
		PORTD=warn[y];
		PORTC|=(1<<rs);
		PORTC|=(1<<en);
		_delay_us(100);
		PORTC&=~(1<<en);
		_delay_us(100);
	}

}
void coder(){
	if(counter!=0){
		int number=0;
		int xc=0;
		for(int x=0;x<counter;x++){
			number=signalarray[x];
			for(int y=0;y<=3;y++){
				xc=number%10;
				if(xc==1){
					_delay_ms(200);
					PORTC|=(1<<out);
					_delay_ms(dot);
					PORTC&=~(1<<out);
				}
				else if(xc==2){
					_delay_ms(200);
					PORTC|=(1<<out);
					_delay_ms(dash);
					PORTC&=~(1<<out);
				}
				number=(int)(number/10);
				
			}
			
		}
			
	}
	else{
		char warn2[]={'E','r','r','o','r',':','L','A','C','K',' ','o','f','C','h','a','r','a','c','t','e','r'};
		for(int yu=0;yu<=2;yu++){
		lcd_init();
		for(int y=0;y<=12;y++){
			PORTD=warn2[y];
			PORTC|=(1<<rs);
			PORTC|=(1<<en);
			_delay_us(100);
			PORTC&=~(1<<en);
			_delay_us(100);
		}
		command(0xC0);
		for(int y=13;y<=21;y++){
			PORTD=warn2[y];
			PORTC|=(1<<rs);
			PORTC|=(1<<en);
			_delay_us(100);
			PORTC&=~(1<<en);
			_delay_us(100);
		}
		_delay_ms(300);
		command(0x01);
		_delay_ms(400);
		}
		lcd_init();
		return;		
	}
	}
void send(int sd){
	if(counter<=31){
	signalarray[counter-1]=sd;
	}
}
