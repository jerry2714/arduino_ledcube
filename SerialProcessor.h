#ifndef __SP_H__
#define __SP_H__
#include"arduino.h"
#define SERIAL_BUFFER_SIZE 63
#include"queue.h"
class SerialProcessor
{
  
  CQueue *queue;    //用來放所有接收到的資料，包括指令和燈號資料
  byte buf;
  
  public:
    SerialProcessor(){}
    SerialProcessor(CQueue* q)
    {
        this -> queue = q;
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
    // int c = queue->getQueueSpace();
    // if(c >= readbuf_used_len)
    // {   
        // readbuf_used_len -= queue->push(readbuf, readbuf_offset, readbuf_used_len);
    // }
    // else
    // {
        // readbuf_offset = queue -> push(readbuf, readbuf_offset, c);
        // memcpy(readbuf, readbuf+readbuf_offset, readbuf_used_len - c);
		// readbuf_used_len = readbuf_used_len - c;
    // }
    
}

int SerialProcessor::readData()
{
    return readData(SERIAL_BUFFER_SIZE);
}

int SerialProcessor::readData(int max)
{
    int count = Serial.available();

    if(count > max)
        count = max;
    for(int i = 0; i < count; i++)
	{
		Serial.readBytes(&buf, 1);
		queue -> push(buf);
	}
    
    return count;
}
#endif