#include "Worker.h"

Worker::Worker() 
    : FabricItem(), fio("Unknown"), post("Unknown"), salary(0), 
      address("Unknown"), phoneNumber("Unknown") {
    cout << "Worker default constructor called" << endl;
}

Worker::Worker(const string& name, const string& fio, const string& post, int salary,
               const string& address, const string& phoneNumber)
    : FabricItem(name), fio(fio), post(post), salary(salary),
      address(address), phoneNumber(phoneNumber) {
    cout << "Worker parameterized constructor called for: " << name << endl;
}

Worker::Worker(const Worker& other)
    : FabricItem(other), fio(other.fio), post(other.post), salary(other.salary),
      address(other.address), phoneNumber(other.phoneNumber) {
    cout << "Worker copy constructor called from: " << other.name << endl;
}

Worker::~Worker() {
    cout << "Worker destructor called for: " << name << endl;
}

void Worker::displayInfo() const {
    cout << "Worker Info:" << endl;
    cout << "  Name: " << name << endl;
    cout << "  FIO: " << fio << endl;
    cout << "  Post: " << post << endl;
    cout << "  Salary: " << salary << " rub" << endl;
    cout << "  Address: " << address << endl;
    cout << "  Phone: " << phoneNumber << endl;
}

void Worker::use() const {
    cout << "Worker " << name << " is performing duties: " << post << endl;
}

string Worker::getFio() const { return fio; }
string Worker::getPost() const { return post; }
int Worker::getSalary() const { return salary; }
string Worker::getAddress() const { return address; }
string Worker::getPhoneNumber() const { return phoneNumber; }

void Worker::setFio(const string& fio) { this->fio = fio; }
void Worker::setPost(const string& post) { this->post = post; }
void Worker::setSalary(int salary) { this->salary = salary; }
void Worker::setAddress(const string& address) { this->address = address; }
void Worker::setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }