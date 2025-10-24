#ifndef WORKER_H
#define WORKER_H

#include "FabricItem.h"

class Worker : public FabricItem {
private:
    string post;
    int salary;
    string address;
    string phoneNumber;

public:
    Worker();
    Worker(const string& name, const string& post, int salary, 
           const string& address, const string& phoneNumber);
    Worker(const Worker& other);
    
    virtual ~Worker();
    
    virtual void displayInfo() const override;
    virtual FabricItem* clone() const override;
    
    string getPost() const;
    int getSalary() const;
    string getAddress() const;
    string getPhoneNumber() const;
    
    void setPost(const string& post);
    void setSalary(int salary);
    void setAddress(const string& address);
    void setPhoneNumber(const string& phoneNumber);
};

#endif