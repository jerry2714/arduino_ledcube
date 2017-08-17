#include"cube.h"
//const int size = 6;
//int arr [size][size][size];

void setup() {
  
  Serial.begin(115200);
  Serial.setTimeout(5);
  ledstrip.begin();
  ledstrip.setBrightness(change_bright);
  ledstrip.show();
  standBy();
  
  
  //DataChangeSim(arr,size);
}


void loop() {
    
    unsigned long start, end;
    
    byte led[4] = {0};
    int i = 0, j = 0;
    int count = 0;
    
    
    
    sp.readData(queue.getQueueSpace());
    while(true)
    {
        commandTranslate();
    }

}
inline byte readByte()
{
    //unsigned long time = millis();
	while(queue.isEmpty())
        loadData(queue.getQueueSpace());
    return queue.pop();
}
void commandTranslate()
{
    static const int require_data_size = 3;    //command
    static int command[3] = {0};
    static bool dataFlag = false;
    static bool output = false;
    
    for(int i = 0; i < require_data_size; i++)
    {
        command[i] = readByte();
        //Serial.println(command[i]);
        
    }
    
    dataFlag = command[0] % 2;
    
    if(dataFlag)
    {
        output = (command[0] >> 1) % 2;
        command[0] = command[0] >> 2;
        switch(command[0])
        {
            case SET:
                set(output, ((command[1]<<8) | command[2]));
                break;
            case CLEAR_AND_SET:
                clearAndSet(output, ((command[1]<<8) | command[2]));
                break;
            case SET_BACKGROUND:
                setBackground(output, ((command[1]<<8) | command[2]));
                break;
            case SAME_COLOR:
                sameColor(output, ((command[1]<<8) | command[2]));
                break;
            case SAME_COLOR_STRIP:
                sameColorStrip(output, command[1], command[2]);
                break;
            case STRIP:
                strip(output, command[1], command[2]);
                break;
            case SET_LINE:
                set_line(output, command[1], command[2]);
                break;
        }
    }
    else
    {
        command[0] = command[0] >> 1;
        switch(command[0])
        {
            case SEND_OUT:
                send_out();
                break;
        }
    }
}

inline void loadData(int max)
{
    sp.readData(max);
    sp.loadData();
}


inline void set(bool output, int num)
{
    int data[4];
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < 4; j++)
            data[j] = readByte();
        ledstrip.setPixelColor(data[0], data[1], data[2], data[3]);
    }
    if(output)
        ledstrip.show();
}
inline void clearAndSet(bool output, int num)
{
    for(int i = 0; i < PIX_NUM; i++)
        ledstrip.setPixelColor(i, 0, 0, 0);
    set(output, num);
}
inline void setBackground(bool output, int num)
{
    int color[3];
	Pattern *ptr;
	const Pattern_full pattern_full;
	const Pattern_core pattern_core;
	const Pattern_tree pattern_tree;
    for(int i = 0; i < 3; i++)
        color[i] = readByte();
    if(num == 0)
		ptr = &pattern_full;
	else if(num == 1)
		ptr = &pattern_core;
	else if(num == 2)
		ptr = &pattern_tree;
	ptr -> drawPattern(ledstrip, color);
    if(output)
        ledstrip.show();
}
inline void sameColor(bool output, int num)
{
    int color[3];
    int pos;
    for(int i = 0; i < 3; i++)
        color[i] = readByte();
    for(int i = 0; i < num; i++)
    {
        pos = readByte();
        ledstrip.setPixelColor(pos, color[0], color[1], color[2]);
    }
    if(output)
        ledstrip.show();
}
inline void sameColorStrip(bool output, int offset, int length)
{
    int color[3];
    for(int i = 0; i < 3; i++)
        color[i] = readByte();
    for(int i = offset; i < offset+length; i++)
    {
        ledstrip.setPixelColor(i, color[0], color[1], color[2]);
    }
    if(output)
        ledstrip.show();
}
inline void strip(bool output, int offset, int length)
{
    int color[3];
    for(int i = offset; i < offset+length; i++)
    {
        for(int j = 0; j < 3; j++)
            color[j] = readByte();
        ledstrip.setPixelColor(i, color[0], color[1], color[2]);
    }
    if(output)
        ledstrip.show();
}
void DataChangeSim(int (*arr)[6][6],int size)
{
  for(int k = 0; k < size; k++)
    {
      for(int i = 0; i < size; i++)
      {
        for(int j = 0; j < size; j++)
        {
          if(i % 2 == 1)
            arr[k][i][j] = k*size*size + i*size + (size-j-1);
          else 
            arr[k][i][j] = k*size*size + i*size + j;
        }
      }
    }
    
    /*
    for(int k = 0; k < size; k++)
    { for(int i = 0; i < size; i++)
      {
        for(int j = 0; j < size; j++)
          //cout<<arr[k][i][j]<<" ";  System.out.print(arr[k][i][j] + " ");
        //cout<<"\n"; System.out.println();
      }
      //cout<<"\n"; System.out.println();
      
    }*/
}

int GCD(int a, int b) {
  if(b) while((a %= b) && (b %= a));
  return a + b;
}
inline void set_line(bool output, int input001, int input002)
{
  //const int size = 6;
  //int arr [size][size][size];
  //DataChangeSim(arr,size);
  //int input001,input002;
  int inputled[2][3];
  /*cout<<"input001=";
  cin>>input001;
  cout<<"input002=";
  cin>>input002;*/
  
  ///////////////////////////////
  int input01[3];
  int input02[3];
  int vector[3];
  int gcd01,i,gcd,x,y,z;
  int led[10][3];
  
  
  invCoordinateConvert(input001, input01[0], input01[1], input01[2]);  
  invCoordinateConvert(input002, input02[0], input02[1], input02[2]);  
  //set_line_001
  for(i=0;i<3;i++)
  {
    vector[i]=input02[i]-input01[i];
  }
  gcd=GCD(vector[0],vector[1]);
  gcd=abs(gcd);
  gcd=GCD(gcd,vector[2]);
  gcd=abs(gcd);
  
  //if gcd=0還沒有處理 
  if(gcd==0)
  {
      int color[3];
     for(int j = 0; j < 3; j++)
         color[j] = readByte();
         
     ledstrip.setPixelColor(input001, color[0], color[1], color[2]);

       //Serial.print("!000000000000000!");
       /*Serial.print(input001);
       Serial.print(" ");
       Serial.print(color[0]);
       Serial.print(" ");
       Serial.print(color[1]);
       Serial.print(" ");
       Serial.print(color[2]);
       Serial.println();
    Serial.println("///");*/
    if(output)
      ledstrip.show(); 

     
  }
  else
  {
      for(i=0;i<=gcd;i++)
  {
    x=input01[0]+(vector[0]*i)/gcd;
    y=input01[1]+(vector[1]*i)/gcd;
    z=input01[2]+(vector[2]*i)/gcd;
    led[i][0]=x;
    led[i][1]=y;
    led[i][2]=z;
  }
  
  for(i=0;i<=gcd;i++)
  {
    //cout<<i<<"=("<<led[i][0]<<","<<led[i][1]<<","<<led[i][2]<<")\n";
  }
  
  /////////////////////////////////////////////////////
        
  int t2[10];
  
  for(int t=0;t<=gcd;t++)
  {
    t2[t] = coordinateConvert(led[t][0], led[t][1], led[t][2]);
  }
  

  /*
  for(i=0;i<=gcd;i++)
  {
    cout<<i<<"===="<<t2[i]<<"\n";
  }*/

  int color[3];
  for(int j = 0; j < 3; j++)
            color[j] = readByte();
    for(int t=0;t<=gcd;t++)
    {
        ledstrip.setPixelColor(t2[t], color[0], color[1], color[2]);
       /*Serial.print(t2[t]);
       Serial.print(" ");
       Serial.print(color[0]);
       Serial.print(" ");
       Serial.print(color[1]);
       Serial.print(" ");
       Serial.print(color[2]);
       Serial.println();*/
    }
    if(output)
      ledstrip.show(); 

      //Serial.println("///");
  }//else end
  
  
  
}
inline void send_out()
{
      ledstrip.show(); 
}
