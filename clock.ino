  ////////// DIGITAL CLOCK BY CHANDAN K.S \\\\\\\\\\\

   //#define off 0
   //#define on 1  
   // #define don 0
   //#define doff 1
//
 #define off 1
 #define on 0
 #define don 1
 #define doff 0

int a=12,b=13,c=7,d=8,e=9,f=11,g=10,dp=6;        //pins to activate segment
int dis1=5,dis2=4,dis3=3,dis4=2;               //enable pins for display(anode type display used

int button_1=A0;  //for updating hour
int button_2=A1;  //for updating second
int button_3=A2;  //for updating minute
//refresh rate of display and button
int button_R=200;
int display_R=3;

int p_disp=0;
int p_btn=0;

// for clock//
int time_format=24;  //12 or 24
int hour=0,minute=0,second=0;
int hour_T=0,hour_O=0,minute_T=0,minute_O=0;
int d_hour=0,d_minute=0,d_second=0;
unsigned long button_time=0,display_time=0;
//

//for time control//
unsigned int p_time=0,c_time,interval=1000;//1000 in milli second
//
int blink_t=500;  //adj blink speed min milli second
int blink_counter=0;


void setup()
{
  Serial.begin(9600);
    pinMode(a,OUTPUT);   
    pinMode(b,OUTPUT);    
    pinMode(c,OUTPUT);  
    pinMode(d,OUTPUT);
    pinMode(e,OUTPUT);
    pinMode(f,OUTPUT);
    pinMode(g,OUTPUT);  
    pinMode(dp,OUTPUT);   
    
    pinMode(dis1,OUTPUT);
    pinMode(dis2,OUTPUT);
    pinMode(dis3,OUTPUT);
    pinMode(dis4,OUTPUT);
    
    pinMode(button_1,INPUT_PULLUP);
    pinMode(button_2,INPUT_PULLUP);
    pinMode(button_3,INPUT_PULLUP);
   //check_no();
   digitalWrite(dp,off); 
   all_dispoff();
   all_segment_off();
   c_time=millis();
   }


void loop()
{c_time=millis();

if(c_time-p_time>=interval)
{ p_time=c_time;
  second++;
  
}
blink_dp();
////

if(second==60){minute++;second=0;d_minute=minute;}
if(minute==60){hour++;minute=0;if(time_format==12){d_hour++;}}
if(hour==24 && time_format==24){d_hour=0;hour=0;}
if(hour==13 && time_format==12){d_hour=1;}
if(hour==24 && time_format==12){d_hour=0;hour=0;}

if(c_time-button_time>=button_R)
{ button_time=c_time;  
  if(digitalRead(button_1)==0){hour++;d_hour++;}
  if(digitalRead(button_2)==0){second=0;p_time=c_time;}
  if(digitalRead(button_3)==0){minute++;d_minute=minute;} 
}    

convert_time(d_hour,d_minute);

c_time=millis();
if(c_time-display_time>=display_R&&c_time-display_time<display_R*2)
{display_hourT();}

if(c_time-display_time>=display_R*2&&c_time-display_time<display_R*3)
{display_hourO();}

if(c_time-display_time>=display_R*3&&c_time-display_time<display_R*4)
{display_minuteT();}

if(c_time-display_time>=display_R*4&&c_time-display_time<display_R*5)
{display_minuteO();}

if(c_time-display_time>=display_R*5)
{c_time=millis();
display_time=c_time;
all_segment_off();
//all_dispoff();
}


//Serial.print("hour==>");Serial.println(d_hour);
//Serial.print("second==>");Serial.println(second);
//Serial.print("minute O==>");Serial.println(minute);

////////////////////
////////////////////
//main loop end //// 
////////////////////  
////////////////////
  
  }

void all_dispoff()
{digitalWrite(dis1,doff);
   digitalWrite(dis2,doff);
   digitalWrite(dis3,doff);
   digitalWrite(dis4,doff);}


  
void dispc(int d)
{Serial.println(display_time );
Serial.println(c_time );
Serial.println(d);
  } 

/////////////////////////////////////////////////////

void blink_dp()
{
if(blink_counter==0)
{blink_counter=1;}
else
{blink_counter=0;}
  
 if(c_time-p_time<=blink_t && blink_counter==1)
  { 
     digitalWrite(dp,on);
  }
 else
  {
    digitalWrite(dp,off);}
  }


/////////////////////////////////////////////////////
void check_no()
{
    
    digitalWrite(dis1,don);
    digitalWrite(dis2,don);
    digitalWrite(dis3,don);
    digitalWrite(dis4,don);

   all_segment_off();
   N0();delay(1000);
   N1();delay(1000);  
   N2();delay(1000);   
   N3();delay(1000);    
   N4();delay(1000);    
   N5();delay(1000);    
   N6();delay(1000);    
   N7();delay(1000);   
   N8();delay(1000);   
   N9();delay(1000);
    
  }

////////////////////////////////////////////////////
void all_segment_off()
{   digitalWrite(a,off);
    digitalWrite(b,off);
    digitalWrite(c,off);
    digitalWrite(d,off);
    digitalWrite(e,off);
    digitalWrite(f,off);
    digitalWrite(g,off);
    
}
/////////////////////////////////////////////////////
//convert actual time for 7 segment to display///////
/////////////////////////////////////////////////////

void convert_time(int h,int m)
{
  hour_T=h/10;
  hour_O=h%10;
  minute_T=m/10;
  minute_O=m%10;
  }


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void display_hourT()
  { digitalWrite(dis1,don);
    digitalWrite(dis2,doff);
    digitalWrite(dis3,doff);
    digitalWrite(dis4,doff);
    switch(hour_T)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    
    }
//////////////////////////////////////////////////////////////////
void display_hourO()
  { digitalWrite(dis1,doff);
    digitalWrite(dis2,don);
    digitalWrite(dis3,doff);
    digitalWrite(dis4,doff);
    switch(hour_O)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    
    }
//////////////////////////////////////////////////////////////////
void display_minuteT()
  { digitalWrite(dis1,doff);
    digitalWrite(dis2,doff);
    digitalWrite(dis3,don);
    digitalWrite(dis4,doff);
    switch(minute_T)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    
    }
//////////////////////////////////////////////////////////////////
void display_minuteO()
  { digitalWrite(dis1,doff);
    digitalWrite(dis2,doff);
    digitalWrite(dis3,doff);
    digitalWrite(dis4,don);
    switch(minute_O)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    
    }
//////////////////////////////////////////////////////////////////
void all_segment_on()
{
    
    
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,on);
    digitalWrite(f,on);
    digitalWrite(g,on);
}
///////////////////////////////////////////////////
void N0()
{
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,on);
    digitalWrite(f,on);
    digitalWrite(g,off);

}


///////////////////////////////////////////////////
void N1()
{
    digitalWrite(a,off);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,off);
    digitalWrite(e,off);
    digitalWrite(f,off);
    digitalWrite(g,off);

}


///////////////////////////////////////////////////
void N2()
{
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,off);
    digitalWrite(d,on);
    digitalWrite(e,on);
    digitalWrite(f,off);
    digitalWrite(g,on);

}


///////////////////////////////////////////////////
void N3()
{
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,off);
    digitalWrite(f,off);
    digitalWrite(g,on);

}

///////////////////////////////////////////////////
void N4()
{
    digitalWrite(a,off);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,off);
    digitalWrite(e,off);
    digitalWrite(f,on);
    digitalWrite(g,on);

}

///////////////////////////////////////////////////
void N5()
{
    digitalWrite(a,on);
    digitalWrite(b,off);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,off);
    digitalWrite(f,on);
    digitalWrite(g,on);

}

///////////////////////////////////////////////////
void N6()
{
    digitalWrite(a,on);
    digitalWrite(b,off);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,on);
    digitalWrite(f,on);
    digitalWrite(g,on);

}

///////////////////////////////////////////////////
void N7()
{
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,off);
    digitalWrite(e,off);
    digitalWrite(f,off);
    digitalWrite(g,off);

}

///////////////////////////////////////////////////
void N8()
{
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,on);
    digitalWrite(f,on);
    digitalWrite(g,on);

}

///////////////////////////////////////////////////
void N9()
{
    digitalWrite(a,on);
    digitalWrite(b,on);
    digitalWrite(c,on);
    digitalWrite(d,on);
    digitalWrite(e,off);
    digitalWrite(f,on);
    digitalWrite(g,on);

}




/////////////////////             THANKYOU            ////////////////////////
