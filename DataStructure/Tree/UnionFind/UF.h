/*
 * @Author: five-5
 * @Date: 2019-07-09 17:02:26
 * @Description: 
 * @LastEditTime: 2019-07-09 17:04:27
 */

#ifndef UF_H
#define UF_H

class UF {
 public:
    virtual int size() = 0;
    virtual bool isConnected(int p, int q) = 0;     // p,q 表示数组中的序号
    virtual void unionElements(int p, int q) = 0;
};

#endif