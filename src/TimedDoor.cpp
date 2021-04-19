// Copyright 2021 by Liza
#include "TimedDoor.h"
#include <iostream>
#include <string>
DoorTimerAdapter::DoorTimerAdapter(TimedDoor& door_) : door(door_) {
this->door = door_;}
void DoorTimerAdapter::Timeout() {
door.DoorTimeOut();}
TimedDoor::TimedDoor(int time_) : opened(false),
adapter(new DoorTimerAdapter(*this)), time(time_) {}
bool TimedDoor::isDoorOpened() {
return opened;}
void TimedDoor::unlock() {
opened = true;
adapter->Timeout();}
void TimedDoor::lock() {
opened = false;}
void TimedDoor::DoorTimeOut() {
throw std::string("close the door!");}
void TimedDoor::throwState() {
if (opened) {
throw std::string("the door is opened!");}
else
{throw std::string("the door is closed!");}}
void Timer::sleep(int Timeout) {
time_t start = time(nullptr);
while (time(nullptr) - start < Timeout) {
continue;}}
void Timer::tregister(int Timeout, TimerClient* tclient) {
this->client = tclient;
sleep(Timeout);
tclient->Timeout();}
