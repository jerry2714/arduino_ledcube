#ifndef __QUEUE_H__
#define __QUEUE_H__
#define QUEUE_SIZE 512
#define byte unsigned char
class CQueue
{
    byte buf[QUEUE_SIZE];
    int size = QUEUE_SIZE;
    int front, rear;
    
    public:
        CQueue()
        {
            front = rear = 0;
        }
        inline int getQueueSpace();
        inline int getUsedSize(){return size - getQueueSpace() - 1;}
        inline int getTotalSize(){return size;}
        inline bool isEmpty(){return (front == rear);} 
        inline byte pop();
        inline bool push(byte data);
        inline int push(byte* buf, int offset, int len);
};



inline int CQueue::getQueueSpace()
{ 
    int c = (rear + 1) % size;
    if (c <= front)
    {
        return -(c - front);
    }
    else
    {
        return size - (c - front);
    }
}

inline byte CQueue::pop()
{
  if (front != rear)
  {
    front = (front + 1) % size;
    return buf[front];
  }
  return -1;
}

inline bool CQueue::push(byte data)
{
  if ((rear + 1) % size != front)
  {
    rear = (rear + 1) % size;
    buf[rear] = data;
    return 1;
  }
  return 0;
}

inline int CQueue::push(byte* buf, int offset, int len)
{
  int remain = len - getQueueSpace();
  if(remain <= 0)
	remain = 0;
  else
	len -= remain;
  for (int i = 0; i < len; i++)
  {
    rear = (rear + 1) % size;
    (this -> buf)[rear] = buf[i + offset];
  }

  return len;
}
#endif
