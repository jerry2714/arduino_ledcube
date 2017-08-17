#ifndef __SP_H__
#define __SP_H__
#include"arduino.h"
#define SERIAL_BUFFER_SIZE 63
#include"queue.h"
class SerialProcessor
{
  
  CQueue *queue;    //用來放所有接收到的資料，包括指令和燈號資料

  byte readbuf[SERIAL_BUFFER_SIZE];   //用來接收資料
  int requested_size = 0;  //上次要求對方傳送多少資料
  int data_online_size = 0; //目前應該正在傳輸的資料數量
  bool requested;
  int special_request_size = 0; //特殊狀況下要求對方傳多少資料(可能超過arduino serial buffer size)
  int readbuf_used_len = 0;     //readbuf現在有多少格有資料
  int readbuf_offset = 0;
  public:
    SerialProcessor(){}
    SerialProcessor(CQueue* q)
    {
        this -> queue = q;
        requested = false;
    }
    int test(){}
    /**
    *把資料從readbuf搬到databuf
    */
    inline void loadData();
    
    /**
    *從Serial port 讀取資料
    *回傳共讀到多少資料
    */
    inline int readData();
    
    /**
    *從Serial port 讀取資料
    * max: 最多只讀 max 個 bytes
    *回傳共讀到多少資料
    */
    inline int readData(int max);
    
};

void SerialProcessor::loadData()
{
    int c = queue->getQueueSpace();
    if(c >= readbuf_used_len)
    {   
        readbuf_used_len -= queue->push(readbuf, readbuf_offset, readbuf_used_len);
    }
    else
    {
        readbuf_offset = queue -> push(readbuf, readbuf_offset, c);
        memcpy(readbuf, readbuf+readbuf_offset, readbuf_used_len - c);
		readbuf_used_len = readbuf_used_len - c;
    }
    
}

int SerialProcessor::readData()
{
    return readData(SERIAL_BUFFER_SIZE);
}

int SerialProcessor::readData(int max)
{
    int c = 0;
    readbuf_used_len = Serial.available();

    if(readbuf_used_len > max)
        readbuf_used_len = max;
    // data_online_size -= readbuf_used_len;
    // requested_size = SERIAL_BUFFER_SIZE - (data_online_size);
    // if(requested_size > (SERIAL_BUFFER_SIZE / 2))
    // {
        // Serial.write(requested_size);  
        // data_online_size += requested_size;
        // requested = true;
    // }
    if(readbuf_used_len > 0)
        c = Serial.readBytes(readbuf, readbuf_used_len);    //只從Serial buffer讀資料，不等待所有資料到齊
    
    return c;
}
#endif